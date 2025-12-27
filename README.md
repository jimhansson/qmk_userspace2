# QMK Tangentbordskonfiguration

En anpassad QMK-konfiguration optimerad för svenska tangentbord med fokus på ergonomi och effektivitet.

## Tangentbord som stöds

- **CRKBD (Corne)** - 3x6+3 split keyboard
- **ErgoDox EZ** - Ergonomiskt split keyboard

## Viktiga funktioner

### 🎯 Ergonomiska förbättringar
- **Homerow modifiers via combos**: D+F (vänster ctrl), J+K (höger ctrl), S+D (alt), K+L (alt)
- **Space Cadet Shift**: SC_LSPO/SC_RSPC för shift + parenteser (perfekt för Lisp/paredit)

### ⌨️ Lager (Layers)
- **_BASE**: Standard QWERTY-layout med svenska tecken
- **_SYM**: Symboler och numerisk keypad
- **_NAV**: Navigation, mus-kontroller och clipboard-funktioner
- **_CFG**: Konfigurationsinställningar (autoshift, combos, case modes)
- **_FUN**: Funktionstangenter (F1-F24)

### 🔄 Case Modes
Avancerad texthantering med automatisk case-konvertering:

- **Caps Word**: Automatisk versalisering av ord
  - Aktiveras med `CAS_TOG` eller Leader + CAP
  - Stöder svenska tecken (Å, Ä, Ö)
  - Avslutas automatiskt vid mellanslag eller specialtecken

- **XCase**: Dynamisk case-konvertering med anpassningsbara avgränsare
  - **Leader + X**: Aktivera xcase (nästa tangent blir avgränsare)
  - **Leader + U**: snake_case med underscore (_)
  - **Leader + Z**: path/case med slash (/)
  - **Leader + ,**: comma,separated,values
  - **Leader + .**: dot.separated.values
  - **Leader + V**: backslash\separated\values
  - **Leader + D**: SCREAMING_SNAKE_CASE (xcase + caps word)

### 🎮 Combos
Homerow modifiers utan att lämna hemraden:

```
Vänster hand:
- S+D → Alt (oneshot modifier)
- D+F → Ctrl (oneshot modifier)
- W+E → Delete
- X+C → (reserverad för framtida användning)

Höger hand:
- J+K → Ctrl (oneshot modifier)
- K+L → Alt (oneshot modifier)
- I+O → Insert
```

### 🎯 Leader Key funktioner
Aktiveras med QK_LEAD, följt av sekvens:

**Case modes:**
- **U**: snake_case med underscore
- **Z**: path/case med slash
- **,**: comma,separated,values
- **.**: dot.separated.values
- **V**: backslash\separated\values
- **X**: Aktivera xcase (välj egen avgränsare)
- **D**: SCREAMING_SNAKE_CASE

**System:**
- **AS**: Toggle autoshift
- **CAP**: Caps lock
- **NUM**: Num lock
- **SCRL**: Scroll lock
- **ESC**: Escape key
- **F**: Oneshot function layer

**Konfiguration:**
- **CONF**: Aktivera konfigurationslager
- **BOOT**: Reset till bootloader
- **RESET**: Reset tangentbord

### 🎭 Tap Dance
Dubbla funktioner på samma tangent:

- **QUOT_TD**: ' vid tryck, " vid dubbeltryck
- **AT_TD**: @ vid tryck, ~ vid dubbeltryck  
- **QUES_TD**: ? vid tryck, ! vid dubbeltryck
- **AMP_TD**: & vid tryck, ^ vid dubbeltryck
- **REP_TD**: Repeat key vid tryck, Alt-repeat vid dubbeltryck

### 🖱️ Mus och Navigation
Komplett mus- och navigationskontroll på NAV-lagret:

**Musrörelser:**
- Rörelser i alla riktningar
- Vertikal och horisontell scrollning
- Vänster/höger/mittenklick

**Navigation:**
- **Vim-stil**: HJKL för pilknappar
- **Page navigation**: PgUp, PgDn, Home, End
- **Smart layout**: Logisk placering för snabb åtkomst

### 📋 Clipboard funktioner
Dedikerade knappar för vanliga operationer:
- **Cut** (Ctrl+X)
- **Copy** (Ctrl+C) 
- **Paste** (Ctrl+V)
- **Undo** (Ctrl+Z)
- **Redo** (Ctrl+Y)

### 🔧 Smart Alt-Tab
Förbättrad fönsterväxling med automatisk timer:

- **ALT_TAB**: Framåt genom fönster
- **TLA_TAB**: Bakåt genom fönster (Tab + Left + Alt)
- Automatisk release av Alt efter 1 sekund inaktivitet
- Håller Alt nedtryckt under snabb växling

### 🎮 Gaming Mode
Speciell funktion för gaming:
- **GAME_ON**: Inaktiverar autoshift, combos och key overrides
- Förhindrar oavsiktliga aktiveringar under spel

