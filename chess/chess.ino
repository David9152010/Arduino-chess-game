/*
  ======================================================================
  ARDUINO UNO / NANO CHESS — vs AI (Easy/Medium/Hard) — 5 buttons — 10 min clock
  Display: 1.8" ST7735 SPI TFT, 128x160 panel used LANDSCAPE (160x128)
  ======================================================================

  Same chess engine as the portrait version (move generation, castling
  fix, checkmate detection, negamax AI, live AI clock, board-flip for
  Black, sounds) — this file only changes the SCREEN ORIENTATION: the
  panel is used sideways (160 wide x 128 tall) instead of upright. The
  8x8 board is still a full 128x128 square (16px squares) sitting on the
  LEFT, and the leftover 32px-wide strip on the RIGHT is a narrow status
  column (level/color/turn/check/clocks). That strip is intentionally
  tight — 32px only fits ~5 characters per line — so labels are dropped
  in favor of color-coding: the White clock is printed in the same warm
  tan color as the White pieces, the Black clock in the same color as
  the Black pieces, so you can tell them apart at a glance without text
  labels eating into the width.

  HARDWARE / WIRING — identical to the portrait version
  --------------------------------------------------------------------
    TFT LED->5V(or 3.3V)  SCK->D13  SDA(MOSI)->D11  A0/DC->D9
    RESET->D8  CS->D10  GND->GND  VCC->5V
    Buttons: UP->A0 DOWN->A1 LEFT->A2 RIGHT->A3 SELECT->A4 (INPUT_PULLUP)
    Buzzer (+) -> D7, buzzer (-) -> GND (passive piezo)

  LIBRARIES: "Adafruit GFX Library" + "Adafruit ST7735 and ST7789 Library"

  IF ORIENTATION / COLORS LOOK WRONG
  --------------------------------------------------------------------
    INVERT_COLORS   : true/false — fixes inverted colors on these clones.
    SCREEN_ROTATION : 1 or 3 — the two landscape rotations, 180° apart.
                       Set to 1 by default; try 3 if the image comes out
                       mirrored/upside-down for your physical mounting.
  Just change the value and re-upload — nothing else to touch.

  RULES / SIMPLIFICATIONS: identical to the portrait version — see that
  file's header for the full explanation. Castling bugfix (the phantom
  extra-knight issue) is included here too.
  ======================================================================
*/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <avr/pgmspace.h>

// ---------------------------------------------------------------------
// PINS
// ---------------------------------------------------------------------
#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST   8
#define BUZZER_PIN 7

#define INVERT_COLORS  true
#define SCREEN_ROTATION 3   // landscape, rotated 90° to the LEFT

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// Move struct must be defined this early: the Arduino IDE auto-generates
// function prototypes near the top of the file, before any function
// body, and needs this type known before it does that.
#define MAX_MOVES 80
struct Move { uint8_t from; uint8_t to; };

const uint8_t BTN_PINS[5] = {5, 4, 3, A3, A5}; // UP,DOWN,LEFT,RIGHT,SELECT
#define UP_IDX     0
#define DOWN_IDX   1
#define LEFT_IDX   2
#define RIGHT_IDX  3
#define SELECT_IDX 4

bool justPressed[5];
int  lastRaw[5];
unsigned long lastChangeTime[5];
bool stableState[5];

void setupButtons() {
  for (int i = 0; i < 5; i++) {
    pinMode(BTN_PINS[i], INPUT_PULLUP);
    lastRaw[i] = HIGH;
    stableState[i] = HIGH;
    lastChangeTime[i] = 0;
    justPressed[i] = false;
  }
}

void updateButtons() {
  for (int i = 0; i < 5; i++) justPressed[i] = false;
  unsigned long now = millis();
  for (int i = 0; i < 5; i++) {
    int raw = digitalRead(BTN_PINS[i]);
    if (raw != lastRaw[i]) {
      lastChangeTime[i] = now;
      lastRaw[i] = raw;
    }
    if ((now - lastChangeTime[i]) > 25) {
      if (stableState[i] != raw) {
        stableState[i] = raw;
        if (raw == LOW) justPressed[i] = true;
      }
    }
  }
}

// ---------------------------------------------------------------------
// BOARD REPRESENTATION
// ---------------------------------------------------------------------
const uint8_t EMPTY = 0, PAWN = 1, KNIGHT = 2, BISHOP = 3, ROOK = 4, QUEEN = 5, KING = 6;
const uint8_t WHITE = 0x00, BLACK = 0x08;
const uint8_t TYPE_MASK = 0x07, COLOR_MASK = 0x08;

#define CASTLE_WK 0x01
#define CASTLE_WQ 0x02
#define CASTLE_BK 0x04
#define CASTLE_BQ 0x08

uint8_t board[64];
uint8_t castlingRights;

inline uint8_t pieceColor(uint8_t p) { return p & COLOR_MASK; }
inline uint8_t pieceType(uint8_t p)  { return p & TYPE_MASK; }
inline uint8_t opposite(uint8_t c)   { return c ^ COLOR_MASK; }
inline bool isOnBoard(int f, int r)  { return f >= 0 && f < 8 && r >= 0 && r < 8; }

