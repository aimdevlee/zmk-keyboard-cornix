// Copyright 2024 Miryoku for Cornix
// https://github.com/manna-harbour/miryoku

// Alphas layout: Colemak-DH (default, no need to define)
// Use QWERTY for the base layer.
#define MIRYOKU_ALPHAS_QWERTY

// Miryoku's built-in QWERTY base uses SQT on the right home-row pinky.
// Use SEMI here to match a standard QWERTY home row.
#define MIRYOKU_LAYER_BASE_QWERTY_SEMI \
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,             \
U_MT(LCTRL, A),    U_MT(LALT, S),     U_MT(LGUI, D),    U_MT_SHIFT(LSHFT, F),    &kp G,             &kp H,             U_MT_SHIFT(LSHFT, J),    U_MT(LGUI, K),      U_MT(LALT, L),     U_MT(LCTRL, SEMI),  \
U_LT(U_BUTTON, Z), U_MT(RALT, X),     &kp C,             &kp V,             &kp B,             &kp N,             &kp M,             &kp COMMA,         U_MT(RALT, DOT),   U_LT(U_BUTTON, SLASH),\
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),U_LT(U_NAV, SPACE),U_LT(U_MOUSE, TAB),U_LT(U_SYM, RET),  U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_BASE MIRYOKU_LAYER_BASE_QWERTY_SEMI

// VI-style navigation (HJKL)
// #define MIRYOKU_NAV_VI

// Optional: Uncomment to enable combos
// #define MIRYOKU_KLUDGE_THUMBCOMBOS
// #define MIRYOKU_KLUDGE_TOPROWCOMBOS
// #define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS

// macOS clipboard shortcuts (Cmd+C/V/X/Z instead of Ctrl)
#define MIRYOKU_CLIPBOARD_MAC
