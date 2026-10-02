<!DOCTYPE html>
<html lang="en" data-theme="dark">
<head>
<meta name="referrer" content="origin">
<meta name="referrer" content="strict-origin-when-cross-origin">
<meta name="msvalidate.01" content="635904AB736B01C091C2FDF7E5B38444" />
<meta charset="UTF-8" />
<meta name="viewport" content="width=device-width, initial-scale=1" />
<title>More Projects — David Tech Lab</title>
<link rel="preconnect" href="https://fonts.googleapis.com" />
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
<link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;600;700;800;900&family=JetBrains+Mono:wght@400;700&family=Orbitron:wght@400;700;900&display=swap" rel="stylesheet" />
<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet" />
<meta name="title" content="David Tech Lab – DIY Electronics & Microcontroller Projects" />
<meta name="description" content="Explore creative electronics projects using Arduino, ESP32, MicroPython, sensors, LCDs, dot matrix displays, and more." />
<meta name="keywords" content="Arduino projects, ESP32, MicroPython, electronics tutorials" />
<meta name="author" content="David Medhat" />
<meta name="robots" content="index, follow" />
<meta property="og:type" content="website" />
<meta property="og:url" content="https://davidtechlab.blogspot.com/" />
<meta property="og:title" content="David Tech Lab – DIY Electronics & Microcontroller Projects" />
<meta name="twitter:card" content="summary_large_image" />
<meta name="twitter:title" content="David Tech Lab – DIY Electronics & Microcontroller Projects" />
<style>
:root {
  --primary: #00e5ff;
  --primary-dim: #0099b0;
  --secondary: #7c3aed;
  --secondary-dim: #5b21b6;
  --accent: #10b981;
  --accent-dim: #059669;
  --bg: #0a0e1a;
  --bg-alt: #111827;
  --bg-card: #1a2332;
  --bg-glass: rgba(26, 35, 50, 0.7);
  --border: rgba(0, 229, 255, 0.15);
  --border-glow: rgba(0, 229, 255, 0.4);
  --text: #e2e8f0;
  --text-dim: #94a3b8;
  --text-muted: #64748b;
  --shadow: 0 8px 32px rgba(0,0,0,0.4);
  --radius: 16px;
  --radius-sm: 8px;
  --transition: 0.4s cubic-bezier(0.25, 0.46, 0.45, 0.94);
  --font-display: 'Orbitron', monospace;
  --font-body: 'Inter', sans-serif;
  --font-mono: 'JetBrains Mono', monospace;
  --glow-primary: 0 0 20px rgba(0,229,255,0.15), 0 0 40px rgba(0,229,255,0.05);
  --glow-secondary: 0 0 20px rgba(124,58,237,0.15), 0 0 40px rgba(124,58,237,0.05);
}
[data-theme="light"] {
  --primary: #0284c7;
  --primary-dim: #0369a1;
  --secondary: #7c3aed;
  --secondary-dim: #6d28d9;
  --accent: #059669;
  --accent-dim: #047857;
  --bg: #f0f4ff;
  --bg-alt: #e2e8f0;
  --bg-card: #ffffff;
  --bg-glass: rgba(255, 255, 255, 0.8);
  --border: rgba(2, 132, 199, 0.15);
  --border-glow: rgba(2, 132, 199, 0.3);
  --text: #0f172a;
  --text-dim: #334155;
  --text-muted: #64748b;
  --shadow: 0 8px 32px rgba(0,0,0,0.1);
  --glow-primary: 0 0 20px rgba(2,132,199,0.1), 0 0 40px rgba(2,132,199,0.03);
  --glow-secondary: 0 0 20px rgba(124,58,237,0.1), 0 0 40px rgba(124,58,237,0.03);
}
*, *::before, *::after { box-sizing: border-box; margin: 0; padding: 0; }
html { scroll-behavior: smooth; font-size: 16px; }
body {
  font-family: var(--font-body);
  background: var(--bg);
  color: var(--text);
  line-height: 1.6;
  overflow-x: hidden;
  padding: 0;
  transition: background var(--transition), color var(--transition);
}
body::before {
  content: '';
  position: fixed;
  inset: 0;
  background:
    radial-gradient(ellipse at 20% 50%, rgba(0,229,255,0.04) 0%, transparent 50%),
    radial-gradient(ellipse at 80% 50%, rgba(124,58,237,0.04) 0%, transparent 50%);
  pointer-events: none;
  z-index: 0;
}
a { color: var(--primary); text-decoration: none; transition: color var(--transition); }
img { max-width: 100%; display: block; }
::selection { background: var(--primary); color: #000; }
::-webkit-scrollbar { width: 6px; }
::-webkit-scrollbar-track { background: var(--bg); }
::-webkit-scrollbar-thumb { background: var(--primary-dim); border-radius: 3px; }
::-webkit-scrollbar-thumb:hover { background: var(--primary); }

.theme-toggle {
  position: fixed;
  bottom: 30px;
  left: 30px;
  z-index: 9999;
  width: 48px;
  height: 48px;
  border-radius: 50%;
  border: 2px solid var(--border);
  background: var(--bg-glass);
  backdrop-filter: blur(12px);
  color: var(--text);
  cursor: pointer;
  display: flex;
  align-items: center;
  justify-content: center;
  font-size: 1.25rem;
  transition: all var(--transition);
  box-shadow: var(--shadow);
}
.theme-toggle:hover {
  border-color: var(--primary);
  box-shadow: var(--glow-primary);
  transform: scale(1.1) rotate(15deg);
}

header {
  position: sticky;
  top: 0;
  z-index: 100;
  background: var(--bg-glass);
  backdrop-filter: blur(20px) saturate(180%);
  border-bottom: 1px solid var(--border);
  padding: 16px 24px;
  display: flex;
  justify-content: space-between;
  align-items: center;
}
.logo {
  font-family: var(--font-display);
  font-size: 1.2rem;
  font-weight: 900;
  background: linear-gradient(135deg, var(--primary), var(--secondary));
  -webkit-background-clip: text;
  -webkit-text-fill-color: transparent;
  background-clip: text;
  letter-spacing: 2px;
  text-transform: uppercase;
}
.search-bar {
  padding: 10px 20px;
  border-radius: 100px;
  border: 1px solid var(--border);
  background: var(--bg);
  color: var(--text);
  font-family: var(--font-body);
  font-size: 0.85rem;
  width: 250px;
  outline: none;
  transition: all var(--transition);
}
.search-bar:focus {
  border-color: var(--primary);
  box-shadow: 0 0 0 3px rgba(0,229,255,0.1);
}
.search-bar::placeholder { color: var(--text-muted); }

main {
  position: relative;
  z-index: 1;
  padding: 32px 24px;
  max-width: 1200px;
  margin: 0 auto;
}

.page-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 32px;
  flex-wrap: wrap;
  gap: 16px;
}
.page-header h1 {
  font-family: var(--font-display);
  font-size: 1.8rem;
  letter-spacing: 2px;
}
.page-header .subtitle {
  color: var(--text-dim);
  font-size: 0.9rem;
}

.button-section {
  display: flex;
  gap: 12px;
  flex-wrap: wrap;
  margin-bottom: 40px;
}
.button-link {
  display: inline-flex;
  align-items: center;
  gap: 8px;
  padding: 10px 24px;
  border-radius: var(--radius-sm);
  font-size: 0.85rem;
  font-weight: 600;
  cursor: pointer;
  transition: all var(--transition);
  border: 1px solid var(--border);
  background: var(--bg-glass);
  color: var(--text);
  font-family: var(--font-body);
  letter-spacing: 0.5px;
}
.button-link:hover {
  border-color: var(--primary);
  box-shadow: var(--glow-primary);
  transform: translateY(-2px);
}
.button-link.active {
  border-color: var(--primary);
  background: var(--primary);
  color: #000;
}

.cards-grid {
  display: grid;
  grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
  gap: 24px;
}
.project-card {
  position: relative;
  background: var(--bg-card);
  border-radius: var(--radius);
  border: 1px solid var(--border);
  overflow: hidden;
  cursor: pointer;
  transition: all var(--transition);
  display: flex;
  flex-direction: column;
}
.project-card:hover {
  transform: translateY(-10px) scale(1.01);
  border-color: var(--primary);
  box-shadow: var(--glow-primary), var(--shadow);
}
.project-card .image-wrap {
  position: relative;
  height: 180px;
  overflow: hidden;
}
.project-card .image-wrap img {
  width: 100%;
  height: 100%;
  object-fit: cover;
  transition: transform 0.6s ease;
}
.project-card:hover .image-wrap img { transform: scale(1.1); }
.project-card .image-wrap::after {
  content: '';
  position: absolute;
  inset: 0;
  background: linear-gradient(to top, var(--bg-card) 0%, transparent 50%);
}
.project-card .overlay {
  position: absolute;
  inset: 0;
  background: linear-gradient(135deg, rgba(0,229,255,0.1), rgba(124,58,237,0.1));
  opacity: 0;
  transition: opacity var(--transition);
  display: flex;
  align-items: center;
  justify-content: center;
}
.project-card:hover .overlay { opacity: 1; }
.project-card .overlay span {
  padding: 8px 20px;
  border-radius: var(--radius-sm);
  background: var(--bg-glass);
  backdrop-filter: blur(12px);
  color: white;
  font-weight: 600;
  font-size: 0.85rem;
  border: 1px solid var(--border);
  transform: translateY(20px);
  transition: transform var(--transition);
}
.project-card:hover .overlay span { transform: translateY(0); }
.project-card .content {
  padding: 20px 24px 24px;
  flex-grow: 1;
  display: flex;
  flex-direction: column;
}
.project-card .content .title {
  font-size: 1.05rem;
  font-weight: 700;
  margin-bottom: 12px;
  flex-grow: 1;
}
.project-card .content .tech {
  font-family: var(--font-mono);
  font-size: 0.7rem;
  color: var(--primary);
  letter-spacing: 1px;
  margin-bottom: 4px;
}
.project-card .content .btn {
  align-self: flex-start;
  display: inline-flex;
  align-items: center;
  gap: 6px;
  padding: 8px 20px;
  border-radius: var(--radius-sm);
  font-weight: 600;
  font-size: 0.8rem;
  cursor: pointer;
  border: 1px solid var(--border);
  background: transparent;
  color: var(--text);
  transition: all var(--transition);
  font-family: var(--font-body);
}
.project-card .content .btn:hover {
  border-color: var(--primary);
  color: var(--primary);
  box-shadow: var(--glow-primary);
}

/* Project overlays */
.project-page {
  display: none;
  position: fixed;
  inset: 0;
  overflow-y: auto;
  background: var(--bg);
  z-index: 9999;
  padding: 0;
}
.project-page .container { max-width: 1000px; margin: 0 auto; padding: 100px 20px 40px; }
.project-badge {
  background: var(--bg-card);
  border-radius: var(--radius);
  border: 1px solid var(--border);
  overflow: hidden;
  box-shadow: var(--shadow);
  margin-bottom: 40px;
}
.badge-header {
  display: flex;
  align-items: center;
  padding: 20px 24px;
  background: var(--bg-alt);
  border-bottom: 1px solid var(--border);
  position: sticky;
  top: 0;
  z-index: 10;
}
.badge-header .project-title {
  font-family: var(--font-display);
  font-size: 1.4rem;
  margin: 0;
  flex-grow: 1;
  letter-spacing: 1px;
}
.home-link {
  display: inline-flex;
  align-items: center;
  gap: 8px;
  color: var(--text-dim);
  text-decoration: none;
  margin-right: 20px;
  transition: all var(--transition);
  font-size: 0.85rem;
  padding: 8px 16px;
  border-radius: var(--radius-sm);
  border: 1px solid transparent;
}
.home-link:hover { color: var(--primary); border-color: var(--border); background: var(--bg-glass); }
.badge-section { padding: 24px; border-bottom: 1px solid var(--border); }
.badge-section:last-child { border-bottom: none; }
.badge-section .section-title {
  font-family: var(--font-display);
  font-size: 1.1rem;
  color: var(--primary);
  margin: 0 0 20px;
  display: flex;
  align-items: center;
  gap: 10px;
  font-weight: 700;
}
.badge-section .section-title .material-icons { font-size: 1.2em; }
.project-image-container { text-align: center; margin-bottom: 20px; }
.project-main-image { max-width: 100%; border-radius: var(--radius-sm); box-shadow: var(--shadow); }
.components-grid { display: flex; flex-direction: column; gap: 12px; }
.component-card {
  background: var(--bg-alt);
  padding: 12px 16px;
  border-radius: var(--radius-sm);
  display: flex;
  align-items: center;
  gap: 20px;
  transition: all var(--transition);
  max-width: 500px;
  border: 1px solid transparent;
}
.badge-section ul,
.badge-section ol {
  padding-left: 28px;
  margin: 8px 0;
}
.component-card:hover { border-color: var(--border); transform: translateX(5px); }
.component-image {
  width: 60px;
  height: 60px;
  object-fit: contain;
  flex-shrink: 0;
  padding: 8px;
  border-radius: var(--radius-sm);
  background: var(--bg-card);
}
.component-info h2 { font-size: 1rem; margin: 0 0 2px; }
.component-info p { color: var(--text-dim); margin: 0; font-size: 0.8rem; }
.connection-diagram { text-align: center; margin: 20px 0; }
.connection-image { max-width: 100%; border-radius: var(--radius-sm); box-shadow: var(--shadow); }
.connection-steps { margin-top: 16px; display: grid; gap: 8px; }
.connection-step {
  display: flex;
  align-items: center;
  gap: 12px;
  font-family: var(--font-mono);
  font-size: 0.85rem;
}
.connection-pin {
  background: var(--primary-dim);
  color: #000;
  padding: 4px 12px;
  border-radius: 4px;
  font-weight: 600;
  min-width: 80px;
  text-align: center;
  font-size: 0.75rem;
}
.code-block-container {
  position: relative;
  background: #0a1220;
  border-radius: var(--radius-sm);
  padding: 16px;
  margin-bottom: 16px;
  border: 1px solid var(--border);
}
.code-block {
  font-family: var(--font-mono);
  font-size: 0.8rem;
  overflow-x: auto;
  max-height: 400px;
}
.code-block pre { margin: 0; white-space: pre-wrap; }
.copy-button {
  position: absolute;
  top: 8px;
  right: 8px;
  background: var(--bg-alt);
  color: var(--text);
  border: 1px solid var(--border);
  padding: 6px 12px;
  border-radius: 4px;
  cursor: pointer;
  font-size: 0.75rem;
  display: flex;
  align-items: center;
  gap: 4px;
  transition: all var(--transition);
  font-family: var(--font-body);
}
.copy-button:hover { border-color: var(--primary); color: var(--primary); }
.download-button {
  display: inline-flex;
  align-items: center;
  gap: 8px;
  background: linear-gradient(135deg, var(--accent), var(--accent-dim));
  color: #000;
  font-weight: 600;
  padding: 10px 20px;
  border-radius: var(--radius-sm);
  font-size: 0.85rem;
  transition: all var(--transition);
}
.download-button:hover { box-shadow: 0 0 20px rgba(16,185,129,0.3); transform: translateY(-2px); }
.video-container {
  position: relative;
  padding-bottom: 56.25%;
  height: 0;
  overflow: hidden;
  border-radius: var(--radius-sm);
}
.video-container iframe { position: absolute; top: 0; left: 0; width: 100%; height: 100%; border: none; }
.badge-footer { padding: 20px 24px; text-align: center; background: var(--bg-alt); color: var(--text-dim); font-size: 0.85rem; }
.badge-footer .upload-date { margin-top: 6px; color: var(--primary); font-weight: 600; font-size: 0.82rem; }