void initBoard() {
  uint8_t backRank[8] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
  for (int f = 0; f < 8; f++) {
    board[0 * 8 + f] = backRank[f] | WHITE;
    board[1 * 8 + f] = PAWN | WHITE;
    board[6 * 8 + f] = PAWN | BLACK;
    board[7 * 8 + f] = backRank[f] | BLACK;
    for (int r = 2; r <= 5; r++) board[r * 8 + f] = EMPTY;
  }
  castlingRights = CASTLE_WK | CASTLE_WQ | CASTLE_BK | CASTLE_BQ;
}

// ---------------------------------------------------------------------
// MOVE GENERATION
// ---------------------------------------------------------------------
const int8_t knightOffsets[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
const int8_t kingOffsets[8][2]   = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int8_t bishopDirs[4][2]    = {{1,1},{1,-1},{-1,1},{-1,-1}};
const int8_t rookDirs[4][2]      = {{1,0},{-1,0},{0,1},{0,-1}};
const int8_t queenDirs[8][2]     = {{1,1},{1,-1},{-1,1},{-1,-1},{1,0},{-1,0},{0,1},{0,-1}};

inline void addMove(Move* arr, int &cnt, uint8_t from, uint8_t to) {
  if (cnt < MAX_MOVES) { arr[cnt].from = from; arr[cnt].to = to; cnt++; }
}

int findKingSquare(uint8_t color) {
  for (int sq = 0; sq < 64; sq++) if (board[sq] == (uint8_t)(KING | color)) return sq;
  return -1;
}

bool isSquareAttacked(int sq, uint8_t byColor) {
  int f = sq % 8, r = sq / 8;
  if (byColor == WHITE) {
    if (isOnBoard(f - 1, r - 1) && board[(r - 1) * 8 + (f - 1)] == (uint8_t)(PAWN | WHITE)) return true;
    if (isOnBoard(f + 1, r - 1) && board[(r - 1) * 8 + (f + 1)] == (uint8_t)(PAWN | WHITE)) return true;
  } else {
    if (isOnBoard(f - 1, r + 1) && board[(r + 1) * 8 + (f - 1)] == (uint8_t)(PAWN | BLACK)) return true;
    if (isOnBoard(f + 1, r + 1) && board[(r + 1) * 8 + (f + 1)] == (uint8_t)(PAWN | BLACK)) return true;
  }
  for (int i = 0; i < 8; i++) {
    int nf = f + knightOffsets[i][0], nr = r + knightOffsets[i][1];
    if (isOnBoard(nf, nr) && board[nr * 8 + nf] == (uint8_t)(KNIGHT | byColor)) return true;
  }
  for (int i = 0; i < 8; i++) {
    int nf = f + kingOffsets[i][0], nr = r + kingOffsets[i][1];
    if (isOnBoard(nf, nr) && board[nr * 8 + nf] == (uint8_t)(KING | byColor)) return true;
  }
  for (int d = 0; d < 4; d++) {
    int nf = f + bishopDirs[d][0], nr = r + bishopDirs[d][1];
    while (isOnBoard(nf, nr)) {
      uint8_t t = board[nr * 8 + nf];
      if (t != EMPTY) {
        if (pieceColor(t) == byColor && (pieceType(t) == BISHOP || pieceType(t) == QUEEN)) return true;
        break;
      }
      nf += bishopDirs[d][0]; nr += bishopDirs[d][1];
    }
  }
  for (int d = 0; d < 4; d++) {
    int nf = f + rookDirs[d][0], nr = r + rookDirs[d][1];
    while (isOnBoard(nf, nr)) {
      uint8_t t = board[nr * 8 + nf];
      if (t != EMPTY) {
        if (pieceColor(t) == byColor && (pieceType(t) == ROOK || pieceType(t) == QUEEN)) return true;
        break;
      }
      nf += rookDirs[d][0]; nr += rookDirs[d][1];
    }
  }
  return false;
}

void genPawnMoves(int f, int r, uint8_t color, Move* moves, int &count) {
  int dir = (color == WHITE) ? 1 : -1;
  int startRank = (color == WHITE) ? 1 : 6;
  int nr = r + dir;
  if (isOnBoard(f, nr) && board[nr * 8 + f] == EMPTY) {
    addMove(moves, count, r * 8 + f, nr * 8 + f);
    if (r == startRank) {
      int nr2 = r + 2 * dir;
      if (board[nr2 * 8 + f] == EMPTY) addMove(moves, count, r * 8 + f, nr2 * 8 + f);
    }
  }
  for (int df = -1; df <= 1; df += 2) {
    int nf = f + df;
    if (isOnBoard(nf, nr)) {
      uint8_t target = board[nr * 8 + nf];
      if (target != EMPTY && pieceColor(target) != color)
        addMove(moves, count, r * 8 + f, nr * 8 + nf);
    }
  }
}

void genKnightMoves(int f, int r, uint8_t color, Move* moves, int &count) {
  for (int i = 0; i < 8; i++) {
    int nf = f + knightOffsets[i][0], nr = r + knightOffsets[i][1];
    if (!isOnBoard(nf, nr)) continue;
    uint8_t target = board[nr * 8 + nf];
    if (target == EMPTY || pieceColor(target) != color) addMove(moves, count, r * 8 + f, nr * 8 + nf);
  }
}

void genSliding(int f, int r, uint8_t color, const int8_t dirs[][2], int ndirs, Move* moves, int &count) {
  for (int d = 0; d < ndirs; d++) {
    int nf = f + dirs[d][0], nr = r + dirs[d][1];
    while (isOnBoard(nf, nr)) {
      uint8_t target = board[nr * 8 + nf];
      if (target == EMPTY) {
        addMove(moves, count, r * 8 + f, nr * 8 + nf);
      } else {
        if (pieceColor(target) != color) addMove(moves, count, r * 8 + f, nr * 8 + nf);
        break;
      }
      nf += dirs[d][0]; nr += dirs[d][1];
    }
  }
}

void genKingMoves(int f, int r, uint8_t color, Move* moves, int &count) {
  for (int i = 0; i < 8; i++) {
    int nf = f + kingOffsets[i][0], nr = r + kingOffsets[i][1];
    if (!isOnBoard(nf, nr)) continue;
    uint8_t target = board[nr * 8 + nf];
    if (target == EMPTY || pieceColor(target) != color) addMove(moves, count, r * 8 + f, nr * 8 + nf);
  }
  uint8_t opp = opposite(color);
  int homeRank = (color == WHITE) ? 0 : 7;
  if (f != 4 || r != homeRank) return;
  if (color == WHITE) {
    if ((castlingRights & CASTLE_WK) && board[5] == EMPTY && board[6] == EMPTY &&
        !isSquareAttacked(4, opp) && !isSquareAttacked(5, opp) && !isSquareAttacked(6, opp))
      addMove(moves, count, 4, 6);
    if ((castlingRights & CASTLE_WQ) && board[3] == EMPTY && board[2] == EMPTY && board[1] == EMPTY &&
        !isSquareAttacked(4, opp) && !isSquareAttacked(3, opp) && !isSquareAttacked(2, opp))
      addMove(moves, count, 4, 2);
  } else {
    if ((castlingRights & CASTLE_BK) && board[61] == EMPTY && board[62] == EMPTY &&
        !isSquareAttacked(60, opp) && !isSquareAttacked(61, opp) && !isSquareAttacked(62, opp))
      addMove(moves, count, 60, 62);
    if ((castlingRights & CASTLE_BQ) && board[59] == EMPTY && board[58] == EMPTY && board[57] == EMPTY &&
        !isSquareAttacked(60, opp) && !isSquareAttacked(59, opp) && !isSquareAttacked(58, opp))
      addMove(moves, count, 60, 58);
  }
}

void generatePseudoMoves(uint8_t color, Move* moves, int &count) {
  count = 0;
  for (int sq = 0; sq < 64; sq++) {
    uint8_t p = board[sq];
    if (p == EMPTY || pieceColor(p) != color) continue;
    int f = sq % 8, r = sq / 8;
    switch (pieceType(p)) {
      case PAWN:   genPawnMoves(f, r, color, moves, count); break;
      case KNIGHT: genKnightMoves(f, r, color, moves, count); break;
      case BISHOP: genSliding(f, r, color, bishopDirs, 4, moves, count); break;
      case ROOK:   genSliding(f, r, color, rookDirs, 4, moves, count); break;
      case QUEEN:  genSliding(f, r, color, queenDirs, 8, moves, count); break;
      case KING:   genKingMoves(f, r, color, moves, count); break;
    }
  }
}

void updateCastlingRights(uint8_t from, uint8_t to, uint8_t col) {
  if (to == 0)  castlingRights &= ~CASTLE_WQ;
  if (to == 7)  castlingRights &= ~CASTLE_WK;
  if (to == 56) castlingRights &= ~CASTLE_BQ;
  if (to == 63) castlingRights &= ~CASTLE_BK;
  switch (from) {
    case 4:  if (col == WHITE) castlingRights &= ~(CASTLE_WK | CASTLE_WQ); break;
    case 60: if (col == BLACK) castlingRights &= ~(CASTLE_BK | CASTLE_BQ); break;
    case 0:  if (col == WHITE) castlingRights &= ~CASTLE_WQ; break;
    case 7:  if (col == WHITE) castlingRights &= ~CASTLE_WK; break;
    case 56: if (col == BLACK) castlingRights &= ~CASTLE_BQ; break;
    case 63: if (col == BLACK) castlingRights &= ~CASTLE_BK; break;
  }
}

void applyMoveToBoard(Move m) {
  uint8_t piece = board[m.from];
  uint8_t col = pieceColor(piece);
  uint8_t type = pieceType(piece);
  board[m.to] = piece;
  board[m.from] = EMPTY;
  // BUGFIX: castling must check m.from == the king's home square too,
  // not just m.to — otherwise a normal one-square king move landing on
  // g1/c1/g8/c8 gets mistaken for castling and duplicates a piece
  // (this was the cause of the phantom extra knight).
  if (type == KING && m.from == 4 && m.to == 6)        { board[5] = board[7];  board[7] = EMPTY; }
  else if (type == KING && m.from == 4 && m.to == 2)   { board[3] = board[0];  board[0] = EMPTY; }
  else if (type == KING && m.from == 60 && m.to == 62) { board[61] = board[63]; board[63] = EMPTY; }
  else if (type == KING && m.from == 60 && m.to == 58) { board[59] = board[56]; board[56] = EMPTY; }
  if (type == PAWN) {
    int destRank = m.to / 8;
    if ((col == WHITE && destRank == 7) || (col == BLACK && destRank == 0))
      board[m.to] = QUEEN | col;
  }
  updateCastlingRights(m.from, m.to, col);
}

void generateLegalMoves(uint8_t color, Move* outMoves, int &outCount) {
  Move pseudo[MAX_MOVES];
  int pc = 0;
  generatePseudoMoves(color, pseudo, pc);
  outCount = 0;
  for (int i = 0; i < pc; i++) {
    uint8_t backup[64];
    uint8_t backupCastle = castlingRights;
    memcpy(backup, board, 64);
    applyMoveToBoard(pseudo[i]);
    bool bad = isSquareAttacked(findKingSquare(color), opposite(color));
    memcpy(board, backup, 64);
    castlingRights = backupCastle;
    if (!bad) addMove(outMoves, outCount, pseudo[i].from, pseudo[i].to);
  }
}

// ---------------------------------------------------------------------
// AI (negamax + alpha-beta)
// ---------------------------------------------------------------------
int16_t evaluate(uint8_t colorToMove) {
  int16_t val = 0;
  for (int sq = 0; sq < 64; sq++) {
    uint8_t p = board[sq];
    if (p == EMPTY) continue;
    uint8_t type = pieceType(p), col = pieceColor(p);
    int pv;
    switch (type) {
      case PAWN: pv = 100; break; case KNIGHT: pv = 320; break;
      case BISHOP: pv = 330; break; case ROOK: pv = 500; break;
      case QUEEN: pv = 900; break; default: pv = 0; break;
    }
    if (type == PAWN) {
      int r = sq / 8;
      pv += (col == WHITE) ? r * 4 : (7 - r) * 4;
      int f = sq % 8;
      if (f >= 3 && f <= 4) pv += 12;
    }
    {
      int cf = sq % 8, cr = sq / 8;
      int cd = abs(cf - 3) + abs(cr - 3);
      int cb = 0;
      if (type == KNIGHT || type == BISHOP) cb = 3 * (7 - cd);
      else if (type == QUEEN)               cb = 2 * (7 - cd);
      else if (type == KING)                cb = (7 - cd) / 2;
      else if (type == PAWN)                cb = (cd <= 1) ? 6 : 0;
      if (cb > 0) pv += cb;
    }
    val += (col == WHITE) ? pv : -pv;
  }
  return (colorToMove == WHITE) ? val : -val;
}

int16_t negamax(uint8_t color, int depth, int16_t alpha, int16_t beta) {
  if (depth == 0) return evaluate(color);
  Move moves[MAX_MOVES];
  int count;
  generateLegalMoves(color, moves, count);
  if (count == 0) {
    if (isSquareAttacked(findKingSquare(color), opposite(color))) return -20000;
    return 0;
  }
  for (int a = 0; a < count - 1; a++)
    for (int b = a + 1; b < count; b++)
      if ((board[moves[b].to] != EMPTY) && (board[moves[a].to] == EMPTY)) {
        Move tmp = moves[a]; moves[a] = moves[b]; moves[b] = tmp;
      }
  int16_t best = -32000;
  for (int i = 0; i < count; i++) {
    uint8_t backup[64];
    uint8_t backupCastle = castlingRights;
    memcpy(backup, board, 64);
    applyMoveToBoard(moves[i]);
    int16_t score = -negamax(opposite(color), depth - 1, (int16_t)(-beta), (int16_t)(-alpha));
    memcpy(board, backup, 64);
    castlingRights = backupCastle;
    if (score > best) best = score;
    if (best > alpha) alpha = best;
    if (alpha >= beta) break;
  }
  return best;
}

bool findBestMove(uint8_t color, int depth, int noise, Move* moves, int count, Move &outMove) {
  if (count == 0) return false;
  int16_t bestScore = -32000;
  int bestIdx = 0;
  for (int i = 0; i < count; i++) {
    uint8_t backup[64];
    uint8_t backupCastle = castlingRights;
    memcpy(backup, board, 64);
    applyMoveToBoard(moves[i]);
    int16_t score = -negamax(opposite(color), depth - 1, (int16_t)-32000, (int16_t)32000);
    memcpy(board, backup, 64);
    castlingRights = backupCastle;
    if (noise > 0) score += (int16_t)random(-noise, noise + 1);
    if (i == 0 || score > bestScore) { bestScore = score; bestIdx = i; }
    tickClock();
    maybeUpdateTimerDisplay();
  }
  outMove = moves[bestIdx];
  return true;
}

// ---------------------------------------------------------------------
// GAME STATE
// ---------------------------------------------------------------------
enum GameState { STATE_MENU, STATE_PLAYING, STATE_GAMEOVER };
GameState state;

uint8_t difficulty;
int aiDepth, aiNoise;
uint8_t humanColor, aiColor, turnColor;
int cursorF, cursorR;
bool pieceSelected;
int selF, selR;
Move cachedMoves[MAX_MOVES];
int cachedCount;
bool inCheckFlag;
unsigned long whiteTimeLeft, blackTimeLeft;
unsigned long lastTickMillis;
int menuIndex;

bool boardFlipped;

// ---------------------------------------------------------------------
// LAYOUT: 160x128 screen, LANDSCAPE. Board is 8x8 squares of 16px
// (=128x128, using the full screen HEIGHT) on the LEFT. The leftover
// 32px-wide column on the RIGHT (x=128..159) is the status strip.
// ---------------------------------------------------------------------
#define SQUARE_SIZE 16
#define BOARD_PX (SQUARE_SIZE * 8)   // 128
#define SIDEBAR_X BOARD_PX           // 128 — status column starts here
#define SIDEBAR_W (160 - BOARD_PX)   // 32  — narrow, so text is unlabeled/color-coded

inline int scrX(int f) { return boardFlipped ? (7 - f) * SQUARE_SIZE : f * SQUARE_SIZE; }
inline int scrY(int r) { return boardFlipped ? r * SQUARE_SIZE : (7 - r) * SQUARE_SIZE; }

uint16_t COLOR_BG, COLOR_BOARD_LIGHT, COLOR_BOARD_DARK;
uint16_t COLOR_WHITE_BODY, COLOR_BLACK_BODY, COLOR_BLACK_TEXT;

// ---------------------------------------------------------------------
// PIECE SPRITES — 16x16, 1 bit per pixel (32 bytes each, PROGMEM).
// Bit 1 = draw the piece's body color; bit 0 = transparent (square
// color shows through). Hand-drawn and rendered/verified pixel-by-pixel
// before encoding.
// ---------------------------------------------------------------------
const uint8_t kingSprite[32] PROGMEM = {
  0x01, 0x80, 0x01, 0x80, 0x07, 0xE0, 0x01, 0x80, 0x01, 0x80, 0x07, 0xE0,
  0x07, 0xE0, 0x03, 0xE0, 0x0F, 0xF0, 0x0F, 0xF0, 0x07, 0xE0, 0x07, 0xE0,
  0x0F, 0xF0, 0x1F, 0xF8, 0x1F, 0xF8, 0x1F, 0xF8,
};

const uint8_t queenSprite[32] PROGMEM = {
  0x00, 0x00, 0x05, 0x80, 0x14, 0xAC, 0x15, 0xA8, 0x3D, 0xBC, 0x1F, 0xF8,
  0x1F, 0xF8, 0x0F, 0xF0, 0x0F, 0xF0, 0x0F, 0xF0, 0x0F, 0xF0, 0x0F, 0xF0,
  0x1F, 0xF8, 0x1F, 0xF8, 0x1F, 0xF8, 0x00, 0x00,
};

const uint8_t rookSprite[32] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x0D, 0xB0, 0x0D, 0xB0, 0x0F, 0xF0, 0x0F, 0xF0,
  0x07, 0xE0, 0x07, 0xE0, 0x07, 0xE0, 0x07, 0xE0, 0x03, 0xC0, 0x0F, 0xF0,
  0x0F, 0xF0, 0x1F, 0xF8, 0x1F, 0xF8, 0x00, 0x00,
};

