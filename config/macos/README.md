# macOS language switching (Karabiner-Elements)

The Cornix keymap's language keys (left outer pinky: Japanese / English /
Korean) send stateless trigger chords, and Karabiner-Elements turns each
chord into an **absolute** input-source selection. This is more reliable
than cycling (Ctrl+Space) because every key always lands on the right
language regardless of the current source.

| Key (left outer pinky) | Keyboard sends | Karabiner selects | Keyboard layer |
|---|---|---|---|
| top    (pos 0)  | Ctrl+Alt+3 | Japanese (Hiragana) | BASE (Colemak-DH) |
| middle (pos 12) | Ctrl+Alt+1 | English (ABC)       | BASE (Colemak-DH) |
| bottom (pos 24) | Ctrl+Alt+2 | Korean (2-Set)      | EXTRA (QWERTY) |

## Setup

1. Install [Karabiner-Elements](https://karabiner-elements.pqrs.org/).
2. Add all three input sources in **System Settings → Keyboard → Input
   Sources**: English (ABC), Korean (2-Set), Japanese.
3. Copy `karabiner-language-switch.json` into Karabiner's complex
   modifications folder:

   ```sh
   cp config/macos/karabiner-language-switch.json \
     ~/.config/karabiner/assets/complex_modifications/
   ```

4. In Karabiner-Elements → **Complex Modifications → Add rule**, enable all
   three "Cornix language switch" rules.

## Verifying / fixing the input_source_id

The `input_source_id` values in the JSON match a default macOS setup. If a
language doesn't switch, your identifier differs. Find the real one:

```sh
# Switch to the target language manually, then run:
defaults read ~/Library/Preferences/com.apple.HIToolbox.plist AppleSelectedInputSources
```

Look for the `KeyboardLayout Name` / `Input Mode` entry and update the
matching `input_source_id` regex in the JSON. Common values:

- English: `com.apple.keylayout.ABC`
- Korean 2-Set: `com.apple.inputmethod.Korean.2SetKorean`
- Japanese Hiragana: `com.apple.inputmethod.Japanese` (or `...Japanese.Hiragana`)

## Changing the trigger chords

If Ctrl+Alt+1/2/3 collides with an app shortcut, change both sides
together:

- Keyboard: `config/miryoku/miryoku_combos.dtsi` (the `&kp LC(LA(Nx))`
  bindings)
- Karabiner: the `from.key_code` / `modifiers` in this JSON

A rarely-used alternative is adding `command` to the mandatory modifiers
(Ctrl+Alt+Cmd+1/2/3).