/* ===== LCD CUSTOM CHARACTER GENERATOR ===== */
.lcd-display {
  background: #d9ea95;
  border-radius: 5px;
  padding: 1.5vw;
  display: grid;
  grid-template-columns: repeat(16, 1fr);
  gap: 0.5vw;
  width: 100%;
  box-sizing: border-box;
}
.lcd-cell {
  aspect-ratio: 5 / 8;
  display: grid;
  grid-template-columns: repeat(5, 1fr);
  grid-template-rows: repeat(8, 1fr);
  gap: 1px;
  background: #d1e195;
  border: 1px solid #c5d685;
  border-radius: 2px;
  cursor: pointer;
}
.lcd-pixel {
  background: #c8dc8a;
  border: 1px solid #bccf7e;
  border-radius: 1px;
  cursor: pointer;
}
.lcd-pixel.on {
  background: #133700;
  border-color: #133700;
}
.lcd-controls {
  display: flex;
  flex-wrap: wrap;
  gap: 10px;
  margin-top: 14px;
  align-items: center;
}
.lcd-control-button {
  border: none;
  border-radius: 5px;
  padding: 10px 20px;
  cursor: pointer;
  background: var(--primary);
  color: #000;
  font-size: 0.9rem;
  font-weight: 600;
  font-family: var(--font-body);
}
.lcd-control-button.clear { background: #c0392b; color: #fff; }
.lcd-code-area {
  display: flex;
  gap: 12px;
  margin-top: 16px;
  justify-content: flex-end;
  align-items: flex-start;
}
.lcd-code-box {
  position: relative;
  background: #fdf6e3;
  border-radius: 5px;
  padding: 20px;
  font-family: var(--font-mono);
  font-size: 0.85rem;
  color: #222;
  overflow-y: auto;
  max-height: 420px;
  white-space: pre;
  line-height: 1.6;
  width: 100%;
  box-sizing: border-box;
}
.lcd-copy-button {
  background: var(--primary);
  color: #000;
  border: none;
  padding: 8px 18px;
  border-radius: 5px;
  cursor: pointer;
  font-size: 0.85rem;
  font-weight: 600;
  font-family: var(--font-body);
  white-space: nowrap;
  flex-shrink: 0;
}
.lcd-help {
  margin-top: 10px;
  color: var(--text-dim);
  font-size: 0.8rem;
}

.reveal {
  opacity: 0;
  transform: translateY(30px);
  transition: opacity 0.7s cubic-bezier(0.25, 0.46, 0.45, 0.94),
              transform 0.7s cubic-bezier(0.25, 0.46, 0.45, 0.94);
}
.reveal.visible { opacity: 1; transform: translateY(0); }

.empty-state {
  text-align: center;
  padding: 80px 20px;
  color: var(--text-muted);
}
.empty-state .material-icons { font-size: 3rem; margin-bottom: 16px; }

@media (max-width: 768px) {
  header { flex-direction: column; gap: 12px; }
  .search-bar { width: 100%; }
  .page-header { flex-direction: column; align-items: flex-start; }
  .badge-header { flex-direction: column; gap: 12px; align-items: flex-start; }
  .home-link { margin: 0; }
  .component-card { max-width: 100%; }
  .component-image { width: 50px; height: 50px; }
}
@media (max-width: 600px) {
  .button-section { flex-direction: column; }
  .button-link { width: 100%; justify-content: center; }
}
/* ===== FEEDBACK BUTTON ===== */
#feedback-btn {
  position: fixed;
  bottom: 30px;
  right: 30px;
  z-index: 9999;
  background: linear-gradient(135deg, #00e5ff, #7c3aed);
  border: none;
  color: #fff;
  padding: 16px 28px;
  border-radius: 100px;
  cursor: pointer;
  font-size: 1rem;
  font-weight: 600;
  font-family: 'Inter', sans-serif;
  transition: all 0.3s ease;
  box-shadow: 0 0 30px rgba(0, 229, 255, 0.3);
  display: flex;
  align-items: center;
  gap: 10px;
  animation: feedback-pulse 2s ease-in-out infinite;
  letter-spacing: 0.5px;
  text-transform: uppercase;
}
#feedback-btn:hover {
  transform: translateY(-3px) scale(1.05);
  box-shadow: 0 0 50px rgba(0, 229, 255, 0.5), 0 0 100px rgba(124, 58, 237, 0.2);
}
#feedback-btn .material-icons { font-size: 1.3rem; }
@keyframes feedback-pulse {
  0%, 100% { box-shadow: 0 0 20px rgba(0, 229, 255, 0.3); }
  50% { box-shadow: 0 0 40px rgba(0, 229, 255, 0.5), 0 0 60px rgba(124, 58, 237, 0.2); }
}
.modal-overlay {
  display: none;
  position: fixed;
  inset: 0;
  background: rgba(0,0,0,0.6);
  backdrop-filter: blur(8px);
  justify-content: center;
  align-items: center;
  z-index: 10001;
}
.modal-box {
  background: #11253b;
  border: 1px solid #2563eb;
  border-radius: 16px;
  padding: 32px;
  width: 380px;
  max-width: 90vw;
  box-shadow: 0 8px 32px rgba(0,0,0,0.3);
}
.modal-box h3 {
  font-family: 'Inter', sans-serif;
  font-size: 1rem;
  margin: 0 0 16px;
  letter-spacing: 1px;
  color: #e0e6f0;
}
.modal-box label {
  display: block;
  font-size: 0.85rem;
  color: #a8c7ff;
  margin-bottom: 8px;
}
.stars { display: flex; gap: 4px; margin-bottom: 20px; }
.stars span {
  font-size: 28px;
  cursor: pointer;
  color: #555;
  transition: all 0.2s ease;
}
.stars span:hover,
.stars span.selected { color: #f59e0b; text-shadow: 0 0 10px rgba(245,158,11,0.3); }
.modal-box textarea {
  width: 100%;
  height: 80px;
  margin-top: 8px;
  margin-bottom: 16px;
  padding: 10px;
  border-radius: 8px;
  border: 1px solid #2563eb;
  background: #0a1128;
  color: #e0e6f0;
  font-family: 'Inter', sans-serif;
  resize: none;
  font-size: 0.85rem;
}
.modal-actions { display: flex; gap: 12px; justify-content: flex-end; }
.modal-actions button {
  padding: 8px 20px;
  border-radius: 8px;
  border: none;
  cursor: pointer;
  font-family: 'Inter', sans-serif;
  font-size: 0.85rem;
  font-weight: 600;
  transition: all 0.3s ease;
}
.cancel-btn { background: #1e405b; color: #a8c7ff; }
.cancel-btn:hover { background: #2a5a7a; }
.submit-btn {
  background: linear-gradient(135deg, #00e5ff, #7c3aed);
  color: #000;
}
.submit-btn:hover { box-shadow: 0 0 20px rgba(0,229,255,0.2); }

/* ===== FORM GROUP ===== */
.form-group { margin-bottom: 20px; }
.form-group label {
  display: block;
  font-size: 0.85rem;
  color: var(--text-dim);
  margin-bottom: 8px;
  font-weight: 500;
}
.form-group input {
  width: 100%;
  padding: 12px 16px;
  border-radius: var(--radius-sm);
  border: 1px solid var(--border);
  background: var(--bg);
  color: var(--text);
  font-family: var(--font-body);
  font-size: 0.9rem;
  transition: all var(--transition);
  outline: none;
}
.form-group input:focus {
  border-color: var(--primary);
  box-shadow: 0 0 0 3px rgba(0,229,255,0.1);
}

/* ===== SKELETON LOADER ===== */
.project-image-container, .connection-diagram, .component-card {
  position: relative;
  overflow: hidden;
}
.project-image-container::after, .connection-diagram::after, .component-card::after {
  content: '';
  position: absolute;
  inset: 0;
  z-index: 2;
  pointer-events: none;
  background: var(--bg-card);
  background-image: linear-gradient(110deg, transparent 0%, transparent 40%, rgba(255,255,255,0.06) 50%, transparent 60%, transparent 100%);
  background-size: 200% 100%;
  animation: shimmer 2.5s ease-in-out infinite;
}
.project-image-container.loaded::after, .connection-diagram.loaded::after, .component-card.loaded::after { display: none; }

@keyframes shimmer {
  0% { background-position: -200% center; }
  100% { background-position: 200% center; }
}
</style>
</head>
<body>

<button class="theme-toggle" id="themeToggle" aria-label="Toggle theme">
  <span class="material-icons" id="themeIcon">dark_mode</span>
</button>

<header role="banner">
  <div class="logo" aria-label="David Tech Lab Logo">David Tech Lab</div>
  <input type="text" class="search-bar" placeholder="Search projects..." id="searchInput" aria-label="Search Projects" />
</header>

<main>
  <div class="page-header">
    <div>
      <h1>All Projects</h1>
      <p class="subtitle">Browse the complete collection of electronics & microcontroller projects</p>
    </div>
    <a href="https://davidtechlab.blogspot.com/" class="button-link">
      <span class="material-icons" style="font-size:1rem;">home</span> Back to Home
    </a>
  </div>

  <div class="button-section" id="filterButtons">
    <button class="button-link active" data-filter="all" onclick="filterProjects('all')">
      <span class="material-icons" style="font-size:1rem;">apps</span> All
    </button>
    <button class="button-link" data-filter="arduino" onclick="filterProjects('arduino')">
      <span class="material-icons" style="font-size:1rem;">memory</span> Arduino
    </button>
    <button class="button-link" data-filter="esp32" onclick="filterProjects('esp32')">
        <span class="material-icons" style="font-size:1rem;">computer</span> ESP32
      </button>
  </div>

    <div class="cards-grid" id="projectsGrid">
    <!-- 1 -->
    <article class="project-card reveal" data-category="esp32" tabindex="0" onclick="openProject('p1')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786118613/ESP_32_ppesqt.png" alt="Arabic on TFT" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">ESP32 · MicroPython</span>
        <div class="title">Arabic language on TFT display</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 2 -->
    <article class="project-card reveal" data-category="arduino" tabindex="0" onclick="openProject('p2')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786381965/ESP_32_1_f8xcbr.png" alt="LED Memory Game" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">Arduino · C++</span>
        <div class="title">LED Memory Game</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 3 -->
    <article class="project-card reveal" data-category="arduino" tabindex="0" onclick="openProject('p3')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786618141/Copy_of_ESP_32_svuq9v.png" alt="Bluetooth LED Control" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">Arduino · C++</span>
        <div class="title">Bluetooth LED Control</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 4 -->
    <article class="project-card reveal" data-category="arduino" tabindex="0" onclick="openProject('p4')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786714341/Copy_of_ESP_32_gj5ugd.png" alt="Smoke Sensor" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">Arduino · C++</span>
        <div class="title">MQ-2 Gas Detection System</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 5 -->
    <article class="project-card reveal" data-category="arduino" tabindex="0" onclick="openProject('p5')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786966940/Copy_of_Copy_of_ESP_32_czedru.png" alt="Servo Motor Bluetooth" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">Arduino · C++</span>
        <div class="title">Bluetooth Servo Motor Control</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 6 -->
    <article class="project-card reveal" data-category="arduino" tabindex="0" onclick="openProject('p6')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787221792/Copy_of_Copy_of_ESP_32_rjvzik.png" alt="Drawing on LCD" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">Arduino · C++</span>
        <div class="title">Drawing on an LCD Display</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 7 -->
    <article class="project-card reveal" data-category="arduino" tabindex="0" onclick="openProject('p7')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787581144/Copy_of_Copy_of_Copy_of_ESP_32_qbxgtq.png" alt="Arduino Mini Piano" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">Arduino · C++</span>
        <div class="title">Arduino Mini Piano</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 8 -->
    <article class="project-card reveal" data-category="arduino" tabindex="0" onclick="openProject('p8')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787749697/Copy_of_Copy_of_Copy_of_Copy_of_ESP_32_swhtyu.png" alt="Arduino Calculator" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">Arduino · C++</span>
        <div class="title">Arduino Calculator</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 9 -->
    <article class="project-card reveal" data-category="arduino" tabindex="0" onclick="openProject('p9')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787817335/Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_ESP_32_xmddd0.png" alt="Ultrasonic LCD Meter" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">Arduino · C++</span>
        <div class="title">Ultrasonic Sensor and LCD Meter</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 10 -->
    <article class="project-card reveal" data-category="esp32" tabindex="0" onclick="openProject('p10')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1788110363/Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_ESP_32_1_umq3bp.png" alt="SSD1306 OLED Ultrasonic" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">ESP32 · MicroPython</span>
        <div class="title">SSD1306 OLED Display &amp; Ultrasonic Sensor</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 11 -->
    <article class="project-card reveal" data-category="esp32" tabindex="0" onclick="openProject('p11')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1788184229/Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_ESP_32_omzrne.png" alt="ILI9341 TFT LCD" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">ESP32 · MicroPython</span>
        <div class="title">ILI9341 TFT Display</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
    <!-- 12 -->
    <article class="project-card reveal" data-category="esp32" tabindex="0" onclick="openProject('p12')">
      <div class="image-wrap">
        <img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1788273844/Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_ESP_32_amvpgz.png" alt="Snake Game" loading="lazy" />
        <div class="overlay"><span>View Project</span></div>
      </div>
      <div class="content">
        <span class="tech">ESP32 · MicroPython</span>
        <div class="title">Snake Game</div>
        <button class="btn"><span class="material-icons" style="font-size:1rem;">visibility</span> View</button>
      </div>
    </article>
  </div>

<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p1" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects</a>
<h1 class="project-title">Arabic language on TFT display</h1>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786118613/ESP_32_ppesqt.png" alt="ESP32 Arabic TFT" class="project-main-image" loading="lazy" />
</div>
<p>This project demonstrates how to display properly rendered Arabic text on a TFT screen using an ESP32 and MicroPython. It covers bidirectional text handling, custom font loading, and right-to-left rendering to show Arabic characters with correct shaping and diacritics.</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">lightbulb</span> Project Idea </h2>
<p>
<ul>
  <li>Display properly rendered Arabic text on an ILI9341 TFT screen using an ESP32</li>
  <li>Preserve the natural connected shape of Arabic letters, as they appear in real handwriting/print</li>
  <li>Avoid showing disconnected, isolated Unicode glyphs</li>
</ul>
</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">warning</span> Challenges </h2>
<p>
<ul>
  <li>MicroPython display libraries (like <code>xglcdfont</code>) are built primarily for ASCII fonts, with no built-in support for Arabic characters or letter connectivity</li>
  <li>A single Arabic letter changes shape depending on its position in the word (isolated, initial, medial, final)</li>
  <li>Certain letters (ا، د، ذ، ر، ز، و) never connect to the letter that follows them, which has to be accounted for when determining each letter's shape</li>
  <li>The screen's font renderer only understands byte-based bitmap fonts, so Arabic Unicode characters can't be fed to it directly — they need to be mapped to custom glyph codes first</li>
</ul>
</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Solution Method </h2>
<p>
<ol>
  <li>For every Arabic letter in the input string, check whether the previous and next characters are spaces, non-connecting letters, or string boundaries</li>
  <li>Based on that context, pick the correct visual form — isolated, initial, medial, or final — from a lookup table mapping each Arabic letter to four placeholder characters</li>
  <li>Handle the letter "ه" as a special case, since its shape changes more irregularly than the others</li>
  <li>Feed the converted placeholder string to a custom bitmap font file (<code>font.c</code>), where each placeholder code has a matching hand-drawn 6×8 pixel glyph in the correct connected shape</li>
  <li>Render the final string using <code>xglcdfont.py</code> and <code>ili9341.py</code>, exactly like a normal ASCII string</li>
</ol>
</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Code Explanation </h2>
<p>
<ul>
  <li><code>arabic_font_assistant.py</code> — the core logic. <code>convert()</code> loops through each character, determines its connection state using the <code>non_connectors_right</code> set, and maps it to the right placeholder character</li>
  <li><code>type_text()</code> — the public entry point used in <code>main.py</code></li>
  <li><code>font.c</code> — a bitmap font table where each entry corresponds to one placeholder character, drawn to look like the correctly-connected Arabic letterform</li>
  <li><code>xglcdfont.py</code> — parses <code>font.c</code> and converts each glyph into pixel data for the display</li>
  <li><code>main.py</code> — ties it all together: takes an Arabic string, runs it through <code>arabic_font_assistant.type_text()</code>, then calls <code>display.draw_text()</code> to render it on the TFT</li>
</ul>
</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">rocket_launch</span> Development Ideas </h2>
<p>
<ol>
  <li>Extend the character map to support Arabic diacritics (tashkeel)</li>
  <li>Support larger, higher-resolution custom fonts beyond the current 6×8 bitmap size</li>
  <li>Turn <code>arabic_font_assistant.py</code> into a standalone reusable MicroPython library for other TFT/OLED projects needing Arabic text</li>
  <li>Add right-to-left line wrapping for longer strings that exceed the screen width</li>
</ol>
</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Components</h2>
<div class="components-grid">
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786119224/c1e24f62-b9e5-45bf-bc2a-8c12266f374f.png" alt="ESP32" class="component-image" loading="lazy" />
<div class="component-info">
<h2>ESP32</h2>
<p>We will use MicroPython</p>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648807/TFT_img_dubem0.png" alt="TFT Display" class="component-image" loading="lazy" />
<div class="component-info">
<h2>TFT Display</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy" />
<div class="component-info">
<h2>Jumper Wires</h2>
</div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786119706/d6256226-ae33-47b5-9fc4-532b8619fe16.png" alt="Connection Diagram" class="connection-image" loading="lazy" />
</div>
<div class="connection-steps">
<div class="connection-step">
<span class="connection-pin">TFT VCC</span> → 3.3V</div>
<div class="connection-step"><span class="connection-pin">TFT GND</span> → GND</div>
<div class="connection-step"><span class="connection-pin">TFT CS</span> → GPIO6</div>
<div class="connection-step"><span class="connection-pin">TFT RST</span> → GPIO17</div>
<div class="connection-step"><span class="connection-pin">TFT D/C</span> → GPIO16</div>
<div class="connection-step"><span class="connection-pin">TFT MOSI</span> → GPIO11</div>
<div class="connection-step"><span class="connection-pin">TFT SCK</span> → GPIO10</div>
<div class="connection-step"><span class="connection-pin">TFT LED</span> → 3.3V</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)">
<span class="material-icons">content_copy</span> Copy</button>
<div class="code-block"><pre><code>from machine import Pin, SPI
from ili9341 import Display, color565
from xglcdfont import XglcdFont
import arabic_font_assest

terminal_font = XglcdFont('font.c', 6, 8, start_letter=32, letter_count=116)

spi = SPI(1, baudrate=20000000, polarity=0, phase=0,
sck=Pin(10), mosi=Pin(11))
cs  = Pin(5, Pin.OUT)
dc  = Pin(16, Pin.OUT)
rst = Pin(17, Pin.OUT)

display = Display(spi, cs=cs, dc=dc, rst=rst)

text = arabic_font_assest.type_text("ديفيد مدحت")
display.draw_text(0, 0, text, terminal_font, color565(255, 255, 255), 0, False, False)</code></pre></div></div><p>This project requires external MicroPython libraries not included in Thonny's Library Manager. Download all necessary files (main code, libraries, and Wokwi diagram) from the link below.</p>
<a href="https://drive.google.com/uc?export=download&id=1agcPE_kKeN3zMG_bw6nUX1pDtMcAihV3" class="download-button" download>
<span class="material-icons">download</span> Download Code with All Libraries</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">videocam</span> Project Video
</h2>
<div class="video-container">
<iframe
src="https://www.youtube.com/embed/jev-syf69pA"
width="100%"
height="500"
frameborder="0"
allow="autoplay; encrypted-media"
allowfullscreen>
</iframe>
</div>
<p style="text-align: center; margin-top: 15px;">
<a
href="https://www.youtube.com/watch?v=jev-syf69pA"
target="_blank"
class="footer-link">
Watch on YouTube
</a>
</p>
</div>
<div class="badge-footer">
<p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 14 March 2025</p>
</div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p2" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects</a>
<h1 class="project-title">LED Memory Game</h1>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786381965/ESP_32_1_f8xcbr.png" alt="LED memory game using Arduino" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to build an LED memory game using Arduino. It includes random pattern generation, button interaction, and logic to track and verify player input.</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">lightbulb</span> Project Idea </h2>
<ul>
<li>Generate a random sequence of 4 LEDs</li>
<li>The player must repeat the same sequence by pressing the matching buttons in order</li>
<li>Each time the player succeeds, the sequence grows by one more step and the speed increases</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">warning</span> Challenges </h2>
<ul>
<li>The full sequence is pre-generated once as a 100-number array, instead of generating a new random number on every step</li>
<li>Each button press needs to be distinguished from its release (debouncing), so a single press isn't counted twice</li>
<li>The game needs to stay responsive while waiting for the player's button press, without freezing or lagging</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Solution Method </h2>
<ol>
<li>At the start of each round, generate a long array of 100 random numbers (0–3) in advance, one for each possible step in the game</li>
<li>Only reveal and play the first "level" numbers from that array — the current sequence the player needs to repeat</li>
<li>Use a polling loop (<code>waitForAnyButtonPress</code>) that continuously checks all 4 buttons until one is pressed</li>
<li>Compare each button press against the corresponding number in the sequence — if it doesn't match, the game ends</li>
<li>Every time the player succeeds, increase <code>level</code> by one and decrease <code>speedMs</code> by 25 (down to a minimum of 250), making the game faster and harder over time</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Code Explanation </h2>
<ul>
<li><code>startGame()</code> — resets the level and speed, and generates a fresh 100-number random sequence array</li>
<li><code>playSequence()</code> — lights up the first <code>level</code> LEDs from the sequence, one at a time, with a delay based on <code>speedMs</code></li>
<li><code>getPlayerInput()</code> — waits for the player's button presses and compares each one against the original sequence, returning <code>false</code> on a mismatch</li>
<li><code>waitForAnyButtonPress()</code> — loops continuously, checking all 4 buttons until it detects one being pressed</li>
<li><code>loseGame()</code> — flashes all 4 LEDs together 3 times as a "game over" signal before restarting</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">rocket_launch</span> Development Ideas </h2>
<ol>
<li>Add a buzzer with a different tone for each LED, like the original Simon game</li>
<li>Save the high score to EEPROM so it survives after the Arduino restarts</li>
<li>Add an LCD or 7-segment display to show the current level or score, instead of relying on the Serial Monitor</li>
<li>Add selectable difficulty modes (Easy/Medium/Hard) that control the starting and minimum <code>speedMs</code> values</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Components</h2>
<div class="components-grid"><div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648778/Arduino_img_board_nobg_zfmod7.png" alt="Arduino" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Arduino</h2></div></div><div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648800/Puch_button_img_rd532o.png" alt="Puch button" class="component-image" loading="lazy"/>
<div class="component-info"><h2>4-Puch Buttons</h2></div></div><div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648796/LED-Green-Color_xqcamf.png" alt="LED_img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>4-LED</h2></div></div><div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648779/Breadboard_img_flkekc.jpg" alt="Breadboard_img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Breadboard</h2></div></div><div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Jumper Wires</h2></div></div></div></div><div class="badge-section">
<h2 class="section-title"><span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786380280/632d145c-7919-4c8f-98c5-4d0d052c7bfe.png" alt="Connection Diagram" class="connection-image" loading="lazy"/>
</div><div class="connection-steps">
<div class="connection-step">
<span class="connection-pin">LED 1</span> → D2
</div>
<div class="connection-step">
<span class="connection-pin">LED 2</span> → D3
</div>
<div class="connection-step">
<span class="connection-pin">LED 3</span> → D4
</div>
<div class="connection-step">
<span class="connection-pin">LED 4</span> → D5
</div>
<div class="connection-step">
<span class="connection-pin">Button 1</span> → D7
</div>
<div class="connection-step">
<span class="connection-pin">Button 2</span> → D8
</div>
<div class="connection-step">
<span class="connection-pin">Button 3</span> → D9
</div>
<div class="connection-step">
<span class="connection-pin">Button 4</span> → D10
</div>
<div class="connection-step">
<span class="connection-pin">Buttons GND</span> → GND
</div>
<div class="connection-step">
<span class="connection-pin">LEDs GND</span> → GND
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)">
<span class="material-icons">content_copy</span> Copy</button>
<div class="code-block"><pre><code>// LED Memory Game
const int LED_PINS[4]    = {2, 3, 5, 6};
const int BUTTON_PINS[4] = {6, 7, 8, 9};

const int MAX_LENGTH = 100;
int sequence[MAX_LENGTH];
int level = 0;
int speedMs = 600;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));

  for (int i = 0; i < 4; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
    digitalWrite(LED_PINS[i], LOW);
  }

  Serial.println("=== LED Memory Game ===");
  Serial.println("Press any button to start");
  waitForAnyButtonPress();
  startGame();
}