const uint8_t bishopSprite[32] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x01, 0x80, 0x00, 0x00, 0x00, 0x80,
  0x01, 0xC0, 0x03, 0xC0, 0x07, 0xE0, 0x07, 0xE0, 0x07, 0xE0, 0x03, 0xC0,
  0x0F, 0xF8, 0x1F, 0xF8, 0x1F, 0xFC, 0x1F, 0xFC,
};

const uint8_t knightSprite[32] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x01, 0xE0, 0x03, 0xF8, 0x03, 0xFC,
  0x07, 0xF6, 0x07, 0xE0, 0x07, 0xC0, 0x07, 0xC0, 0x07, 0xC0, 0x07, 0xC0,
  0x07, 0xC0, 0x07, 0xC0, 0x0F, 0xFC, 0x0F, 0xFC,
};

const uint8_t pawnSprite[32] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x03, 0xC0, 0x03, 0xC0, 0x01, 0x80,
  0x01, 0xC0, 0x03, 0xC0, 0x03, 0xC0, 0x03, 0xC0, 0x07, 0xE0, 0x0F, 0xF0,
  0x0F, 0xF0, 0x1F, 0xF8, 0x1F, 0xF8, 0x00, 0x00,
};

void drawChessSprite(int x0, int y0, const uint8_t* sprite, uint16_t color) {
  tft.startWrite();
  for (uint8_t yy = 0; yy < SQUARE_SIZE; yy++) {
    for (uint8_t xx = 0; xx < SQUARE_SIZE; xx++) {
      uint16_t bitIndex = (uint16_t)yy * SQUARE_SIZE + xx;
      uint8_t byteVal = pgm_read_byte(&sprite[bitIndex >> 3]);
      uint8_t bit = 7 - (bitIndex & 7);
      if ((byteVal >> bit) & 1) tft.writePixel(x0 + xx, y0 + yy, color);
    }
  }
  tft.endWrite();
}