## Tekniska detaljer

### Layout-makron
Modulära definitioner för enkel anpassning:

```c
// QWERTY-rader
___5QWERTY_1_L___    // Q W E R T
___6QWERTY_1_R___    // Y U I O P Å
___5QWERTY_2_L___    // A S D F G  
___6QWERTY_2_R___    // H J K L Ö Ä
___5QWERTY_3_L___    // Z X C V B
___5QWERTY_3_R___    // N M , . -

// Numerisk keypad
___3NUM_1/2/3___     // 7 8 9 / 4 5 6 / 1 2 3

// Symboler (gamla svenska layouten)
___5SYM_OLD_1/2/3___ // * { } % | / < ( ) > $ / / [ ] \ #

// Navigation
___4NAV_MY_1/2___    // PgUp Home Up End / PgDn Left Down Right
___4MOUSE_MY_1/2___  // WheelUp MouseUp / WheelDown MouseLeft MouseDown MouseRight

// Funktionstangenter
___6FUNCTI_1/2_L/R___ // F1-F6 / F7-F12 / F13-F18 / F19-F24
```

### Homerow Modifiers
```c
#define HRML(k1,k2,k3,k4)  LCTL_T(k1), LALT_T(k2), LGUI_T(k3), LSFT_T(k4)
#define HRMR(k1,k2,k3,k4)  RSFT_T(k1), RGUI_T(k2), RALT_T(k3), RCTL_T(k4)
```

## Installation och byggning

### Förutsättningar (Fedora)
```bash
# ARM och AVR utvecklingsverktyg
sudo dnf install arm-none-eabi-binutils-cs arm-none-eabi-gcc-cs arm-none-eabi-gcc-cs-c++ arm-none-eabi-newlib
sudo dnf install avr-binutils avr-gcc avr-gcc-c++ avr-libc avrdude

# Övriga verktyg
sudo dnf install clang dfu-programmer dfu-util hidapi kernel-devel wget

# För Wally (grafisk flasher)
sudo dnf install gtk3 webkit2gtk3 libusb

# HID bootloader CLI
sudo dnf copr enable erovia/hid-bootloader-cli
sudo dnf install hid-bootloader-cli
```

### Bygga firmware
```bash
# Navigera till QMK-katalogen
cd qmk_firmware

# För CRKBD
make crkbd:jimhansson

# För ErgoDox EZ  
make ergodox_ez:jimhansson

# Med verbose output
make crkbd:jimhansson VERBOSE=1
```

### Flashing
```bash
# Med QMK CLI
qmk flash -kb crkbd -km jimhansson

# Med make
make crkbd:jimhansson:flash

# Manuellt med verktyg
# Wally (GUI) - rekommenderas för nybörjare
# hid-bootloader-cli för HID bootloaders
# teensy_loader_cli för Teensy-baserade tangentbord
```

## Filstruktur

```
├── crkbd/
│   ├── keymap.c          # CRKBD-specifik layout
│   ├── config.h          # CRKBD-konfiguration  
│   └── rules.mk          # CRKBD build-regler
├── ergodox_ez/
│   ├── keymap.c          # ErgoDox EZ layout
│   └── rules.mk          # ErgoDox build-regler
└── user/
    ├── jimhansson.h      # Huvuddefinitioner och makron
    ├── jimhansson.c      # Huvudlogik och process_record_user
    ├── casemodes.h/c     # Case mode funktionalitet
    ├── combos.c          # Combo-definitioner
    ├── leaders.c         # Leader key funktioner
    ├── tap_dance.c       # Tap dance definitioner
    ├── config.h          # Användarspecifik konfiguration
    └── rules.mk          # Användarspecifika build-regler
```


## Anpassning

### Ändra combos
Redigera `user/combos.c` för att lägga till eller modifiera combos:
```c
const uint16_t PROGMEM my_combo[] = {SE_KEY1, SE_KEY2, COMBO_END};
// Lägg till i key_combos array
COMBO(my_combo, KC_FUNCTION),
```

### Lägg till leader-funktioner  
Utöka `user/leaders.c` med nya sekvenser:
```c
if(leader_sequence_two_keys(SE_KEY1, SE_KEY2)) {
    // Din funktion här
}
```

### Justera case modes
Konfigurera beteende i `user/casemodes.c`:
- Ändra `terminate_case_modes()` för att anpassa när modes avslutas
- Modifiera `use_default_xcase_separator()` för automatisk avgränsare

## Felsökning

### Vanliga problem
- **Combos fungerar inte**: Kontrollera COMBO_TERM i config.h
- **Case modes aktiveras inte**: Verifiera att LEADER_ENABLE är aktiverat
- **Tap dance fungerar inte**: Kontrollera TAP_DANCE_ENABLE i rules.mk

### Debug-tips
```bash
# Aktivera debug-output
make crkbd:jimhansson CONSOLE_ENABLE=yes

# Använd QMK Toolbox för att se debug-meddelanden
```