void loop() {
  playSequence();
  bool correct = getPlayerInput();

  if (correct) {
    level++;
    Serial.print("Correct! Level: ");
    Serial.println(level);
    if (speedMs > 250) speedMs -= 25;
    delay(800);
  } else {
    loseGame();
    startGame();
  }
}

void startGame() {
  level = 1;
  speedMs = 600;
  for (int i = 0; i < MAX_LENGTH; i++) {
    sequence[i] = random(0, 4);
  }
}

void playSequence() {
  delay(500);
  for (int i = 0; i < level; i++) {
    int idx = sequence[i];
    digitalWrite(LED_PINS[idx], HIGH);
    delay(speedMs);
    digitalWrite(LED_PINS[idx], LOW);
    delay(150);
  }
}

bool getPlayerInput() {
  for (int i = 0; i < level; i++) {
    int pressed = waitForAnyButtonPress();

    digitalWrite(LED_PINS[pressed], HIGH);
    delay(200);
    digitalWrite(LED_PINS[pressed], LOW);

    if (pressed != sequence[i]) {
      return false;
    }
  }
  return true;
}

int waitForAnyButtonPress() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(BUTTON_PINS[i]) == LOW) {
        delay(30);
        while (digitalRead(BUTTON_PINS[i]) == LOW) {
        }
        return i;
      }
    }
  }
}