// ---------------------------------------------------------------------
// DISPLAY — board
// ---------------------------------------------------------------------
void drawSquareBorder(int f, int r, uint16_t color) {
  int x = scrX(f), y = scrY(r);
  tft.drawRect(x, y, SQUARE_SIZE, SQUARE_SIZE, color);
}

bool cursorVisible() {
  return state == STATE_PLAYING && turnColor == humanColor;
}

void drawCursorBrackets(int f, int r) {
  int x = scrX(f), y = scrY(r);
  uint16_t c = ST77XX_GREEN;
  const int arm = 5, th = 2;
  tft.fillRect(x, y, arm, th, c);
  tft.fillRect(x, y, th, arm, c);
  tft.fillRect(x + SQUARE_SIZE - arm, y, arm, th, c);
  tft.fillRect(x + SQUARE_SIZE - th, y, th, arm, c);
  tft.fillRect(x, y + SQUARE_SIZE - th, arm, th, c);
  tft.fillRect(x, y + SQUARE_SIZE - arm, th, arm, c);
  tft.fillRect(x + SQUARE_SIZE - arm, y + SQUARE_SIZE - th, arm, th, c);
  tft.fillRect(x + SQUARE_SIZE - th, y + SQUARE_SIZE - arm, th, arm, c);
}

