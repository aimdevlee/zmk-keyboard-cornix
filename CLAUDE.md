# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

ZMK firmware for **Cornix** - a 50-key split ergonomic keyboard (3×6 + 3 thumb per side) with Miryoku layout support. Uses Nordic nRF52840 MCU (E73-2G4M08S1C module).

## Build Commands

All build commands use **Just** (task runner):

```bash
just init          # Initialize west environment (first time setup)
just update        # Update ZMK dependencies
just build <expr>  # Build firmware matching expression
just list          # List all available build targets
just clean         # Clear build artifacts
just draw <kb>     # Generate keymap SVG visualization
```

### Common Build Targets

```bash
just build cornix_left              # Left half (standalone)
just build cornix_right             # Right half
just build cornix_left_for_dongle   # Left half for dongle setup
just build cornix_dongle            # Central dongle with display
just build reset                    # Settings reset firmware
just build all                      # Build everything
```

Output firmware: `firmware/*.uf2`

## Architecture

```
config/
├── cornix.keymap           # Entry point - includes Miryoku
├── west.yml                # ZMK dependencies (zmk, urob/zmk-helpers)
└── miryoku/
    ├── custom_config.h     # Layout selection (Colemak-DH vs QWERTY)
    ├── mapping/cornix.h    # 50-key → 36-key Miryoku position mapping
    ├── miryoku.dtsi        # Main keymap generator
    ├── miryoku_behaviors.dtsi  # Hold-tap definitions (HRM)
    ├── miryoku_combos.dtsi     # Language switching combos
    └── miryoku_babel/          # Layer definitions

boards/
├── arm/cornix/             # Board definitions (MCU, pins, matrix)
└── shields/
    ├── cornix_dongle_adapter/   # Dongle matrix + BT config
    └── cornix_dongle_eyelash/   # Display overlay for dongle
```

## Key Concepts

### Miryoku Layout Mapping

Cornix has 50 physical keys but uses 36-key Miryoku. Outer pinky columns are disabled via `mapping/cornix.h`:

```
Active positions (36 keys):
     1   2   3   4   5  |  6   7   8   9  10
    13  14  15  16  17  | 18  19  20  21  22
    25  26  27  28  29  | 32  33  34  35  36
          41  42  43    | 44  45  46
```

### Layers (10 total)

| Layer | Purpose |
|-------|---------|
| BASE (0) | Colemak-DH + Home Row Mods |
| EXTRA (1) | QWERTY (for Korean IME) |
| NAV (4) | Arrow keys, editing |
| MOUSE (5) | Cursor movement |
| NUM (7) | Numpad |
| SYM (8) | Symbols |
| FUN (9) | Function keys |

### Language Combos (`miryoku_combos.dtsi`)

```
R+S (pos 14+15) → English + BASE (Colemak-DH)
E+I (pos 20+21) → Korean + EXTRA (QWERTY)
N+E (pos 19+20) → Japanese + BASE (Colemak-DH)
```

Uses `require-prior-idle-ms` to prevent accidental triggering during fast typing.

### Home Row Mods Timing (`miryoku_behaviors.dtsi`)

```
tapping-term-ms = 200
require-prior-idle-ms = 150
flavor = "tap-preferred"
quick-tap-ms = 200
```

## Important Notes

- **SoftDevice**: Board uses `nrf52840-nosd` snippet (no SoftDevice). Original RMK firmware removed it. Don't revert without understanding flash layout.
- **Split Pairing**: Reset both halves simultaneously for pairing.
- **Dongle Variants**: Multiple dongle shields exist (eyelash, xiao, generic). Check `build.yaml` for your target.
- **RGB LEDs**: Experimental via `cornix_indicator` shield. High power consumption.

## Configuration Patterns

Change default layout in `custom_config.h`:
```c
// Uncomment for QWERTY base
// #define MIRYOKU_ALPHAS_QWERTY
```

Adjust timing in `miryoku.h`:
```c
#define U_TAPPING_TERM 200  // ms
```

Add combos in `miryoku_combos.dtsi` with appropriate `timeout-ms` and `require-prior-idle-ms`.