void loseGame() {
  Serial.println("You lost! Restarting...");
  for (int r = 0; r < 3; r++) {
    for (int i = 0; i < 4; i++) digitalWrite(LED_PINS[i], HIGH);
    delay(200);
    for (int i = 0; i < 4; i++) digitalWrite(LED_PINS[i], LOW);
    delay(200);
  }
  delay(500);
}
</code>
</pre>
</div>
</div>
<a href="https://drive.google.com/uc?export=download&id=1pllPlVlhh1OmCGjxklSO27M5YKY3mPxp" class="download-button" download>
<span class="material-icons">download</span> Download Code</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">videocam</span> Project Video
</h2>
<div class="video-container">
<iframe
src="https://www.youtube.com/embed/x9c1O0GVngU"
width="100%"
height="500"
frameborder="0"
allow="autoplay; encrypted-media"
allowfullscreen>
</iframe>
</div>
<p style="text-align: center; margin-top: 15px;">
<a
href="https://www.youtube.com/watch?v=x9c1O0GVngU"
target="_blank"
class="footer-link">
Watch on YouTube
</a>
</p>
</div>
<div class="badge-footer">
<p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 9 June 2024</p>
</div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p3" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects</a>
<h1 class="project-title">Bluetooth LED Control</h1>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786618141/Copy_of_ESP_32_svuq9v.png" alt="control an LED using Arduino and Bluetooth" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to control an LED using Arduino and Bluetooth. It includes wireless communication with a smartphone and allows turning the LED on or off through a Bluetooth terminal app.</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">lightbulb</span> Project Idea </h2>
<ul>
<li>Control an Arduino LED wirelessly from a smartphone using Bluetooth</li>
<li>The LED turns on or off instantly based on the character received, with no physical wiring to a switch</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">warning</span> Challenges </h2>
<ul>
<li>The Arduino needs to reliably distinguish between different characters coming from the phone and execute the right command quickly</li>
<li>The mobile app used in the original video is no longer available on Google Play, so users need a suitable alternative like Serial Bluetooth Terminal</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Solution Method </h2>
<ol>
<li>The Arduino continuously checks whether data has arrived on Serial from the HC-05 module (<code>Serial.available()</code>)</li>
<li>When a character arrives, it's read and compared against known values using a <code>switch</code> statement</li>
<li>If the character is "A", the LED turns on; if it's "S", the LED turns off</li>
<li>Any other character falls into the default case and is ignored, while still being printed to the Serial Monitor for confirmation</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Code Explanation </h2>
<ul>
<li><code>setup()</code> — initializes Serial communication and sets pin D2 as an output for the LED</li>
<li><code>loop()</code> — continuously checks if data is available on Serial (<code>Serial.available() > 0</code>)</li>
<li><code>Serial.read()</code> — reads the single character sent from the phone through the HC-05 module</li>
<li><code>switch(data)</code> — compares the character to "A" or "S" and calls <code>digitalWrite</code> accordingly</li>
<li><code>delay(50)</code> — adds a short pause before checking the loop again</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">rocket_launch</span> Development Ideas </h2>
<ol>
<li>Add more commands to control multiple LEDs independently</li>
<li>Add brightness control (PWM/dimming) instead of just on/off</li>
<li>Build a dedicated mobile app instead of relying on a generic Serial Terminal app</li>
<li>Upgrade to Bluetooth Low Energy (BLE) for lower power consumption</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Components</h2>
<div class="components-grid"><div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648778/Arduino_img_board_nobg_zfmod7.png" alt="Arduino" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Arduino</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648786/hc-05_Blutooth_module_img_l4aoc0.png" alt="hc-05 Blutooth module_img" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>HC-05 Bluetooth Module</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648795/LED_img_k5uwcl.png" alt="LED_img" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>LED</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648779/Breadboard_img_flkekc.jpg" alt="Breadboard_img" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Breadboard</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Jumper Wires</h2>
</div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786630992/Untitled_fob82n.png" alt="Connection Diagram" class="connection-image" loading="lazy"/>
</div>
<div class="connection-steps">
<div class="connection-step">
<span class="connection-pin">HC-05 VCC</span> → 5V
</div>
<div class="connection-step">
<span class="connection-pin">HC-05 GND</span> → GND
</div>
<div class="connection-step">
<span class="connection-pin">HC-05 TX</span> → D0 (RX)
</div>
<div class="connection-step">
<span class="connection-pin">HC-05 RX</span> → D1 (TX)
</div>
<div class="connection-step">
<span class="connection-pin">LED +</span> → D2</div>
<div class="connection-step">
<span class="connection-pin">LED -</span> → GND</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)">
<span class="material-icons">content_copy</span> Copy</button>
<div class="code-block">
<pre>
<code>
void setup() {
Serial.begin(9600);
pinMode(13, OUTPUT);
}
void loop() {
if (Serial.available() > 0) {
char data = Serial.read();

switch (data) {
case 'A': digitalWrite(2, HIGH); break;
case 'S': digitalWrite(2, LOW); break;
default: break;
}

Serial.println(data);
}

delay(50);
}
</code>
</pre>
</div>
</div>
<a href="https://drive.google.com/uc?export=download&id=19hFWM1b2k6mo9CqHGcGTbKwNvFav6D9A" class="download-button" download>
<span class="material-icons">download</span> Download Code</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">phone_android</span> Mobile App</h2>
<p>This project includes a mobile app that allows you to control the LED via Bluetooth. Download the app from Google Play to get started!</p>
<p style="color:var(--text-dim);font-size:0.85rem;">Note : the app used in video dosn't include in google play now</p>
<a href="https://play.google.com/store/apps/details?id=com.giristudio.hc05.bluetooth.arduino.control" target="_blank" class="download-button">
<span class="material-icons">download</span> Download from Google Play</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">videocam</span> Project Video
</h2>
<div class="video-container">
<iframe
src="https://www.youtube.com/embed/g3KptMVz9xs"
width="100%"
height="500"
frameborder="0"
allow="autoplay; encrypted-media"
allowfullscreen>
</iframe>
</div>
<p style="text-align: center; margin-top: 15px;">
<a
href="https://www.youtube.com/watch?v=g3KptMVz9xs"
target="_blank"
class="footer-link">
Watch on YouTube
</a>
</p>
</div>
<div class="badge-footer">
<p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 2 September 2024</p>
</div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p4" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects</a>
<h1 class="project-title">MQ-2 Gas Detection System</h1>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786714341/Copy_of_ESP_32_gj5ugd.png" alt="smoke using an Arduino and a gas sensor" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to detect smoke using an Arduino and a gas sensor. It includes real-time monitoring, threshold-based detection, and visual or buzzer alerts when smoke levels are high.</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">lightbulb</span> Project Idea </h2>
<ul>
<li>Continuously monitor air quality using an MQ-2 gas/smoke sensor</li>
<li>Give instant visual feedback (red/green LED) showing whether smoke levels are safe or dangerous</li>
<li>Sound a buzzer alert automatically when smoke is detected above a safe level</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">warning</span> Challenges </h2>
<ul>
<li>The MQ-2 sensor outputs a raw analog value, not a simple "smoke / no smoke" signal, so a decision threshold has to be defined manually</li>
<li>The system needs to react quickly and continuously without any noticeable delay when smoke is detected</li>
<li>Both visual (LED) and audible (buzzer) alerts need to stay in sync with the sensor reading at all times</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Solution Method </h2>
<ol>
<li>Continuously read the analog output of the MQ-2 sensor on pin A0</li>
<li>Compare the reading against a fixed threshold value (500)</li>
<li>If the reading exceeds the threshold, turn on the red LED and sound the buzzer</li>
<li>If the reading stays below the threshold, turn on the green LED and keep the buzzer off</li>
<li>Repeat this check every 100 milliseconds for near real-time monitoring</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Code Explanation </h2>
<ul>
<li><code>analogRead(smokeA0)</code> — reads the current smoke/gas concentration value from the MQ-2 sensor</li>
<li><code>sensorThres</code> — the threshold value (500) used to decide between "safe" and "danger" states</li>
<li><code>if (analogSensor > sensorThres)</code> — when smoke is above the threshold, the red LED turns on and <code>tone()</code> triggers the buzzer</li>
<li><code>else</code> block — when smoke is within a safe range, the green LED turns on and <code>noTone()</code> keeps the buzzer silent</li>
<li><code>Serial.println(analogSensor)</code> — prints the live reading to the Serial Monitor for debugging/monitoring</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">rocket_launch</span> Development Ideas </h2>
<ol>
<li>Add an LCD or OLED display to show the live sensor reading as a number, not just LED status</li>
<li>Send an alert notification to a phone (via Bluetooth or Wi-Fi) when smoke is detected</li>
<li>Add a calibration/warm-up routine, since MQ-2 sensors need a few minutes to stabilize after power-on</li>
<li>Log readings over time to detect gradual air-quality trends, not just instant threshold crossing</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Components</h2>
<div class="components-grid">
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648778/Arduino_img_board_nobg_zfmod7.png" alt="Arduino" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Arduino</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648800/mq2-Gas-sensore-img_myw3bw.png" alt="mq2-Gas-sensore-img" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>MQ2 Gas Sensore</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648795/LED_img_k5uwcl.png" alt="LED_img" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Red LED</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648796/LED-Green-Color_xqcamf.png" alt="LED-Green-Color" class="component-image" loading="lazy" />
<div class="component-info">
<h2>Green LED</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648779/buzzer-img_hsg7p3.png" alt="buzzer-img" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Buzzer</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648779/Breadboard_img_flkekc.jpg" alt="Breadboard_img" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Breadboard</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Jumper Wires</h2>
</div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648798/MQ2_Smoke_Gas_Sensore_crhris.png" alt="Connection Diagram" class="connection-image" loading="lazy"/>
</div><div class="connection-steps">
<div class="connection-step">
<span class="connection-pin">MQ2 VCC</span> → 5V</div>
<div class="connection-step">
<span class="connection-pin">MQ2 GND</span> → GND</div>
<div class="connection-step"><span class="connection-pin">MQ2 AOUT</span> → A0</div>
<div class="connection-step"><span class="connection-pin">Red LED</span> → D2</div>
<div class="connection-step"><span class="connection-pin">Green LED</span> → D3</div>
<div class="connection-step"><span class="connection-pin">Buzzer</span> → D4</div>
<div class="connection-step"><span class="connection-pin">LEDs GND</span> → GND</div>
<div class="connection-step"><span class="connection-pin">Buzzer GND</span> → GND</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)">
<span class="material-icons">content_copy</span> Copy</button>
<div class="code-block">
<pre>
<code>
int redLed = 2;
int greenLed = 3;
int buzzer = 4;
int smokeA0 = A0;

int sensorThres = 500  ;

void setup() {
pinMode(redLed, OUTPUT);
pinMode(greenLed, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(smokeA0, INPUT);
Serial.begin(9600);
}

void loop() {
int analogSensor = analogRead(smokeA0);

Serial.print("Pin A0: ");
Serial.println(analogSensor);
if (analogSensor > sensorThres)
{
digitalWrite(redLed, HIGH);
digitalWrite(greenLed, LOW);
tone(buzzer, 1000, 200);
}
else
{
digitalWrite(redLed, LOW);
digitalWrite(greenLed, HIGH);
noTone(buzzer);
}
delay(100);
}
</code>
</pre>
</div>
</div>
<a href="https://drive.google.com/uc?export=download&id=1kAtyHIyPRdlr2z9Z3-TplBAJv_FwQZr6" class="download-button" download>
<span class="material-icons">download</span> Download Code</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">videocam</span> Project Video
</h2>
<div class="video-container">
<iframe
src="https://www.youtube.com/embed/jroO5Libzhs"
width="100%"
height="500"
frameborder="0"
allow="autoplay; encrypted-media"
allowfullscreen>
</iframe>
</div>
<p style="text-align: center; margin-top: 15px;">
<a
href="https://www.youtube.com/watch?v=jroO5Libzhs"
target="_blank"
class="footer-link">
Watch on YouTube
</a>
</p>
</div>
<div class="badge-footer">
<p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 5 January 2025</p>
</div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p5" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects</a>
<h1 class="project-title">Bluetooth Servo Motor Control</h1>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786966940/Copy_of_Copy_of_ESP_32_czedru.png" alt="control a servo motor using Arduino and Bluetooth" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to control a servo motor using Arduino and Bluetooth. It includes wireless communication with a smartphone and allows adjusting the motor angle through a Bluetooth terminal app.</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">lightbulb</span> Project Idea </h2>
<ul>
<li>Control a Servo Motor's angle remotely and wirelessly using Bluetooth</li>
<li>Provide a mobile app interface (built with MIT App Inventor) with a Slider to choose the desired angle</li>
<li>Send the selected angle to the Arduino over Bluetooth so the Servo moves to that exact position</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">warning</span> Challenges </h2>
<ul>
<li>Some Arduino boards (like the Uno) only have a single 5V pin, which isn't enough to comfortably power both the Bluetooth module and the Servo, making the Mega a better choice</li>
<li>The Bluetooth module's TX and RX pins must be crossed with the Arduino's RX and TX — connecting them straight is a common mistake that blocks communication entirely</li>
<li>The Baud Rate (9600) must match exactly between the Arduino and the Bluetooth module, or the data received becomes corrupted or unreadable</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Solution Method </h2>
<ol>
<li>Wire the HC-05/HC-06 Bluetooth module to the Arduino: VCC to 5V, GND to GND, TX to RX, and RX to TX</li>
<li>Wire the Servo Motor's Signal wire to digital Pin 2, with GND to GND and VCC to 5V</li>
<li>Use the Servo.h library to attach the Servo object to Pin 2 and initialize serial communication at 9600 baud</li>
<li>Continuously check for incoming serial data, and when a new value arrives, read it and move the Servo to that angle</li>
<li>Build a mobile app in MIT App Inventor with a Slider to select the angle and buttons to connect to the Bluetooth module</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Code Explanation </h2>
<ul>
<li><code>#include &lt;Servo.h&gt;</code> — imports the Servo library, giving ready-made functions to control the Servo Motor</li>
<li><code>Servo myservo;</code> — creates a Servo object representing the physical motor inside the code</li>
<li><code>myservo.attach(2);</code> — connects the Servo object to digital Pin 2, the same pin wired to the Servo's Signal wire</li>
<li><code>Serial.begin(9600);</code> — starts serial communication at 9600 baud so the Arduino can talk to the Bluetooth module</li>
<li><code>if (Serial.available() > 0)</code> — checks whether new data has arrived through the serial connection</li>
<li><code>servoPos</code> and <code>myservo.write(servoPos)</code> — stores the received value and moves the Servo to that received angle</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">rocket_launch</span> Development Ideas </h2>
<ol>
<li>Add support for controlling multiple Servo motors independently from the same app</li>
<li>Show the Servo's current angle back on the app screen instead of one-way control only</li>
<li>Replace Bluetooth with WiFi (e.g. ESP32) to control the Servo remotely over the internet, not just short range</li>
<li>Add preset buttons for commonly used angles instead of relying on the Slider every time</li>
<li>Integrate with voice control (Google Assistant / IFTTT) for hands-free operation</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Components</h2>
<div class="components-grid">
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648778/Arduino_img_board_nobg_zfmod7.png" alt="Arduino" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Arduino</h2></div></div><div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648786/hc-05_Blutooth_module_img_l4aoc0.png" alt="hc-05 Blutooth module_img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>HC-05 Bluetooth Module</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648802/Servo_motor-img_fqmjt1.png" alt="Servo_motor-img" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Servo Motor</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Jumper Wires</h2>
</div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786968463/Copy_of_Copy_of_ESP_32_kvw6e0.jpg" alt="Connection Diagram" class="connection-image" loading="lazy"/>
</div>
<div class="connection-steps">
<div class="connection-step">
<span class="connection-pin">HC-05 VCC</span> → 5V</div>
<div class="connection-step">
<span class="connection-pin">HC-05 GND</span> → GND</div>
<div class="connection-step"><span class="connection-pin">HC-05 TX</span> → D0 (RX)</div>
<div class="connection-step"><span class="connection-pin">HC-05 RX</span> → D1 (TX)</div>
<div class="connection-step"><span class="connection-pin">Servo motor +</span> → 5V</div>
<div class="connection-step"><span class="connection-pin">Servo motor -</span> → GND</div>
<div class="connection-step"><span class="connection-pin">Servo motor D</span> → D2</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container"><button class="copy-button" onclick="copyCode(this)">
<span class="material-icons">content_copy</span> Copy</button><div class="code-block">
<pre>
<code>
#include &lt;Servo.h&gt;

Servo myservo;

void setup()
{
  myservo.attach(2);

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    int servopos = Serial.read();

    Serial.println(servopos);

    myservo.write(servopos);
  }
}
</code>
</pre>
</div>
</div>
<a href="https://drive.google.com/uc?export=download&id=1Z8PGddlqiSKFdE90ujriy8IPLF7kNTbE" class="download-button" download>
<span class="material-icons">download</span> Download Code</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">phone_android</span> Mobile App</h2>
<p>This project includes a mobile app that allows you to control the Servo motor via Bluetooth.</p>
<a href="https://drive.google.com/uc?export=download&id=18bdcudl6LkH7Q8xUyxzujgkcEiD1yOV2" target="_blank" class="download-button">
<span class="material-icons">download</span> Direct link Download Android</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">videocam</span> Project Video
</h2>
<div class="video-container">
<iframe
src="https://www.youtube.com/embed/Z2nQFtqlyug"
width="100%"
height="500"
frameborder="0"
allow="autoplay; encrypted-media"
allowfullscreen>
</iframe>
</div>
<p style="text-align: center; margin-top: 15px;">
<a
href="https://www.youtube.com/watch?v=Z2nQFtqlyug"
target="_blank"
class="footer-link">
Watch on YouTube
</a>
</p>
</div>
<div class="badge-footer"><p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 27 April 2024</p>
</div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p6" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects</a>
<h1 class="project-title">Drawing on an LCD Display</h1>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787221792/Copy_of_Copy_of_ESP_32_rjvzik.png" alt="Drawing on LCD using Arduino" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to create drawings on an LCD display using Arduino. It includes pixel-level control, shape drawing, and custom graphics rendering.</p>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">lightbulb</span> Project Idea </h2>
<ul>
<li>Draw any custom shape or symbol and display it directly on a 16x2 LCD screen</li>
<li>Provide an easy visual tool (LCD Custom Character Generator) instead of manually writing pixel-by-pixel byte code</li>
<li>Automatically generate ready-to-use Arduino code from the drawn shape</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">warning</span> Challenges </h2>
<ul>
<li>The HD44780-type LCD controller can only store up to 8 custom characters at once due to its limited CGRAM — a hardware limitation that cannot be bypassed</li>
<li>Manually calculating and writing the byte array for each pixel of a custom character is slow and error-prone</li>
<li>The wiring must be precise, since RS, E, and the four data pins (D4-D7) all need to match the pin numbers used in the code</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Solution Method </h2>
<ol>
<li>Wire the LCD to the Arduino: VSS-GND, VDD-5V, VO to the potentiometer's middle pin, RS-Pin12, RW-GND, E-Pin11, D4-Pin5, D5-Pin4, D6-Pin3, D7-Pin2, and backlight A-5V, K-GND</li>
<li>Connect the potentiometer's two outer pins to 5V and GND for contrast control</li>
<li>Open the LCD Custom Character Generator tool on David Tech Lab (under More Projects → Drawing on an LCD)</li>
<li>Draw the desired shape visually using the tool</li>
<li>Copy the automatically generated Arduino code and upload it as-is, adjusting only the pin numbers if the wiring differs</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Code Explanation </h2>
<ul>
<li><code>byte customChar[8]</code> — stores the 8-byte pixel pattern (one byte per row) representing the drawn shape</li>
<li><code>lcd.createChar(slot, customChar)</code> — registers the custom character into one of the 8 available CGRAM slots (0–7)</li>
<li><code>lcd.begin(16, 2)</code> — initializes the LCD in 16-column, 2-row mode</li>
<li><code>lcd.write(byte(slot))</code> — prints the custom character at the current cursor position using its CGRAM slot number</li>
<li><code>lcd.setCursor(col, row)</code> — positions where the next character (custom or normal text) will be printed on the screen</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">rocket_launch</span> Development Ideas </h2>
<ol>
<li>Create simple animations by rapidly switching between different custom characters (frame-by-frame animation)</li>
<li>Combine multiple 5x8 custom characters together to build larger drawings</li>
<li>Add a preset library in the tool so users can quickly load ready-made shapes</li>
<li>Trigger different drawings automatically using a sensor or button input</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Components</h2>
<div class="components-grid">
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648778/Arduino_img_board_nobg_zfmod7.png" alt="Arduino" class="component-image" loading="lazy" />
<div class="component-info">
<h2>Arduino</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648794/LCD16x2_img_nlofi0.png" alt="TFT Display" class="component-image" loading="lazy" />
<div class="component-info">
<h2>LCD</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648800/Potentiometer_img_aioyzf.png" alt="TFT Display" class="component-image" loading="lazy" />
<div class="component-info">
<h2>Potentiometer 10K</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy" />
<div class="component-info">
<h2>Jumper Wires</h2>
</div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787234824/fb1b3abe-ca2a-4ab7-bf91-07541da4afb0.png" alt="Connection Diagram" class="connection-image" loading="lazy"/>
</div>
<div class="connection-steps">
<div class="connection-step">
<span class="connection-pin">VSS</span> → GND</div>
<div class="connection-step">
<span class="connection-pin">VDD</span> → 5V</div>
<div class="connection-step">
<span class="connection-pin">VO</span> → Potentiometer 10K (Middle)</div>
<div class="connection-step">
<span class="connection-pin">RS</span> → D12</div>
<div class="connection-step">
<span class="connection-pin">RW</span> → GND</div>
<div class="connection-step">
<span class="connection-pin">E</span> → D11</div>
<div class="connection-step">
<span class="connection-pin">D4</span> → D5</div>
<div class="connection-step">
<span class="connection-pin">D5</span> → D4</div>
<div class="connection-step">
<span class="connection-pin">D6</span> → D3</div>
<div class="connection-step">
<span class="connection-pin">D7</span> → D2</div>
<div class="connection-step">
<span class="connection-pin">A (LED+)</span> → 5V</div>
<div class="connection-step">
<span class="connection-pin">K (LED-)</span> → GND</div>
<div class="connection-step">
<span class="connection-pin">Potentiometer 10K</span> → 5V / GND</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)">
<span class="material-icons">content_copy</span> Copy</button>
<div class="code-block">
<pre>
<code>
#include &lt;LiquidCrystal.h&gt;

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void image() {
lcd.clear();

byte image07[8] = {B00111, B01000, B10000, B00000, B00000, B00000, B00010, B00000};
byte image08[8] = {B11100, B00010, B00001, B00000, B00000, B00000, B01000, B00000};
byte image06[8] = {B01000, B11000, B00000, B00001, B00010, B00010, B00100, B00100};
byte image09[8] = {B00010, B00011, B00000, B10000, B01000, B01000, B00100, B00100};
byte image22[8] = {B00100, B00100, B00010, B00010, B00001, B00000, B11000, B01000};
byte image25[8] = {B00100, B00100, B01000, B01000, B10000, B00000, B00011, B00010};
byte image23[8] = {B00000, B10000, B01000, B00100, B00011, B10000, B01000, B00111};
byte image24[8] = {B00000, B00001, B00010, B00100, B11000, B00001, B00010, B11100};

lcd.createChar(0, image07);
lcd.createChar(1, image08);
lcd.createChar(2, image06);
lcd.createChar(3, image09);
lcd.createChar(4, image22);
lcd.createChar(5, image25);
lcd.createChar(6, image23);
lcd.createChar(7, image24);

lcd.setCursor(6, 0);
lcd.write(byte(0));
lcd.setCursor(7, 0);
lcd.write(byte(1));
lcd.setCursor(5, 0);
lcd.write(byte(2));
lcd.setCursor(8, 0);
lcd.write(byte(3));
lcd.setCursor(5, 1);
lcd.write(byte(4));
lcd.setCursor(8, 1);
lcd.write(byte(5));
lcd.setCursor(6, 1);
lcd.write(byte(6));
lcd.setCursor(7, 1);
lcd.write(byte(7));
}