void drawPieceAt(int f, int r, uint8_t p) {
  if (p == EMPTY) return;
  uint8_t col = pieceColor(p);
  uint8_t type = pieceType(p);
  uint16_t body = (col == WHITE) ? COLOR_WHITE_BODY : COLOR_BLACK_BODY;
  const uint8_t* sprite;
  switch (type) {
    case PAWN:   sprite = pawnSprite;   break;
    case KNIGHT: sprite = knightSprite; break;
    case BISHOP: sprite = bishopSprite; break;
    case ROOK:   sprite = rookSprite;   break;
    case QUEEN:  sprite = queenSprite;  break;
    case KING:   sprite = kingSprite;   break;
    default: return;
  }
  drawChessSprite(scrX(f), scrY(r), sprite, body);
}

void redrawCell(int f, int r) {
  int x = scrX(f), y = scrY(r);
  uint16_t sqColor = ((f + r) % 2 == 0) ? COLOR_BOARD_DARK : COLOR_BOARD_LIGHT;
  tft.fillRect(x, y, SQUARE_SIZE, SQUARE_SIZE, sqColor);
  drawPieceAt(f, r, board[r * 8 + f]);
  if (pieceSelected && f == selF && r == selR) drawSquareBorder(f, r, ST77XX_RED);
  if (cursorVisible() && f == cursorF && r == cursorR) drawCursorBrackets(f, r);
}

