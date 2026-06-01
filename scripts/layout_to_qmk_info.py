#!/usr/bin/env python3
"""Convert the Cornix ZMK physical-layout into a QMK-style info.json.

keymap-drawer needs key geometry to render an SVG. The Cornix board isn't in
the QMK keyboard database, but the firmware already describes every key's
position in `boards/jzf/cornix/cornix-layouts.dtsi` via a `zmk,physical-layout`
node (`&key_physical_attrs w h x y rot rx ry`, units of 1/100 key).

This script extracts those attributes and emits the QMK `info.json` shape that
`keymap draw -j` understands, so the drawer uses the *real* board geometry
instead of a hand-written ortho_layout.

Usage:
    python3 scripts/layout_to_qmk_info.py \
        boards/jzf/cornix/cornix-layouts.dtsi > cornix-info.json
"""

import json
import re
import sys

# &key_physical_attrs  w  h  x  y  rot  rx  ry
# Values may be negative and wrapped in parentheses, e.g. (-2300).
_ATTR_RE = re.compile(
    r"key_physical_attrs\s+"
    r"\(?(-?\d+)\)?\s+"  # w
    r"\(?(-?\d+)\)?\s+"  # h
    r"\(?(-?\d+)\)?\s+"  # x
    r"\(?(-?\d+)\)?\s+"  # y
    r"\(?(-?\d+)\)?\s+"  # rot (1/100 degree)
    r"\(?(-?\d+)\)?\s+"  # rx
    r"\(?(-?\d+)\)?"  # ry
)


def parse_layout(dts_text: str) -> list[dict]:
    # Only look inside the keys = <...>; block to avoid matching anything else.
    keys_block = dts_text.split("keys", 1)[1]
    keys = []
    for w, h, x, y, rot, rx, ry in _ATTR_RE.findall(keys_block):
        key = {
            "x": int(x) / 100,
            "y": int(y) / 100,
            "w": int(w) / 100,
            "h": int(h) / 100,
        }
        rotation = int(rot) / 100
        if rotation:
            key["r"] = rotation
            key["rx"] = int(rx) / 100
            key["ry"] = int(ry) / 100
        keys.append(key)
    return keys


def main() -> None:
    if len(sys.argv) != 2:
        sys.exit(f"usage: {sys.argv[0]} <cornix-layouts.dtsi>")
    keys = parse_layout(open(sys.argv[1]).read())
    if not keys:
        sys.exit("error: no key_physical_attrs found")
    info = {
        "keyboard_name": "cornix",
        "layouts": {"LAYOUT": {"layout": keys}},
    }
    json.dump(info, sys.stdout, indent=2)
    print()
    print(f"parsed {len(keys)} keys", file=sys.stderr)


if __name__ == "__main__":
    main()