void setup() {
lcd.begin(16, 2);
image();
}

void loop() {

}
</code>
</pre>
</div>
</div>
<a href="https://drive.google.com/uc?export=download&id=1HTGlOL18sVCiaY9UD_BBLJdj4WvjcHYd" class="download-button" download>
<span class="material-icons">download</span> Download Code</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">draw</span> LCD Custom Character Generator</h2>
<p>Draw your own custom character using the 5&times;8 pixel grid and generate the Arduino LiquidCrystal code automatically.</p>
<button class="lcd-control-button" onclick="openProject('lcdgen')" style="margin-top:12px;">
<span class="material-icons" style="font-size:1rem;">open_in_new</span> Open LCD Generator</button>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">videocam</span> Project Video
</h2>
<div class="video-container">
<iframe
src="https://www.youtube.com/embed/kPDiamMZOLg"
width="100%"
height="500"
frameborder="0"
allow="autoplay; encrypted-media"
allowfullscreen>
</iframe>
</div>
<p style="text-align: center; margin-top: 15px;">
<a
href="https://www.youtube.com/watch?v=kPDiamMZOLg"
target="_blank"
class="footer-link">
Watch on YouTube
</a>
</p>
</div>
<div class="badge-footer">
<p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 18 July 2025</p>
</div>
</div>
</div>
</div>
<div id="lcdgen" class="project-page">
<div class="container" style="max-width:100%;padding:20px;">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link" style="margin-bottom:16px;display:inline-flex;">
<span class="material-icons">arrow_back</span> Back to Projects</a>
<h1 style="font-family:var(--font-display);color:var(--primary);margin:0 0 20px;font-size:1.3rem;text-align:center;">LCD Custom Character Generator</h1>
<div class="lcd-display" id="lcdDisplay"></div>
<div class="lcd-controls">
<button class="lcd-control-button clear" onclick="lcdClearAll()">Clear LCD</button>
<p class="lcd-help">Click any pixel to draw. Max 8 characters.</p>
</div>
<div style="display:flex;justify-content:flex-end;margin-top:16px;">
<button class="lcd-copy-button" onclick="lcdCopyCode()">Copy Code</button>
</div>
<pre class="lcd-code-box" id="lcdCode">// Draw something on the LCD first.</pre>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p7" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects</a>
<h1 class="project-title">Arduino Mini Piano</h1>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container"><img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787581144/Copy_of_Copy_of_Copy_of_ESP_32_qbxgtq.png" alt="Arduino Mini Piano" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to build a mini piano using Arduino. It includes push buttons for musical notes and a buzzer for sound output.</p>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">lightbulb</span> Project Idea</h2>
<ul>
<li>Build a simple 7-key musical instrument using push buttons and a piezo buzzer</li>
<li>Map each button to one musical note (C through B) so pressing a key plays a distinct tone</li>
<li>Light an LED whenever any key is held down, giving visual feedback alongside the sound</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">warning</span> Challenges</h2>
<ul>
<li>Wiring internal pull-up resistors correctly for all 7 buttons (using <code>pinMode(INPUT)</code> + <code>digitalWrite(HIGH)</code>) instead of needing 7 external pull-down resistors</li>
<li>Each note is checked through a blocking <code>while</code> loop, so only one key registers reliably at a time — true polyphony (multiple notes at once) isn't possible with this design</li>
<li>Keeping the frequency table (T_C…T_B) accurate enough that the notes sound musically correct</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">build</span> Solution Method</h2>
<ol>
<li>Define standard musical note frequencies (262Hz–493Hz) as constants for C through B</li>
<li>Assign each of the 7 push buttons to its own digital pin, configured as INPUT with the internal pull-up resistor enabled</li>
<li>In the main loop, check each button in sequence: while a button reads LOW (pressed), play its note with <code>tone()</code> and light the LED</li>
<li>Once the button is released, the loop for that note exits, and <code>noTone()</code> plus turning off the LED run after the last checked button</li>
<li>Repeat the cycle continuously so any of the 7 keys can be played by pressing and holding its button</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">code</span> Code Explanation</h2>
<ul>
<li><code>#define T_C 262</code> etc. — frequency constants in Hz for each musical note (C4 through B4)</li>
<li><code>pinMode(X, INPUT); digitalWrite(X, HIGH);</code> — configures each button pin as an input with its internal pull-up resistor enabled, so the pin reads HIGH when not pressed and LOW when pressed</li>
<li><code>while(digitalRead(C) == LOW) { tone(Buzz, T_C); digitalWrite(LED, HIGH); }</code> — one such block per note; keeps playing the tone and lighting the LED for as long as that specific button stays pressed</li>
<li><code>noTone(Buzz); digitalWrite(LED, LOW);</code> — stops the buzzer and turns off the LED once none of the 7 buttons are currently pressed</li>
<li><code>loop()</code> — checks all 7 buttons in order every cycle, giving each one a chance to trigger its note</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">rocket_launch</span> Development Ideas</h2>
<ol>
<li>Replace the blocking while loops with non-blocking button checks so multiple keys can be pressed in quick succession without lag</li>
<li>Add an octave-shift button to extend the playable note range beyond one octave</li>
<li>Add a simple "record and playback" mode to store and replay short melodies</li>
<li>Use a piezo speaker with volume control (via PWM) instead of a fixed-tone buzzer</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Components</h2>
<div class="components-grid">
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648778/Arduino_img_board_nobg_zfmod7.png" alt="Arduino" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Arduino</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648800/Puch_button_img_rd532o.png" alt="Push Buttons" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>7 Push Buttons</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648779/buzzer-img_hsg7p3.png" alt="Buzzer" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Buzzer</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648779/Breadboard_img_flkekc.jpg" alt="Breadboard" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Breadboard</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Jumper Wires</h2>
</div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)">
<span class="material-icons">content_copy</span> Copy</button>
<div class="code-block">
<pre>
<code>
#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493

const int C = 10;
const int D = 9;
const int E = 8;
const int F = 7;
const int G = 6;
const int A = 5;
const int B = 4;

const int Buzz = 3;
const int LED = 2;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(C, INPUT);
  digitalWrite(C,HIGH);

  pinMode(D, INPUT);
  digitalWrite(D,HIGH);

  pinMode(E, INPUT);
  digitalWrite(E,HIGH);

  pinMode(F, INPUT);
  digitalWrite(F,HIGH);

  pinMode(G, INPUT);
  digitalWrite(G,HIGH);

  pinMode(A, INPUT);
  digitalWrite(A,HIGH);

  pinMode(B, INPUT);
  digitalWrite(B,HIGH);

   digitalWrite(LED,LOW);
}