void redrawBoardFull() {
  for (int r = 0; r < 8; r++)
    for (int f = 0; f < 8; f++)
      redrawCell(f, r);
}

void moveCursorTo(int newF, int newR) {
  int oldF = cursorF, oldR = cursorR;
  cursorF = newF; cursorR = newR;
  redrawCell(oldF, oldR);
  redrawCell(newF, newR);
}

void printTime(unsigned long ms, int x, int y) {
  unsigned long s = ms / 1000;
  unsigned int mm = s / 60, ss = s % 60;
  char buf[6];
  buf[0] = '0' + (mm / 10); buf[1] = '0' + (mm % 10); buf[2] = ':';
  buf[3] = '0' + (ss / 10); buf[4] = '0' + (ss % 10); buf[5] = 0;
  tft.setCursor(x, y);
  tft.print(buf);
}

// ---------------------------------------------------------------------
// DISPLAY — narrow (32px) status column at x=128..159, full height.
// No text labels (no room) — info is color-coded and stacked vertically:
//   y=2  : difficulty (yellow)         y=42 : turn color (white text)
//   y=12 : your color (green)          y=52 : "CHK!" if in check (red)
//   y=70 : White's clock (tan, matches White piece color)
//   y=82 : Black's clock (light gray, matches Black piece color)
//   y=100: short AI-thinking indicator (cyan)
// ---------------------------------------------------------------------
void drawSidebarHeader() {
  tft.fillRect(SIDEBAR_X, 0, SIDEBAR_W, 24, COLOR_BG);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(SIDEBAR_X + 1, 2);
  tft.print(difficulty == 0 ? "EASY" : (difficulty == 1 ? "MED" : "HARD"));
  tft.setTextColor(ST77XX_GREEN);
  tft.setCursor(SIDEBAR_X + 1, 12);
  tft.print(humanColor == WHITE ? "WHITE" : "BLACK");
}

void drawTurnStatus() {
  tft.fillRect(SIDEBAR_X, 40, SIDEBAR_W, 20, COLOR_BG);
  tft.setTextSize(1); tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(SIDEBAR_X + 1, 42);
  tft.print(turnColor == WHITE ? "WHITE" : "BLACK");
  if (inCheckFlag) {
    tft.setTextColor(ST77XX_RED);
    tft.setCursor(SIDEBAR_X + 1, 52);
    tft.print("CHK!");
  }
}

void drawStatusMessage(const char* msg) {
  tft.fillRect(SIDEBAR_X, 98, SIDEBAR_W, 8, COLOR_BG);
  tft.setTextSize(1); tft.setTextColor(ST77XX_CYAN);
  tft.setCursor(SIDEBAR_X + 1, 98); tft.print(msg);
}

void drawTimers() {
  tft.fillRect(SIDEBAR_X, 68, SIDEBAR_W, 24, COLOR_BG);
  tft.setTextSize(1);
  tft.setTextColor(COLOR_WHITE_BODY);
  printTime(whiteTimeLeft, SIDEBAR_X + 1, 70);
  tft.setTextColor(COLOR_BLACK_TEXT);
  printTime(blackTimeLeft, SIDEBAR_X + 1, 82);
}

void maybeUpdateTimerDisplay() {
  static unsigned long lastDraw = 0;
  unsigned long now = millis();
  if (now - lastDraw >= 500) { drawTimers(); lastDraw = now; }
}

