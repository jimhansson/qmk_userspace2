# Planck Rev. 6 (eller din specifika revision)
BOOTLOADER = atmel-dfu
MCU = atmega32u4

# Aktivera funktioner
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
LEADER_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
MOUSEKEY_ENABLE = yes

# Planck-specifika inställningar
SRC += jimhansson.c
SRC += casemodes.c
SRC += combos.c
SRC += leaders.c
SRC += tap_dance.c