void loop()
{
  while(digitalRead(C) == LOW)
  {
    tone(Buzz,T_C);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(D) == LOW)
  {
    tone(Buzz,T_D);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(E) == LOW)
  {
    tone(Buzz,T_E);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(F) == LOW)
  {
    tone(Buzz,T_F);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(G) == LOW)
  {
    tone(Buzz,T_G);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(A) == LOW)
  {
    tone(Buzz,T_A);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(B) == LOW)
  {
    tone(Buzz,T_B);
    digitalWrite(LED,HIGH);
  }

  noTone(Buzz);
  digitalWrite(LED,LOW);

}
</code>
</pre>
</div>
</div>
<a href="https://drive.google.com/uc?export=download&id=1HUd8t8N8kYc6v62s5vEU55cLPLiBREpC" class="download-button" download>
<span class="material-icons">download</span> Download Code</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">videocam</span> Project Video
</h2>
<div class="video-container">
<iframe
src="https://www.youtube.com/embed/uM7lqfCr2po"
width="100%"
height="500"
frameborder="0"
allow="autoplay; encrypted-media"
allowfullscreen>
</iframe>
</div>
<p style="text-align: center; margin-top: 15px;">
<a
href="https://www.youtube.com/watch?v=uM7lqfCr2po"
target="_blank"
class="footer-link">
Watch on YouTube
</a>
</p>
</div>
<div class="badge-footer">
<p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 11 October 2024</p>
</div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p8" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects</a>
<h1 class="project-title">Arduino Calculator</h1>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787749697/Copy_of_Copy_of_Copy_of_Copy_of_ESP_32_swhtyu.png" alt="Arduino Calculator" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to build a calculator using Arduino. It includes a keypad for input, an LCD for displaying results, and logic to perform basic arithmetic operations.</p>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">lightbulb</span> Project Idea</h2>
<p>
Build a simple 4-function calculator using a 4x4 matrix keypad for input and a 16x2 LCD for display.
The user enters a number, presses an operator key (+, -, *, /), enters a second number, then presses "="
to see the result, just like a basic handheld calculator.
</p>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">warning</span> Challenges</h2>
<p>
Reading multi-digit numbers from a keypad requires building up the value digit-by-digit rather than reading
a single keypress, since each digit is entered separately. The calculator also needs to remember the result
of a previous operation so it can be reused as the first number in a follow-up calculation (chained
operations), and division needs a manual check to avoid dividing by zero.
</p>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">build</span> Solution Method</h2>
<ol>
<li>Scan the keypad continuously using the <code>Keypad</code> library and read each key press</li>
<li>While digit keys (0-9) are pressed, build up the first number by multiplying the running total by 10 and adding the new digit</li>
<li>When an operator key (+, -, *, /) is pressed, store the operator and call <code>SecondNumber()</code> to collect the second number the same way</li>
<li>When "=" is pressed inside <code>SecondNumber()</code>, return the collected value and perform the corresponding arithmetic operation</li>
<li>Display the result on the LCD, and reset <code>first</code>/<code>second</code> to zero so the calculator is ready for the next operation (using the previous total if chaining calculations)</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">code</span> Code Explanation</h2>
<ul>
<li><code>customKeypad.getKey()</code> — reads the currently pressed key from the 4x4 matrix keypad, or returns nothing if no key is pressed</li>
<li><code>case '0' ... '9'</code> — builds the first number digit-by-digit as the user types, multiplying the existing value by 10 and adding the new digit</li>
<li><code>case '+' / '-' / '*' / '/'</code> — stores the chosen operator, calls <code>SecondNumber()</code> to collect the second operand, then computes and displays <code>total</code></li>
<li><code>SecondNumber()</code> — loops reading key presses to build the second number until "=" is pressed, then returns the collected value</li>
<li><code>case 'C'</code> — clears the LCD and resets <code>total</code> back to zero</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">rocket_launch</span> Development Ideas</h2>
<ol>
<li>Add support for decimal point input, since the current version only handles whole numbers</li>
<li>Add a backspace/delete key to correct mistyped digits before pressing an operator</li>
<li>Support parentheses and operator precedence for more complex expressions</li>
<li>Add a calculation history that can be scrolled through on the LCD</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">build</span> Components</h2>
<div class="components-grid">
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648778/Arduino_img_board_nobg_zfmod7.png" alt="Arduino" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Arduino</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648794/LCD16x2_img_nlofi0.png" alt="LCD" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>LCD</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648800/Potentiometer_img_aioyzf.png" alt="POT" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Potentiometer 10k</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648792/Keypad_img_p3fpki.png" alt="Keypad" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Keypad 4x4</h2>
</div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy"/>
<div class="component-info">
<h2>Jumper Wires</h2>
</div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787750264/0a640f20-7d8c-40f6-96c6-fe1e63d34584.png"
alt="Arduino Uno Keypad and LCD Connection Diagram"
class="connection-image"
loading="lazy"/>
</div>
<div class="connection-steps">
<div class="connection-step">
<span class="connection-pin">LCD VSS</span> → GND
</div>
<div class="connection-step">
<span class="connection-pin">LCD VDD</span> → 5V
</div>
<div class="connection-step">
<span class="connection-pin">LCD VO</span> → Potentiometer 10K (Middle)
</div>
<div class="connection-step">
<span class="connection-pin">LCD RS</span> → D13
</div>
<div class="connection-step">
<span class="connection-pin">LCD RW</span> → GND
</div>
<div class="connection-step">
<span class="connection-pin">LCD E</span> → D12
</div>
<div class="connection-step">
<span class="connection-pin">LCD D4</span> → D11
</div>
<div class="connection-step">
<span class="connection-pin">LCD D5</span> → D10
</div>
<div class="connection-step">
<span class="connection-pin">LCD D6</span> → D9
</div>
<div class="connection-step">
<span class="connection-pin">LCD D7</span> → D8
</div>
<div class="connection-step">
<span class="connection-pin">LCD A (LED+)</span> → 5V
</div>
<div class="connection-step">
<span class="connection-pin">LCD K (LED-)</span> → GND
</div>
<div class="connection-step">
<span class="connection-pin">Potentiometer 10K</span> → 5V / GND
</div>
<div class="connection-step">
<span class="connection-pin">Keypad Row 1</span> → D7
</div>
<div class="connection-step">
<span class="connection-pin">Keypad Row 2</span> → D6
</div>
<div class="connection-step">
<span class="connection-pin">Keypad Row 3</span> → D5
</div>
<div class="connection-step">
<span class="connection-pin">Keypad Row 4</span> → D4
</div>
<div class="connection-step">
<span class="connection-pin">Keypad Column 1</span> → D3
</div>
<div class="connection-step">
<span class="connection-pin">Keypad Column 2</span> → D2
</div>
<div class="connection-step">
<span class="connection-pin">Keypad Column 3</span> → D1
</div>
<div class="connection-step">
<span class="connection-pin">Keypad Column 4</span> → D0
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)">
<span class="material-icons">content_copy</span> Copy</button>
<div class="code-block">
<pre>
<code>
#include &lt;Servo.h&gt;
#include &lt;Keypad.h&gt;
#include &lt;Wire.h&gt;
#include &lt;LiquidCrystal.h&gt;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

long first = 0;
long second = 0;
double total = 0;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte rowPins[ROWS] = {7,6,5,4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3,2,1,0}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
lcd.begin(16, 2);               // start lcd
for(int i=0;i &lt; =3;i++);
lcd.setCursor(0,0);
  lcd.print("Calculator");
  lcd.setCursor(0,1);
  lcd.print("by David medhat");
delay(4000);
lcd.clear();
lcd.setCursor(0, 0);
}

void loop()
{

  customKey = customKeypad.getKey();
  switch(customKey)
  {
  case '0' ... '9': // This keeps collecting the first value until a operator is pressed "+-*/"
    lcd.setCursor(0,0);
    first = first * 10 + (customKey - '0');
    lcd.print(first);
    break;

  case '+':
    first = (total != 0 ? total : first);
    lcd.setCursor(0,1);
    lcd.print("+");
    second = SecondNumber(); // get the collected the second number
    total = first + second;
    lcd.setCursor(0,3);
    lcd.print(total);
    first = 0, second = 0; // reset values back to zero for next use
    break;

  case '-':
    first = (total != 0 ? total : first);
    lcd.setCursor(0,1);
    lcd.print("-");
    second = SecondNumber();
    total = first - second;
    lcd.setCursor(0,3);
    lcd.print(total);
    first = 0, second = 0;
    break;

  case '*':
    first = (total != 0 ? total : first);
    lcd.setCursor(0,1);
    lcd.print("*");
    second = SecondNumber();
    total = first * second;
    lcd.setCursor(0,3);
    lcd.print(total);
    first = 0, second = 0;
    break;

  case '/':
    first = (total != 0 ? total : first);
    lcd.setCursor(0,1);
    lcd.print("/");
    second = SecondNumber();
    lcd.setCursor(0,3);

    second == 0 ? lcd.print("Invalid") : total = (float)first / (float)second;

    lcd.print(total);
    first = 0, second = 0;
    break;

  case 'C':
    total = 0;
    lcd.clear();
    break;
  }
}

long SecondNumber()
{
  while( 1 )
  {
    customKey = customKeypad.getKey();
    if(customKey >= '0' && customKey <= '9')
    {
      second = second * 10 + (customKey - '0');
      lcd.setCursor(0,2);
      lcd.print(second);
    }

    if(customKey == '=') break;  //return second;
  }
 return second;
}
</code>
</pre>
</div>
</div>
<a href="https://drive.google.com/uc?export=download&id=1FeDT1eTrUBFqCnwjckzoUJJZQR55rH37" class="download-button" download>
<span class="material-icons">download</span> Download Code</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">videocam</span> Project Video
</h2>
<div class="video-container">
<iframe
src="https://www.youtube.com/embed/fhUKN6yvCuw"
width="100%"
height="500"
frameborder="0"
allow="autoplay; encrypted-media"
allowfullscreen>
</iframe>
</div>
<p style="text-align: center; margin-top: 15px;">
<a
href="https://www.youtube.com/watch?v=fhUKN6yvCuw"
target="_blank"
class="footer-link">
Watch on YouTube
</a>
</p>
</div>
<div class="badge-footer">
<p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 22 August 2024</p>
</div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p9" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects
</a>
<h1 class="project-title">Ultrasonic Sensor and LCD Meter</h1>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787817335/Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_ESP_32_xmddd0.png" alt="digital distance meter using Arduino" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to build a digital distance meter using Arduino, an ultrasonic sensor, and an LCD. It continuously measures the distance to nearby objects and displays real-time readings on the screen for easy monitoring.</p>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">lightbulb</span> Project Idea</h2>
<ul>
<li>Build a real-time digital distance meter using an ultrasonic sensor and an Arduino</li>
<li>Continuously display the measured distance on a 16x2 LCD in both centimeters and inches</li>
<li>Provide an easy, low-cost alternative to a physical tape measure for short-range distance checks</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">warning</span> Challenges</h2>
<ul>
<li>The ultrasonic sensor returns a raw pulse duration in microseconds, which has to be manually converted into a real-world distance unit</li>
<li>Displaying two different unit readings (cm and inch) on a small 16x2 screen without the layout overlapping or getting cut off</li>
<li>Getting stable, consistent readings without noticeable flicker or lag on the LCD as the sensor updates rapidly</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">build</span> Solution Method</h2>
<ol>
<li>Trigger the ultrasonic sensor by sending a short 10-microsecond HIGH pulse on the Trig pin</li>
<li>Measure the time it takes for the echo pulse to return using <code>pulseIn()</code> on the Echo pin</li>
<li>Convert the measured duration into centimeters and inches using the speed of sound constants</li>
<li>Print the distance in centimeters on the LCD's first row and the distance in inches on the second row</li>
<li>Repeat the process continuously so the display updates in near real time</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">code</span> Code Explanation</h2>
<ul>
<li><code>trigPin</code> / <code>echoPin</code> — the two pins used to send the ultrasonic pulse and read its reflection back</li>
<li><code>pulseIn(echoPin, HIGH)</code> — measures how long the Echo pin stays HIGH, which represents the round-trip travel time of the sound wave</li>
<li><code>distanceCm = duration * 0.034 / 2</code> — converts the pulse duration into centimeters using the speed of sound, dividing by 2 to account for the round trip</li>
<li><code>distanceInch = duration * 0.0133 / 2</code> — same calculation, using the speed of sound in inches instead of centimeters</li>
<li><code>lcd.setCursor()</code> / <code>lcd.print()</code> — position and print each unit's reading on its own row of the 16x2 LCD</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">rocket_launch</span> Development Ideas</h2>
<ol>
<li>Add a moving-average filter to smooth out noisy or fluctuating sensor readings</li>
<li>Add a buzzer or LED alert that triggers when an object gets closer than a set minimum distance</li>
<li>Log distance readings over time to a computer or SD card for tracking trends</li>
<li>Replace the fixed LCD display with an OLED for a sharper, more compact readout</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">build</span> Components</h2>
<div class="components-grid">
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648778/Arduino_img_board_nobg_zfmod7.png" alt="Arduino" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Arduino</h2></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648794/LCD16x2_img_nlofi0.png" alt="LCD16x2_img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>LCD</h2></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648800/Potentiometer_img_aioyzf.png" alt="Potentiometer_img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Potentiometer</h2></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648808/Ultrasonic_sensore_img_to5ihi.png" alt="Ultrasonic sensore_img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Ultrasonic Sensore</h2></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Jumper Wires</h2></div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1787817327/8c63f390-cc46-4a54-a605-e42b34a131b1.png" alt="Connection Diagram" class="connection-image" loading="lazy"/>
</div>
<div class="connection-steps">
<div class="connection-step"><span class="connection-pin">Ultrasonic VCC</span> → 5V</div>
<div class="connection-step"><span class="connection-pin">Ultrasonic GND</span> → GND</div>
<div class="connection-step"><span class="connection-pin">Ultrasonic Trig</span> → D9</div>
<div class="connection-step"><span class="connection-pin">Ultrasonic Echo</span> → D8</div>
<div class="connection-step"><span class="connection-pin">LCD RS</span> → D12</div>
<div class="connection-step"><span class="connection-pin">LCD E</span> → D11</div>
<div class="connection-step"><span class="connection-pin">LCD D4</span> → D5</div>
<div class="connection-step"><span class="connection-pin">LCD D5</span> → D4</div>
<div class="connection-step"><span class="connection-pin">LCD D6</span> → D3</div>
<div class="connection-step"><span class="connection-pin">LCD D7</span> → D2</div>
<div class="connection-step"><span class="connection-pin">LCD VSS</span> → GND</div>
<div class="connection-step"><span class="connection-pin">LCD VDD</span> → 5V</div>
<div class="connection-step"><span class="connection-pin">LCD A (LED +)</span> → 5V</div>
<div class="connection-step"><span class="connection-pin">LCD K (LED –)</span> → GND</div>
<div class="connection-step"><span class="connection-pin">LCD RW</span> → LCD VSS (GND)</div>
<div class="connection-step"><span class="connection-pin">LCD V0</span> → Potentiometer SIG</div>
<div class="connection-step"><span class="connection-pin">Pot VCC</span> → 5V</div>
<div class="connection-step"><span class="connection-pin">Pot GND</span> → GND</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)"><span class="material-icons">content_copy</span> Copy</button>
<div class="code-block">
<pre><code>
#include &lt;LiquidCrystal.h&gt;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // LCD: (rs, enable, d4, d5, d6, d7)

const int trigPin = 9;
const int echoPin = 8;

long duration;
int distanceCm, distanceInch;