// ---- Difficulty menu: uses the FULL 160x128 screen (this part isn't
// cramped — only the in-game status column is), full draw once, then
// only the 3 option lines repaint on UP/DOWN. ----
void drawMenuOptions() {
  const char* labels[3] = {"EASY", "MEDIUM", "HARD"};
  for (int i = 0; i < 3; i++) {
    int y = 34 + i * 26;
    tft.fillRect(0, y, 160, 18, COLOR_BG);
    tft.setTextSize(2);
    tft.setTextColor(i == menuIndex ? ST77XX_YELLOW : ST77XX_WHITE);
    tft.setCursor(20, y);
    tft.print(i == menuIndex ? "> " : "  ");
    tft.print(labels[i]);
  }
}

void showDifficultyMenu() {
  tft.fillScreen(COLOR_BG);
  tft.setTextSize(1); tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(6, 4); tft.print("CHESS - UNO/NANO");
  tft.setCursor(6, 114); tft.setTextColor(ST77XX_WHITE);
  tft.print("UP/DOWN choose, SEL ok");
  drawMenuOptions();
}

void showColorAssignedMessage() {
  tft.fillScreen(COLOR_BG);
  tft.setTextSize(2); tft.setTextColor(ST77XX_GREEN);
  tft.setCursor(20, 40); tft.print("You are");
  tft.setCursor(20, 65); tft.print(humanColor == WHITE ? "WHITE" : "BLACK");
}

void showGameOverTwoLines(const char* line1, const char* line2) {
  tft.fillScreen(COLOR_BG);
  tft.setTextSize(2); tft.setTextColor(ST77XX_RED);
  tft.setCursor(10, 28); tft.print(line1);
  tft.setCursor(10, 53); tft.print(line2);
  tft.setTextSize(1); tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 100); tft.print("Press SELECT for menu");
}

// ---------------------------------------------------------------------
// SOUND (passive piezo on BUZZER_PIN). tone() is non-blocking.
// ---------------------------------------------------------------------
void soundMove() {
  tone(BUZZER_PIN, 880, 45);
}

void soundCapture() {
  tone(BUZZER_PIN, 520, 70);
}

void soundCheck() {
  tone(BUZZER_PIN, 1500, 80);
  delay(110);
  tone(BUZZER_PIN, 1500, 80);
}

void soundGameStart() {
  tone(BUZZER_PIN, 660, 90);  delay(100);
  tone(BUZZER_PIN, 880, 90);  delay(100);
  tone(BUZZER_PIN, 1320, 150);
}

void soundGameOver() {
  tone(BUZZER_PIN, 500, 160);
  delay(170);
  tone(BUZZER_PIN, 330, 240);
}

// ---------------------------------------------------------------------
// GAME FLOW
// ---------------------------------------------------------------------
void tickClock() {
  unsigned long now = millis();
  unsigned long elapsed = now - lastTickMillis;
  lastTickMillis = now;
  if (elapsed == 0) return;
  if (turnColor == WHITE) whiteTimeLeft = (elapsed >= whiteTimeLeft) ? 0 : whiteTimeLeft - elapsed;
  else                    blackTimeLeft = (elapsed >= blackTimeLeft) ? 0 : blackTimeLeft - elapsed;
}

void endGameByTime(uint8_t winner) {
  state = STATE_GAMEOVER;
  showGameOverTwoLines("TIME OUT", winner == WHITE ? "WHITE WINS" : "BLACK WINS");
}

void redrawAfterMove(Move m) {
  int fFrom = m.from % 8, rFrom = m.from / 8;
  int fTo   = m.to % 8,   rTo   = m.to / 8;
  redrawCell(fFrom, rFrom);
  redrawCell(fTo, rTo);

  uint8_t movedPiece = board[m.to];
  if (pieceType(movedPiece) == KING && (m.from == 4 || m.from == 60) && abs(fTo - fFrom) == 2) {
    if (m.to == 6)       { redrawCell(5, 0); redrawCell(7, 0); }
    else if (m.to == 2)  { redrawCell(3, 0); redrawCell(0, 0); }
    else if (m.to == 62) { redrawCell(5, 7); redrawCell(7, 7); }
    else if (m.to == 58) { redrawCell(3, 7); redrawCell(0, 7); }
  }
  redrawCell(cursorF, cursorR);
}

void afterMoveUpdate(uint8_t moverColor, Move m, bool wasCapture) {
  uint8_t nextColor = opposite(moverColor);
  generateLegalMoves(nextColor, cachedMoves, cachedCount);
  bool nextInCheck = isSquareAttacked(findKingSquare(nextColor), moverColor);
  if (cachedCount == 0) {
    state = STATE_GAMEOVER;
    if (nextInCheck) showGameOverTwoLines("CHECKMATE", moverColor == WHITE ? "WHITE WINS" : "BLACK WINS");
    else showGameOverTwoLines("STALEMATE", "DRAW");
    soundGameOver();
  } else {
    turnColor = nextColor;
    inCheckFlag = nextInCheck;
    drawTurnStatus();
    redrawAfterMove(m);
    if (nextInCheck) soundCheck();
    else if (wasCapture) soundCapture();
    else soundMove();
  }
}

void doAIMove() {
  drawStatusMessage("AI");
  Move mv;
  bool ok = findBestMove(aiColor, aiDepth, aiNoise, cachedMoves, cachedCount, mv);
  bool wasCapture = ok && (board[mv.to] != EMPTY);
  if (ok) applyMoveToBoard(mv);
  tickClock();
  drawStatusMessage("");
  if (ok) afterMoveUpdate(aiColor, mv, wasCapture);
}

