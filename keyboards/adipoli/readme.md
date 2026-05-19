# adipoli

Custom **split ergonomic keyboard** with two independent halves. Each half uses a **Pro Micro** (ATmega32u4), **COL2ROW** diodes, and a **3×7** matrix (five alpha keys per row plus two thumb keys).

Firmware is maintained in [Roshanjossey/qmk_firmware](https://github.com/Roshanjossey/qmk_firmware) on the `adipoli` branch.

## Hardware

| | |
|---|---|
| **Controller** | Pro Micro (8 MHz / 16 MHz ATmega32u4) |
| **Matrix** | 3 rows × 7 columns per half |
| **Diodes** | COL2ROW |
| **Features** | Bootmagic, NKRO, mouse keys, extra keys |
| **Maintainer** | [Roshanjossey](https://github.com/Roshanjossey) |

### Matrix pins (both halves)

| | Pins |
|---|------|
| **Columns** | `D0`, `D4`, `C6`, `D7`, `E6`, `B4`, `B5` |
| **Rows** | `B1`, `B3`, `B2` |

USB IDs (default QMK test values): `VID=0xFEED`, `PID=0x0000`.

## Layout

Each half is a 3×7 matrix (five alpha keys + two inner thumb keys per row). Together the inner keys form a **3×3 thumb cluster** between the halves. Same PCB both sides; firmware differs (`left` / `right`).

### Layer 0 — base (QWERTY split)

```
┌───┬───┬───┬───┬───┬───────┬───────────┐
│ Q │ W │ E │ R │ T │ Esc   │ Backspace │
├───┼───┼───┼───┼───┼───────┼───────────┤
│ A │ S │ D │ F │ G │ Enter │ →         │
├───┼───┼───┼───┼───┼───────┼───────────┤
│ Z │ X │ C │ V │ B │ Space │ TO(1)     │
└───┴───┴───┴───┴───┴───────┴───────────┘
```

**Right half (layer 0)** — QWERTY right + modifier thumbs:

```
┌───────┬───────┬───┬───┬───┬───┬───┐
│ ↑     │ Tab   │ Y │ U │ I │ O │ P │
├───────┼───────┼───┼───┼───┼───┼───┤
│ BOOT  │ Shift │ H │ J │ K │ L │ ; │
├───────┼───────┼───┼───┼───┼───┼───┤
│ TO(1) │ Ctrl  │ N │ M │ , │ . │ / │
└───────┴───────┴───┴───┴───┴───┴───┘
```

(`BOOT` = `QK_BOOTLOADER` on layer 0, row 2 left thumb on the right half.)

### Layers

Both halves use **3 layers** (`TO(n)` on the bottom-right thumb of layer 0 cycles left; right half uses `TO(1)` / `MO(2)` on layer 1).

| Layer | Left | Right |
|-------|------|-------|
| **0** | QWERTY (Q–T), Esc/Bspc, Enter/→, Space → layer 1 | QWERTY (Y–P), arrows/Tab/Shift, Super/Ctrl, → layer 1 |
| **1** | Numbers 1–5, same thumb cluster | 6–0 and symbol keys, `MO(2)` on last thumb |
| **2** | F1–F5, bootloader on Enter thumb | F1–F5, bootloader on second thumb row |

Layer definitions: `keymaps/left/keymap.c`, `keymaps/right/keymap.c`.

## Build and flash

From the repository root (after [setting up the build tools](https://docs.qmk.fm/#/getting_started_build_tools)):

```bash
# Compile
qmk compile -kb adipoli -km left
qmk compile -kb adipoli -km right

# Flash (half must be in bootloader)
qmk flash -kb adipoli -km left
qmk flash -kb adipoli -km right
```

```bash
make adipoli:left:flash
make adipoli:right:flash
```

Flash **each half** with its own keymap. There is no combined “whole keyboard” image—each Pro Micro runs its own firmware.

## Bootloader

Enter the bootloader on a half:

1. **Bootmagic** — Hold the top-left matrix key (matrix position `0,0`, usually **Q** on the left / **↑** on the right) while plugging in USB.
2. **Keycode** — Right half layer 0: hold **QK_BOOTLOADER** (left thumb on the middle row). Layers 1–2 and left layer 2 also map bootloader on thumb keys. See `keymaps/*/keymap.c`.
3. **Reset button** — Short the Pro Micro reset pads or press the reset button, if fitted.

Then run `qmk flash` for that half.

## Keymaps

| Keymap | Use |
|--------|-----|
| `left` | Left half (includes `keymap_german.h` for future DE layout work) |
| `right` | Right half |

## New to QMK?

Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs), then the [make guide](https://docs.qmk.fm/#/getting_started_make_guide).