void setup() {
    lcd.begin(16, 2);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    // Trigger the ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the echo time
    duration = pulseIn(echoPin, HIGH);

    // Convert to distance
    distanceCm   = duration * 0.034  / 2;
    distanceInch = duration * 0.0133 / 2;

    // Display on LCD
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distanceCm);
    lcd.print(" cm");

    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distanceInch);
    lcd.print(" inch");

    delay(10);
}
</code></pre>
</div>
</div>
<a href="https://drive.google.com/uc?export=download&id=1EEk2nGSqqP39hstLkSec0ny62NSZ46OM" class="download-button" download>
<span class="material-icons">download</span> Download Code
</a>
</div>
<div class="badge-section">
<h2 class="section-title">
<span class="material-icons">videocam</span> Project Video
</h2>
<div class="video-container">
<iframe
src="https://www.youtube.com/embed/l3pkFKowquo"
width="100%"
height="500"
frameborder="0"
allow="autoplay; encrypted-media"
allowfullscreen>
</iframe>
</div>
<p style="text-align: center; margin-top: 15px;">
<a
href="https://www.youtube.com/watch?v=l3pkFKowquo"
target="_blank"
class="footer-link">
Watch on YouTube
</a>
</p>
</div>
<div class="badge-footer"><p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 30 November 2024</p></div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p10" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects
</a>
<h1 class="project-title">SSD1306 OLED Display & Ultrasonic Sensor</h1>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1788110363/Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_ESP_32_1_umq3bp.png" alt="SSD1306 OLED Display and Ultrasonic Sensore" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to measure distance using an ultrasonic sensor and display the results on an SSD1306 OLED screen with an ESP32 and MicroPython. It includes real-time distance monitoring, visual feedback on the OLED display, and precise readings ideal for object detection or range-based applications.</p>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">lightbulb</span> Project Idea</h2>
<ul>
<li>Continuously measure distance to nearby objects using an ultrasonic sensor on an ESP32</li>
<li>Display the live distance reading in real time on an SSD1306 OLED screen</li>
<li>Show a clear "Out of range" message when no valid echo is detected, instead of a frozen or garbage reading</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">warning</span> Challenges</h2>
<ul>
<li>The ultrasonic sensor's raw echo duration can time out or return invalid values when no object is in range, which has to be handled explicitly instead of just converting it to a (wrong) distance</li>
<li>MicroPython's <code>time_pulse_us()</code> needs a timeout value set manually, or the program can hang waiting for an echo that never returns</li>
<li>The OLED must be fully cleared and redrawn every cycle (<code>oled.fill(0)</code> + <code>oled.show()</code>), otherwise old digits overlap with new ones and the display becomes unreadable</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">build</span> Solution Method</h2>
<ol>
<li>Trigger the ultrasonic sensor with a short 10-microsecond HIGH pulse on the Trig pin</li>
<li>Use <code>time_pulse_us()</code> on the Echo pin with a 30ms timeout to measure the round-trip pulse duration</li>
<li>If the function returns a negative value (timeout), treat it as "no object detected" instead of computing a distance</li>
<li>Otherwise, convert the duration into centimeters using the speed of sound (<code>duration / 2 / 29.1</code>)</li>
<li>Clear the OLED, print either the distance or an out-of-range message, call <code>oled.show()</code>, then repeat after a short delay</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">code</span> Code Explanation</h2>
<ul>
<li><code>get_distance()</code> — fires the trigger pulse, measures the echo duration with <code>time_pulse_us()</code>, and returns the distance in cm or <code>-1</code> on timeout</li>
<li><code>time_pulse_us(echo, 1, 30000)</code> — waits for the Echo pin to go HIGH then LOW, measuring how long it stays HIGH, capped at a 30ms timeout to avoid hanging</li>
<li><code>distance_cm = (duration / 2) / 29.1</code> — standard ultrasonic distance formula, dividing by 2 for the round trip and by the speed of sound in cm/µs</li>
<li><code>oled.fill(0)</code> / <code>oled.text()</code> / <code>oled.show()</code> — clears the previous frame, draws the new text, then pushes the buffer to the physical OLED</li>
<li><code>while True</code> loop — repeats the measure-and-display cycle every 0.5 seconds for continuous, near real-time monitoring</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">rocket_launch</span> Development Ideas</h2>
<ol>
<li>Add a minimum-distance alert (buzzer or LED) when an object gets too close</li>
<li>Smooth the readings with a moving average to reduce flicker from noisy measurements</li>
<li>Add a graphical bar or gauge on the OLED instead of numeric text only</li>
<li>Log readings over time or send them over WiFi for remote monitoring</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">build</span> Components</h2>
<div class="components-grid">
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786119224/c1e24f62-b9e5-45bf-bc2a-8c12266f374f.png" alt="ESP32" class="component-image" loading="lazy"/>
<div class="component-info"><h2>ESP32</h2><p>We will use MicroPython</p></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648808/Ultrasonic_sensore_img_to5ihi.png" alt="Ultrasonic sensore_img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Ultrasonic Sensore</h2></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648798/OLED_img_gfkupk.png" alt="OLED_img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>SSD1306 OLED Display</h2></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Jumper Wires</h2></div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1788113820/f74c61a5-2077-44af-9c25-dabc45ec007f.png" alt="Connection Diagram" class="connection-image" loading="lazy"/>
</div>
<div class="connection-steps">
<div class="connection-step"><span class="connection-pin">Ultrasonic Sensore VCC</span> → 3V3</div>
<div class="connection-step"><span class="connection-pin">Ultrasonic Sensore GND</span> → GND</div>
<div class="connection-step"><span class="connection-pin">Ultrasonic Sensore TRIG</span> → GP19</div>
<div class="connection-step"><span class="connection-pin">Ultrasonic Sensore ECHO</span> → GP18</div>
<div class="connection-step"><span class="connection-pin">Smoke(Gas) Sensore VCC</span> → 3V3</div>
<div class="connection-step"><span class="connection-pin">Smoke(Gas) Sensore GND</span> → GND</div>
<div class="connection-step"><span class="connection-pin">Smoke(Gas) Sensore SCL</span> → GP17</div>
<div class="connection-step"><span class="connection-pin">Smoke(Gas) Sensore SDA</span> → GP5</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)"><span class="material-icons">content_copy</span> Copy</button>
<div class="code-block">
<pre><code>
from machine import Pin, I2C, time_pulse_us
import time
from ssd1306 import SSD1306_I2C  

i2c = I2C(0, scl=Pin(17), sda=Pin(5))
oled = SSD1306_I2C(128, 64, i2c)
oled.fill(0)
oled.show()

trig = Pin(19, Pin.OUT)
echo = Pin(18, Pin.IN)

def get_distance():
    trig.value(0)
    time.sleep_us(2)
    trig.value(1)
    time.sleep_us(10)
    trig.value(0)
    duration = time_pulse_us(echo, 1, 30000)  # Timeout 30 ms
    if duration < 0:
        return -1
    distance_cm = (duration / 2) / 29.1
    time.sleep_ms(60)
    return distance_cm

while True:
    distance = get_distance()
    oled.fill(0)
    if distance == -1:
        oled.text("Out of range", 0, 0)
    else:
        oled.text("Distance:", 0, 0)
        oled.text("{:.2f} cm".format(distance), 0, 10)
    oled.show()
    time.sleep(0.5)
</code></pre>
</div>
</div>
<p>This project requires MicroPython libraries that are included in the Thonny Library Manager. You can download all the necessary files, including the main code ,libraries and the diagram for Wokwi from the direct link below.</p>
<a href="https://drive.google.com/uc?export=download&id=10NT70P8K5PwKyB7Hcg_Nxgikx4D-HoUs" class="download-button" download>
<span class="material-icons">download</span> Download Code with all libraries
</a>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">videocam</span> There is no video for this project yet.</h2>
</div>
<div class="badge-footer"><p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 16 March 2025</p></div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p11" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects
</a>
<h1 class="project-title">ILI9341 TFT Display</h1>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1788184229/Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_ESP_32_omzrne.png" alt="ILI9341_TFT_LCD_Display" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to display custom text using various fonts on an ILI9341 TFT LCD with an ESP32 and MicroPython. It covers initializing the display, loading external font files, and rendering high-quality text output for rich visual interfaces.</p>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">lightbulb</span> Project Idea</h2>
<ul>
  <li>Display custom text on an ILI9341 TFT screen using an ESP32</li>
<li>Support loading external bitmap font files instead of relying on a single built-in font</li>
<li>Achieve smooth, high-quality text rendering suitable for rich visual interfaces</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">warning</span> Challenges</h2>
<ul>
<li>MicroPython has no native driver for the ILI9341 controller, so an external SPI-based display driver is required</li>
<li>Standard fonts only cover fixed sizes, so using a custom style (like the 18x24 Espresso Dolce font) means the font file has to be parsed and mapped to the correct glyph dimensions</li>
<li>SPI pin assignments (CS, RST, D/C, MOSI, SCK) must exactly match the wiring, or the display stays blank or shows corrupted output</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">build</span> Solution Method</h2>
<ol>
  <li>Wire the ILI9341 display to the ESP32 over SPI (CS, RST, D/C, MOSI, SCK, MISO)</li>
<li>Import the community ili9341 driver for MicroPython to handle low-level SPI communication and drawing</li>
<li>Load the custom bitmap font file (Espresso_Dolce18x24.c) with XglcdFont, specifying its glyph width (18px) and height (24px)</li>
<li>Initialize the SPI bus at 20MHz and create the Display object using the connected CS/DC/RST pins</li>
<li>Call display.draw_text() with the target string, font, and color to render the text onto the screen</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">code</span> Code Explanation</h2>
<ul>
<li><code>XglcdFont('Espresso_Dolce18x24.c', 18, 24)</code> — loads the custom bitmap font, specifying each glyph's pixel width and height</li>
<li><code>SPI(1, baudrate=20000000, ...)</code> — configures the SPI bus at 20MHz for fast communication with the display controller</li>
<li><code>Display(spi, cs=cs, dc=dc, rst=rst)</code> — creates the display driver object, tying the SPI bus to the CS/DC/RST control pins</li>
<li><code>display.draw_text(x, y, text, font, color, ...)</code> — renders the given string at position (x, y) using the loaded font and color</li>
<li><code>color565(255, 255, 255)</code> — converts standard RGB values into the 16-bit RGB565 format the display expects</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">rocket_launch</span> Development Ideas</h2>
<ol>
<li>Add support for switching between multiple loaded fonts at runtime</li>
<li>Add scrolling or multi-line text wrapping for strings longer than the screen width</li>
<li>Combine with a touch-enabled ILI9341 module for interactive text input/display</li>
<li>Extend the display to render Arabic text using the connected-letterform technique from the Arabic TFT project</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">build</span> Components</h2>
<div class="components-grid">
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786119224/c1e24f62-b9e5-45bf-bc2a-8c12266f374f.png" alt="ESP32" class="component-image" loading="lazy"/>
<div class="component-info"><h2>ESP32</h2><p>We will use MicroPython</p></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648807/TFT_img_dubem0.png" alt="TFT_img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>TFT ILI9341 display</h2></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Jumper Wires</h2></div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1788184428/65835dfb-ef83-4e85-b46b-d501eb96711b.png" alt="Connection Diagram" class="connection-image" loading="lazy"/>
</div>
<div class="connection-steps">
<div class="connection-step"><span class="connection-pin">TFT VCC</span> → 3V3</div>
<div class="connection-step"><span class="connection-pin">TFT GND</span> → GND</div>
<div class="connection-step"><span class="connection-pin">TFT CS</span> → GP5</div>
<div class="connection-step"><span class="connection-pin">TFT RST</span> → GP17</div>
<div class="connection-step"><span class="connection-pin">TFT D/C</span> → GP16</div>
<div class="connection-step"><span class="connection-pin">TFT MOSI</span> → GP11</div>
<div class="connection-step"><span class="connection-pin">TFT SCK</span> → GP10</div>
<div class="connection-step"><span class="connection-pin">TFT LED</span> → 3V3</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)"><span class="material-icons">content_copy</span> Copy</button>
<div class="code-block">
<pre><code>
from machine import Pin, SPI
from ili9341 import Display, color565
from xglcdfont import XglcdFont 

terminal_font = XglcdFont('Espresso_Dolce18x24.c', 18, 24)
spi = SPI(1, baudrate=20000000, polarity=0, phase=0,
          sck=Pin(16), mosi=Pin(17))
cs = Pin(19, Pin.OUT)
dc = Pin(5, Pin.OUT)
rst = Pin(18, Pin.OUT)

display = Display(spi, cs=cs, dc=dc, rst=rst)


display.draw_text(0,0,"david medhat",terminal_font,color565(255,255,255),0,False,True)
</code></pre>
</div>
</div>
<p>This project requires a font file. You can download all the necessary files, including the main code ,libraries and some defrant fonts and the diagram for Wokwi from the direct link below.</p>
<a href="https://drive.google.com/uc?export=download&id=1EvpTptTO6KMq1IuZQ_Y_9DcP37P9MNrr" class="download-button" download>
<span class="material-icons">download</span> Download Code with all libraries
</a>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">videocam</span> There is no video for this project yet.</h2>
</div>
<div class="badge-footer"><p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 7 June 2025</p></div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<div id="p12" class="project-page">
<div class="container">
<div class="project-badge">
<div class="badge-header">
<a href="javascript:void(0)" onclick="closeProject()" class="home-link">
<span class="material-icons">arrow_back</span> Back to Projects
</a>
<h1 class="project-title">Snake Game</h1>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">image</span> Project Overview</h2>
<div class="project-image-container">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1788273844/Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_Copy_of_ESP_32_amvpgz.png" alt="Snake game" class="project-main-image" loading="lazy"/>
</div>
<p>This project demonstrates how to create a Snake game using a Dot Matrix display and a joystick with ESP32 and MicroPython. It includes snake movement, food collection, and collision detection. The joystick is used to control the snake.</p>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">lightbulb</span> Project Idea</h2>
<ul>
<li>Recreate the classic Snake game on an 8x8 LED dot matrix display, controlled with an analog joystick</li>
<li>Move the snake continuously in the current direction, growing by one segment each time it eats a food pixel</li>
<li>Wrap the snake around the screen edges instead of ending the game when it reaches a border</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">warning</span> Challenges</h2>
<ul>
<li>The 8x8 matrix only gives 64 pixels total, so the snake, food, and empty space all have to be tracked and redrawn every frame without flicker</li>
<li>Reading a joystick's raw analog values (0–65535) and converting them into 4 clean directions requires carefully chosen thresholds</li>
<li>The snake must not be able to reverse directly into itself when the opposite direction is pressed, and food must never spawn on top of a snake segment</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">build</span> Solution Method</h2>
<ol>
<li>Read the joystick's X and Y analog values on every loop iteration and compare them against high/low thresholds to decide the next direction, ignoring any input that would reverse the snake directly into itself</li>
<li>Calculate the new head position by adding the current direction to the head coordinates, using modulo arithmetic on the width and height so the snake wraps around the edges instead of stopping</li>
<li>End the game immediately if the new head position collides with any existing segment of the snake's body</li>
<li>If the new head lands on the food pixel, grow the snake by keeping the tail (skip removing the last segment) and generate a new food position that isn't inside the snake; otherwise, move normally by removing the tail</li>
<li>Clear the display, redraw every snake segment and the food pixel, then repeat the loop with a short delay to control game speed</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">code</span> Code Explanation</h2>
<ul>
<li><code>read_joystick()</code> — reads the ADC values from the joystick's X/Y pins and updates the global <code>direction</code> tuple, blocking any 180° reversal</li>
<li><code>move()</code> — calculates the new head position with wraparound (<code>% WIDTH</code>, <code>% HEIGHT</code>), checks for self-collision, and returns <code>False</code> to end the game if the snake hits itself</li>
<li><code>place_food()</code> — repeatedly generates random coordinates until it finds one that isn't currently occupied by the snake</li>
<li><code>draw()</code> — clears the matrix buffer, lights up a pixel for each snake segment and the food, then pushes the frame to the display with <code>display.show()</code></li>
<li><code>while True</code> loop — ties everything together: reads the joystick, moves the snake, redraws the display, and pauses briefly (<code>sleep(0.2)</code>) each cycle to set the game speed</li>
</ul>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">rocket_launch</span> Development Ideas</h2>
<ol>
<li>Add a score counter and display it once the game ends, instead of only showing "Dead"</li>
<li>Gradually decrease the delay between frames as the snake grows, increasing difficulty over time</li>
<li>Add a "Game Over" restart sequence so a new game starts automatically after a short pause, without needing to reset the board</li>
<li>Replace the wraparound edges with an optional wall-collision mode for a harder difficulty</li>
</ol>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">build</span> Components</h2>
<div class="components-grid">
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1786119224/c1e24f62-b9e5-45bf-bc2a-8c12266f374f.png" alt="ESP32" class="component-image" loading="lazy"/>
<div class="component-info"><h2>ESP32</h2><p>We will use MicroPython</p></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648785/Dot_matrix_img_iffhl9.jpg" alt="Dot_matrix_img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Dot Matrix</h2></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648789/joystick-img_val6e2.png" alt="joystick-img" class="component-image" loading="lazy"/>
<div class="component-info"><h2>joystick</h2></div>
</div>
<div class="component-card">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1781648790/Jumper_Wires_dh5j3b.webp" alt="Jumper Wires" class="component-image" loading="lazy"/>
<div class="component-info"><h2>Jumper Wires</h2></div>
</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">settings_input_component</span> Connections</h2>
<div class="connection-diagram">
<img src="https://res.cloudinary.com/dqyebtw3b/image/upload/v1788273887/76284a9f-248d-4891-b721-51c1c5c7ef22.png" alt="Connection Diagram" class="connection-image" loading="lazy"/>
</div>
<div class="connection-steps">
<div class="connection-step"><span class="connection-pin">Dot Matrix VCC</span> → 3V3</div>
<div class="connection-step"><span class="connection-pin">Dot Matrix GND</span> → GND</div>
<div class="connection-step"><span class="connection-pin">Dot Matrix DIN</span> → GP23</div>
<div class="connection-step"><span class="connection-pin">Dot Matrix CS</span> → GP5</div>
<div class="connection-step"><span class="connection-pin">Dot Matrix CLK</span> → GP18</div>
<div class="connection-step"><span class="connection-pin">joystick VCC</span> → 3V3</div>
<div class="connection-step"><span class="connection-pin">joystick VERT</span> → GP27</div>
<div class="connection-step"><span class="connection-pin">joystick HORZ</span> → GP26</div>
<div class="connection-step"><span class="connection-pin">joystick GND</span> → GND</div>
</div>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">code</span> Source Code</h2>
<div class="code-block-container">
<button class="copy-button" onclick="copyCode(this)"><span class="material-icons">content_copy</span> Copy</button>
<div class="code-block">
<pre><code>
from machine import Pin, ADC, SPI
from max7219 import Matrix8x8
from time import sleep
import random