void handleSelect() {
  int sq = cursorR * 8 + cursorF;
  uint8_t p = board[sq];
  if (!pieceSelected) {
    if (p != EMPTY && pieceColor(p) == humanColor) {
      pieceSelected = true; selF = cursorF; selR = cursorR;
      redrawCell(selF, selR);
    }
  } else {
    if (cursorF == selF && cursorR == selR) {
      pieceSelected = false;
      redrawCell(selF, selR);
    } else if (p != EMPTY && pieceColor(p) == humanColor) {
      int oldF = selF, oldR = selR;
      selF = cursorF; selR = cursorR;
      redrawCell(oldF, oldR);
      redrawCell(selF, selR);
    } else {
      int from = selR * 8 + selF, to = sq;
      bool legal = false;
      for (int i = 0; i < cachedCount; i++) {
        if (cachedMoves[i].from == from && cachedMoves[i].to == to) { legal = true; break; }
      }
      if (legal) {
        Move m; m.from = (uint8_t)from; m.to = (uint8_t)to;
        bool wasCapture = (board[to] != EMPTY);
        applyMoveToBoard(m);
        pieceSelected = false;
        tickClock();
        afterMoveUpdate(humanColor, m, wasCapture);
      }
    }
  }
}

void handleHumanInput() {
  if (justPressed[UP_IDX])    moveCursorTo(cursorF, boardFlipped ? max(cursorR - 1, 0) : min(cursorR + 1, 7));
  if (justPressed[DOWN_IDX])  moveCursorTo(cursorF, boardFlipped ? min(cursorR + 1, 7) : max(cursorR - 1, 0));
  if (justPressed[LEFT_IDX])  moveCursorTo(boardFlipped ? min(cursorF + 1, 7) : max(cursorF - 1, 0), cursorR);
  if (justPressed[RIGHT_IDX]) moveCursorTo(boardFlipped ? max(cursorF - 1, 0) : min(cursorF + 1, 7), cursorR);
  if (justPressed[SELECT_IDX]) handleSelect();
}

void handleMenuInput() {
  if (justPressed[UP_IDX])   { menuIndex = (menuIndex + 2) % 3; drawMenuOptions(); }
  if (justPressed[DOWN_IDX]) { menuIndex = (menuIndex + 1) % 3; drawMenuOptions(); }
  if (justPressed[SELECT_IDX]) {
    difficulty = menuIndex;
    switch (difficulty) {
      case 0: aiDepth = 1; aiNoise = 150; break;
      case 1: aiDepth = 2; aiNoise = 30;  break;
      case 2: aiDepth = 3; aiNoise = 0;   break;
    }
    humanColor = (random(0, 2) == 0) ? WHITE : BLACK;
    aiColor = opposite(humanColor);
    boardFlipped = (humanColor == BLACK);
    showColorAssignedMessage();
    delay(1500);
    startNewGame();
  }
}

void handleGameOverInput() {
  if (justPressed[SELECT_IDX]) {
    state = STATE_MENU; menuIndex = 0;
    showDifficultyMenu();
  }
}

void startNewGame() {
  initBoard();
  whiteTimeLeft = blackTimeLeft = 10UL * 60UL * 1000UL;
  lastTickMillis = millis();
  cursorF = 4; cursorR = 1;
  pieceSelected = false;
  turnColor = WHITE;
  generateLegalMoves(WHITE, cachedMoves, cachedCount);
  inCheckFlag = false;
  state = STATE_PLAYING;
  tft.fillScreen(COLOR_BG);
  redrawBoardFull();
  drawSidebarHeader();
  drawTurnStatus();
  drawTimers();
  soundGameStart();
  if (turnColor == aiColor) doAIMove();
}

// ---------------------------------------------------------------------
// SETUP / LOOP
// ---------------------------------------------------------------------
void setup() {
  tft.initR(INITR_BLACKTAB);       // try INITR_GREENTAB if geometry looks off
  tft.setRotation(SCREEN_ROTATION);
  tft.invertDisplay(INVERT_COLORS);

  COLOR_BG = ST77XX_BLACK;
  COLOR_BOARD_LIGHT = tft.color565(150, 165, 185);
  COLOR_BOARD_DARK  = tft.color565(45, 55, 75);
  COLOR_WHITE_BODY  = tft.color565(240, 200, 130);
  COLOR_BLACK_BODY  = tft.color565(80, 84, 92);
  COLOR_BLACK_TEXT  = tft.color565(170, 174, 182); // brighter than the piece body, for legible clock text
  tft.fillScreen(COLOR_BG);

  setupButtons();
  randomSeed(analogRead(A5));
  pinMode(BUZZER_PIN, OUTPUT);

  boardFlipped = false;
  state = STATE_MENU;
  menuIndex = 0;
  showDifficultyMenu();
}

void loop() {
  updateButtons();
  switch (state) {
    case STATE_MENU:
      handleMenuInput();
      break;
    case STATE_PLAYING:
      tickClock();
      if (whiteTimeLeft == 0) { endGameByTime(BLACK); break; }
      if (blackTimeLeft == 0) { endGameByTime(WHITE); break; }
      maybeUpdateTimerDisplay();
      if (turnColor == humanColor) handleHumanInput();
      else doAIMove();
      break;
    case STATE_GAMEOVER:
      handleGameOverInput();
      break;
  }
}
