# Kravdokument: Enhetlig Editor-layout för QMK

## 1. Syfte och mål

### Primär editor
- **Emacs** - huvudeditor som andra anpassar sig efter
- Emacs-tangentbindningar används som bas för mappningar

### Målsättning
- Enhetliga tangentkommandon för vanliga utvecklingsuppgifter
- Minska kognitiv belastning vid växling mellan editorer
- Bibehålla muskelminne för kritiska funktioner

### Scope
- **Emacs** (primär)
- **Vim/Neovim** (sekundär)
- **VS Code** (sekundär)

## 2. Funktionella krav

### Hög prioritet (MVP)
- **Kommandorad/Command palette**
  - Emacs: `M-x`
  - Vim: `:`
  - VS Code: `Ctrl+Shift+P`
- **Sök i fil**
  - Emacs: `C-s` (isearch)
  - Vim: `/`
  - VS Code: `Ctrl+F`
- **Hoppa till definition**
  - Emacs: `M-.` (xref-find-definitions)
  - Vim: `gd` eller `Ctrl+]`
  - VS Code: `F12`
- **Kommentera/avkommentera**
  - Emacs: `M-;` (comment-dwim)
  - Vim: `gc` (med plugin)
  - VS Code: `Ctrl+/`
- **Build/Compile**
  - Emacs: `M-x compile` eller `C-c C-c`
  - Vim: `:make`
  - VS Code: `Ctrl+Shift+B`
- **Fönsterhantering**
  - **Dela horisontellt**
    - Emacs: `C-x 2` (split-window-below)
    - Vim: `:split` eller `C-w s`
    - VS Code: `Ctrl+\` (split editor)
    - *Förslag leader*: `Leader + H`
  - **Dela vertikalt**
    - Emacs: `C-x 3` (split-window-right)
    - Vim: `:vsplit` eller `C-w v`
    - VS Code: `Ctrl+Shift+\` (split editor orthogonal)
    - *Förslag leader*: `Leader + V`
  - **Växla mellan paneler**
    - Emacs: `C-x o` (other-window)
    - Vim: `C-w w` eller `C-w h/j/k/l`
    - VS Code: `Ctrl+1/2/3` eller `Ctrl+K Ctrl+←/→`
    - *Förslag leader*: `Leader + O`
  - **Stäng fönster/buffer**
    - Emacs: `C-x 0` (delete-window) eller `C-x k` (kill-buffer)
    - Vim: `:q` eller `C-w c`
    - VS Code: `Ctrl+W` (close editor)
    - *Förslag leader*: `Leader + Q`
  - **Maximera panel**
    - Emacs: `C-x 1` (delete-other-windows)
    - Vim: `C-w o` eller `:only`
    - VS Code: `Ctrl+K Z` (zen mode) eller `Ctrl+Shift+Enter` (maximize)
    - *Förslag leader*: `Leader + M`

### Medel prioritet
- **Sök i projekt**
  - Emacs: `C-c p s` (projectile) eller `M-x rgrep`
  - Vim: `:grep` eller plugin
  - VS Code: `Ctrl+Shift+F`
- **Navigera filer/buffers**
  - Emacs: `C-x b` (switch-to-buffer), `C-x C-f` (find-file)
  - Vim: `:b`, `:e`
  - VS Code: `Ctrl+P`, `Ctrl+Tab`
- **Duplicera/ta bort rad**
  - Duplicera rad
  - Ta bort hela rad
- **Undo/Redo**
  - Standardiserad undo/redo över editorer

### Låg prioritet (framtida utbyggnad)
- **Debug funktioner**
  - Sätt breakpoint
  - Starta/stoppa debug
- **Terminal toggle**
  - Visa/dölj terminal
- **Formatera kod**
  - Formatera aktuell fil
  - Formatera markering

## 3. Tekniska krav

### Implementation
- **Metod**: Leader key-sekvenser (förslag)
  - Bygger på befintlig leader key-infrastruktur
  - Intuitivt för Emacs-användare
- **Detektering**: Manuell växling eller applikationsspecifik
  - Undersök möjlighet att detektera aktiv applikation
  - Fallback: manuell växling mellan editor-modes

### Tangentmappning
- **Leader prefix**: `QK_LEAD` följt av editor-specifik sekvens
- **Namngivning**: Logiska förkortningar baserade på Emacs-terminologi
- **Konflikthantering**: Undvik kollision med befintliga leader-sekvenser

## 4. Användarupplevelse

### Designprinciper
- **Konsistens**: Samma tangenttryck → samma funktion
- **Intuitivitet**: Baserat på Emacs-konventioner
- **Effektivitet**: Minimera antal tangenttryck
- **Felhantering**: Tydlig feedback vid fel

### Utbildning
- Dokumentation av mappningar i README
- Kommentarer i kod för förståelse
- Exempel på vanliga arbetsflöden

## 5. Framtida utbyggnad

### Potentiella tillägg
- **Fler editorer**: IntelliJ IDEA, Sublime Text
- **Språkspecifika funktioner**: LSP-kommandon
- **Git-integration**: Vanliga git-operationer
- **Projekthantering**: Bygg, test, deploy

### Underhåll
- Regelbunden uppdatering när editorer ändras
- Testning av funktionalitet
- Användarfeedback och iterationer

## 6. Acceptanskriterier

### Definition of Done
- [ ] Alla hög-prioritet funktioner implementerade
- [ ] Fungerar i alla tre editorer
- [ ] Dokumenterat i README
- [ ] Testat i praktisk användning
- [ ] Inga konflikter med befintliga tangentbindningar

### Testscenarier
- [ ] Växla mellan editorer och utför samma uppgift
- [ ] Verifiera att muskelminne fungerar
- [ ] Kontrollera att inga befintliga funktioner påverkas

---

*Dokument skapat: 2025-12-27*  
*Status: Utkast - under utveckling*