spi = SPI(2, baudrate=10000000, polarity=0, phase=0, sck=Pin(18), mosi=Pin(23))

cs = Pin(5, Pin.OUT)

display = Matrix8x8(spi, cs, 1)
display.brightness(1)

WIDTH = 8
HEIGHT = 8

vrx = ADC(Pin(26))
vry = ADC(Pin(27))

vrx.atten(ADC.ATTN_11DB)
vry.atten(ADC.ATTN_11DB)

snake = [(4, 4), (3, 4), (2, 4)]
direction = (1, 0)

food = (random.randint(0, WIDTH - 1), random.randint(0, HEIGHT - 1))

def place_food():
    global food

    while True:
        new_food = (
            random.randint(0, WIDTH - 1),
            random.randint(0, HEIGHT - 1)
        )

        if new_food not in snake:
            food = new_food
            break

def draw():
    display.fill(0)

    for segment in snake:
        display.pixel(segment[0], segment[1], 1)

    display.pixel(food[0], food[1], 1)

    display.show()

def read_joystick():
    global direction

    x_val = vrx.read_u16()
    y_val = vry.read_u16()

    if x_val &lt; 20000 and direction != (1, 0):
        direction = (-1, 0)

    elif x_val &gt; 45000 and direction != (-1, 0):
        direction = (1, 0)

    elif y_val &lt; 20000 and direction != (0, -1):
        direction = (0, 1)

    elif y_val &gt; 45000 and direction != (0, 1):
        direction = (0, -1)

def move():
    head_x = (snake[0][0] + direction[0]) % WIDTH
    head_y = (snake[0][1] + direction[1]) % HEIGHT

    new_head = (head_x, head_y)

    if new_head in snake:
        return False

    snake.insert(0, new_head)

    if new_head == food:
        place_food()
    else:
        snake.pop()

    return True

while True:
    read_joystick()

    if not move():
        break

    draw()

    sleep(0.2)

display.fill(0)
display.text("Dead", 0, 0, 1)
display.show()
</code></pre>
</div>
</div>
<p>This project requires an custom MicroPython library (max7219.py). You can download all the necessary files, including the main code, required libraries, and the Wokwi wiring diagram from the direct link below.</p>
<a href="https://drive.google.com/uc?export=download&id=1OYhrD8eCsIE1syEQhqU83YYnAeOGo30n" class="download-button" download>
<span class="material-icons">download</span> Download Code with all libraries
</a>
</div>
<div class="badge-section">
<h2 class="section-title"><span class="material-icons">videocam</span> There is no video for this project yet.</h2>
</div>
<div class="badge-footer"><p>&copy; 2024 David Medhat. All rights reserved.</p>
<p class="upload-date">Uploaded on 20 September 2025</p></div>
</div>
</div>
</div>
<!-------------------------------------------------------------------------------------------------------------------------------->
<!-- ===== FEEDBACK BUTTON ===== -->
<button id="feedback-btn"><span class="material-icons">rate_review</span> Feedback</button>

<div id="modal" class="modal-overlay">
<div class="modal-box">
<h3>Send Feedback</h3>
<form action="https://formsubmit.co/david.9152010@gmail.com" method="POST">
<input type="hidden" name="_captcha" value="false" />
<input type="hidden" name="_template" value="table" />
<input type="hidden" name="_next" value="https://davidtechlab.blogspot.com/" />
<div class="form-group">
<label>Your Name (optional)</label>
<input type="text" name="Name" id="fb-modal-name" placeholder="Your name" />
</div>
<div class="form-group">
<label>Your Email (optional)</label>
<input type="email" name="Email" id="fb-modal-email" placeholder="Your email" />
</div>
<label>How satisfied are you? *</label>
<input type="hidden" name="Rating" id="rating-input" />
<div class="stars" id="star-container">
<span data-value="1">★</span>
<span data-value="2">★</span>
<span data-value="3">★</span>
<span data-value="4">★</span>
<span data-value="5">★</span>
</div>
<label>Explain in more detail *</label>
<textarea name="Message" required></textarea>
<div class="modal-actions">
<button type="button" class="cancel-btn" id="close-modal">Cancel</button>
<button type="submit" class="submit-btn">Submit</button>
</div>
</form>
</div>
</div>

<script>
// Theme toggle
const themeToggle = document.getElementById('themeToggle');
const themeIcon = document.getElementById('themeIcon');
const html = document.documentElement;
const savedTheme = localStorage.getItem('theme') || 'dark';
html.setAttribute('data-theme', savedTheme);
themeIcon.textContent = savedTheme === 'dark' ? 'dark_mode' : 'light_mode';
themeToggle.addEventListener('click', () => {
  const current = html.getAttribute('data-theme');
  const next = current === 'dark' ? 'light' : 'dark';
  html.setAttribute('data-theme', next);
  localStorage.setItem('theme', next);
  themeIcon.textContent = next === 'dark' ? 'dark_mode' : 'light_mode';
});

// Search
const searchInput = document.getElementById('searchInput');
const projectCards = document.querySelectorAll('.project-card');
const emptyState = document.getElementById('emptyState');
searchInput.addEventListener('input', () => {
  const query = searchInput.value.toLowerCase();
  let visible = 0;
  projectCards.forEach(card => {
    const title = card.querySelector('.title')?.textContent?.toLowerCase() || '';
    const tech = card.querySelector('.tech')?.textContent?.toLowerCase() || '';
    const match = title.includes(query) || tech.includes(query);
    card.style.display = match ? '' : 'none';
    if (match) visible++;
  });
  emptyState.style.display = visible === 0 ? 'block' : 'none';
});

// Filter
function filterProjects(filter) {
  document.querySelectorAll('.button-link').forEach(btn => btn.classList.remove('active'));
  document.querySelector(`[data-filter="${filter}"]`).classList.add('active');
  projectCards.forEach(card => {
    if (filter === 'all') { card.style.display = ''; return; }
    card.style.display = card.getAttribute('data-category') === filter ? '' : 'none';
  });
}

// Scroll reveal
const revealObserver = new IntersectionObserver((entries) => {
  entries.forEach(entry => {
    if (entry.isIntersecting) { entry.target.classList.add('visible'); revealObserver.unobserve(entry.target); }
  });
}, { threshold: 0.1, rootMargin: '0px 0px -50px 0px' });
document.querySelectorAll('.reveal').forEach(el => revealObserver.observe(el));

// Project overlay functions
function openProject(id) {
  document.querySelectorAll('.project-page').forEach(p => p.style.display = 'none');
  const page = document.getElementById(id);
  if (page) { page.style.display = 'block'; page.scrollTop = 0; }
  document.body.style.overflow = 'hidden';
  document.documentElement.style.overflow = 'hidden';
}
function closeProject() {
  document.querySelectorAll('.project-page').forEach(p => p.style.display = 'none');
  document.body.style.overflow = '';
  document.documentElement.style.overflow = '';
}
function copyCode(btn) {
  const code = btn.closest('.code-block-container').querySelector('code').textContent.trim();
  navigator.clipboard.writeText(code).then(() => {
    btn.innerHTML = '<span class="material-icons">check</span> Copied!';
    setTimeout(() => { btn.innerHTML = '<span class="material-icons">content_copy</span> Copy'; }, 2000);
  });
}
document.addEventListener('keydown', e => { if (e.key === 'Escape') closeProject(); });

// Auto-open a specific project from URL query param (?project=pX)
(function () {
  const params = new URLSearchParams(window.location.search);
  const target = params.get('project');
  if (target && document.getElementById(target)) {
    openProject(target);
  }
})();

// Feedback modal
const modal = document.getElementById('modal');
const fbBtn = document.getElementById('feedback-btn');
const closeBtn = document.getElementById('close-modal');
const stars = document.querySelectorAll('#star-container span');
const ratingInput = document.getElementById('rating-input');
fbBtn.onclick = () => modal.style.display = 'flex';
closeBtn.onclick = () => modal.style.display = 'none';
modal.addEventListener('click', e => { if (e.target === modal) modal.style.display = 'none'; });
stars.forEach(star => {
  star.addEventListener('click', () => {
    const val = star.getAttribute('data-value');
    ratingInput.value = val;
    stars.forEach((s, i) => s.classList.toggle('selected', i < val));
  });
});

// Skeleton loader: hide shimmer on image load
function skeletonLoaded(el) {
  const parent = el.closest('.project-image-container, .connection-diagram, .component-card');
  if (parent) parent.classList.add('loaded');
}
document.querySelectorAll('.project-image-container img, .connection-diagram img, .component-card img').forEach(img => {
  if (img.complete) skeletonLoaded(img);
  else img.addEventListener('load', () => skeletonLoaded(img));
});

/* ===== LCD CUSTOM CHARACTER GENERATOR ===== */
const LCD_ROWS = 2;
const LCD_COLS = 16;
const LCD_PIXEL_ROWS = 8;
const LCD_PIXEL_COLS = 5;
let lcdData = [];
let lcdPixelEls = [];

function lcdInitGenerator() {
  const display = document.getElementById("lcdDisplay");
  if (!display) return;
  display.innerHTML = "";
  lcdData = [];
  lcdPixelEls = [];

  for (let row = 0; row < LCD_ROWS; row++) {
    for (let col = 0; col < LCD_COLS; col++) {
      let cellIdx = row * LCD_COLS + col;
      let rowData = [];
      let rowEls = [];
      const cell = document.createElement("div");
      cell.className = "lcd-cell";

      for (let y = 0; y < LCD_PIXEL_ROWS; y++) {
        let colData = [];
        let colEls = [];
        for (let x = 0; x < LCD_PIXEL_COLS; x++) {
          colData.push(false);
          const pixel = document.createElement("div");
          pixel.className = "lcd-pixel";
          pixel.addEventListener("click", function () {
            if (!colData[x]) {
              let hasPixels = false;
              for (let py = 0; py < LCD_PIXEL_ROWS && !hasPixels; py++) {
                for (let px = 0; px < LCD_PIXEL_COLS && !hasPixels; px++) {
                  if (lcdData[cellIdx][py][px]) hasPixels = true;
                }
              }
              if (!hasPixels) {
                let drawnCount = 0;
                for (let c = 0; c < LCD_ROWS * LCD_COLS; c++) {
                  let cellHas = false;
                  for (let py = 0; py < LCD_PIXEL_ROWS && !cellHas; py++) {
                    for (let px = 0; px < LCD_PIXEL_COLS && !cellHas; px++) {
                      if (lcdData[c][py][px]) cellHas = true;
                    }
                  }
                  if (cellHas) drawnCount++;
                }
                if (drawnCount >= 8) return;
              }
            }
            colData[x] = !colData[x];
            pixel.classList.toggle("on");
            lcdUpdateCode();
          });
          colEls.push(pixel);
          cell.appendChild(pixel);
        }
        rowData.push(colData);
        rowEls.push(colEls);
      }
      lcdData.push(rowData);
      lcdPixelEls.push(rowEls);
      display.appendChild(cell);
    }
  }
  lcdUpdateCode();
}

function lcdClearAll() {
  for (let i = 0; i < lcdData.length; i++) {
    for (let y = 0; y < LCD_PIXEL_ROWS; y++) {
      for (let x = 0; x < LCD_PIXEL_COLS; x++) {
        lcdData[i][y][x] = false;
        lcdPixelEls[i][y][x].classList.remove("on");
      }
    }
  }
  lcdUpdateCode();
}

function lcdUpdateCode() {
  const codeElement = document.getElementById("lcdCode");
  if (!codeElement) return;

  let drawnCells = [];

  for (let cell = 0; cell < LCD_ROWS * LCD_COLS; cell++) {
    let isEmpty = true;
    for (let y = 0; y < LCD_PIXEL_ROWS && isEmpty; y++) {
      for (let x = 0; x < LCD_PIXEL_COLS && isEmpty; x++) {
        if (lcdData[cell][y][x]) isEmpty = false;
      }
    }
    if (isEmpty) continue;

    let bytes = [];
    for (let y = 0; y < LCD_PIXEL_ROWS; y++) {
      let b = "";
      for (let x = 0; x < LCD_PIXEL_COLS; x++) b += lcdData[cell][y][x] ? "1" : "0";
      bytes.push(b);
    }
    drawnCells.push({ cell: cell, bytes: bytes });
  }

  if (drawnCells.length === 0) {
    codeElement.textContent = "// Draw something on the LCD first.";
    return;
  }

  let count = Math.min(drawnCells.length, 8);

  let code = "#include <LiquidCrystal.h>\n\n";
  code += "// RS, E, D4, D5, D6, D7\n";
  code += "LiquidCrystal lcd(12, 11, 5, 4, 3, 2);\n\n";
  code += "void image() {\n";
  code += "lcd.clear();\n\n";

  for (let i = 0; i < count; i++) {
    let pos = drawnCells[i].cell + 1;
    code += "byte image" + String(pos).padStart(2, "0") + "[8] = {";
    code += drawnCells[i].bytes.map(function(b) { return "B" + b; }).join(", ");
    code += "};\n";
  }

  code += "\n";
  for (let i = 0; i < count; i++) {
    code += "lcd.createChar(" + i + ", image" + String(drawnCells[i].cell + 1).padStart(2, "0") + ");\n";
  }

  code += "\n";
  for (let i = 0; i < count; i++) {
    let col = drawnCells[i].cell % LCD_COLS;
    let row = Math.floor(drawnCells[i].cell / LCD_COLS);
    code += "lcd.setCursor(" + col + ", " + row + ");\n";
    code += "lcd.write(byte(" + i + "));\n";
  }

  code += "}\n\n";
  code += "void setup() {\n\n";
  code += "lcd.begin(16, 2);\n";
  code += "image();\n\n";
  code += "}\n\n";
  code += "void loop() {\n\n";
  code += "}";
  codeElement.textContent = code;
}

function lcdCopyCode() {
  const codeElement = document.getElementById("lcdCode");
  if (!codeElement) return;
  navigator.clipboard.writeText(codeElement.textContent).then(function () {
    const button = document.querySelector(".lcd-copy-button");
    if (!button) return;
    const oldText = button.textContent;
    button.textContent = "Copied!";
    setTimeout(function () { button.textContent = oldText; }, 1500);
  });
}

if (document.readyState === "loading") {
  document.addEventListener("DOMContentLoaded", lcdInitGenerator);
} else {
  lcdInitGenerator();
}
</script>
</body>
</html>
