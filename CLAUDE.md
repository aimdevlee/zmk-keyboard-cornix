# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

ZMK firmware configuration for the **Cornix split keyboard** - a Corne-inspired 3×6 column-staggered ergonomic keyboard with adjustable tenting. Uses nRF52840 (Ebyte E73 module) with Bluetooth split communication.

## Build Commands

### Local Development (requires Nix or manual ZMK setup)

```bash
# Initialize west workspace (first time only)
just init

# Update dependencies
just update

# Build specific target (use artifact-name from build.yaml)
just build cornix_left
just build cornix_right
just build cornix_dongle

# Build all targets
just build all

# List available build targets
just list

# Clean build artifacts
just clean
```

### Build Outputs
- Firmware: `firmware/<artifact-name>.uf2`
- Build cache: `.build/`

### GitHub Actions (Recommended for Most Users)
Push to `config/` or `boards/` directories triggers automatic builds. Download `.uf2` files from Actions artifacts.

## Architecture

### Board Variants
| Board | Purpose |
|-------|---------|
| `cornix_left` | Left half (standalone, no dongle) |
| `cornix_right` | Right half (peripheral) |
| `cornix_ph_left` | Left half for dongle setup |

### Shields (Optional Add-ons)
| Shield | Purpose |
|--------|---------|
| `cornix_dongle_adapter` | Matrix + BLE for dongles |
| `cornix_dongle_eyelash` | Display overlay for dongle |
| `cornix_indicator` | RGB LED status (high power) |

### Key Directories
```
boards/jzf/cornix/     # Hardware definitions (DTS, Kconfig, pinctrl)
boards/shields/        # Optional shield modules
config/                # User keymaps and ZMK configuration
  ├── cornix.keymap    # Main 52-key layout
  ├── cornix42.keymap  # 42-key variant
  ├── west.yml         # Dependency manifest
  └── includes/        # Helper macros (cornix54.h)
```

### Device Tree Structure
- `cornix.dtsi` - Common base (nRF52840, kscan matrix)
- `cornix_left_common.dtsi` - Left GPIO mapping + SPI (RGB)
- `cornix-layouts.dtsi` - Physical layouts (50-key, 42-key)
- `cornix-pinctrl.dtsi` - Pin control configurations
- `cornix_sensors.dtsi` - EC11 encoder definitions

## ZMK-Specific Notes

### Flash Layout
All boards use **no-SoftDevice (nosd)** layout by default. The `nrf52840-nosd` snippet is applied automatically.

### Snippets Used
- `nrf52840-nosd` - Removes SoftDevice requirement (default for all)
- `studio-rpc-usb-uart` - Enables ZMK Studio support

### Dependencies (west.yml)
- `zmk` - Core ZMK firmware
- `zmk-helpers` (urob) - Timeless homerow mods utilities
- `zmk-dongle-display` - Display widgets for dongles

### Keymap Features
- 8 layers: BASE, WIN, LOWER, RAISE, ADJUST, NAVI, NUM, DEBUG
- Homerow mods with timeless configuration
- EC11 encoder support (volume, page navigation)
- Key position macros in `config/includes/cornix54.h`

## Flashing

1. Double-tap reset to enter UF2 bootloader
2. Drag `.uf2` file to mounted drive
3. For split: flash both halves, then reset simultaneously

### Recovery
If dongle/board becomes unresponsive:
- Flash `bootloader/s140_6.1.1_restore_no_mbr.uf2` first
- Or use `settings_reset` shield to clear stored settings
