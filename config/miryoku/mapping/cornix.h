// Copyright 2024 Miryoku for Cornix
// https://github.com/manna-harbour/miryoku
// Cornix keyboard mapping for Miryoku layout

/*
  Cornix 50-key matrix layout (from cornix54.h):

  ╭────────────────────────╮               ╭────────────────────────╮
  │  0   1   2   3   4   5 │               │  6   7   8   9  10  11 │
  │ 12  13  14  15  16  17 ╰──╮         ╭──╯ 18  19  20  21  22  23 │
  │ 24  25  26  27  28  29  30╰────┬────╯31  32  33  34  35  36  37 │
  │ 38  39  40      41  42  43     │     44  45  46      47  48  49 │
  ╰────────────────────────────────┴────────────────────────────────╯

  Miryoku uses 36 keys (3x5 + 3 thumbs per side):
  - 30 alpha keys (3 rows × 5 columns × 2 sides)
  - 6 thumb keys (3 per side)

  Cornix keys to disable (outer pinky columns + palm keys):
  - Left outer pinky: 0, 12, 24
  - Right outer pinky: 11, 23, 37
  - Palm keys: 38, 39, 40, 47, 48, 49

  Active Miryoku mapping:
  - Left hand:  1-5, 13-17, 25-29(+30), thumbs 41-43
  - Right hand: 6-10, 18-22, 31-36, thumbs 44-46
*/

#if !defined (MIRYOKU_LAYOUTMAPPING_CORNIX)

#define XXX &none

// Miryoku 40-key logical layout:
//      K00  K01  K02  K03  K04       K05  K06  K07  K08  K09
//      K10  K11  K12  K13  K14       K15  K16  K17  K18  K19
//      K20  K21  K22  K23  K24       K25  K26  K27  K28  K29
//      N30  N31  K32  K33  K34       K35  K36  K37  N38  N39
//
// N** = unused in Miryoku (outer thumb keys)

#define MIRYOKU_LAYOUTMAPPING_CORNIX( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
XXX  K00  K01  K02  K03  K04       K05  K06  K07  K08  K09  XXX  \
XXX  K10  K11  K12  K13  K14       K15  K16  K17  K18  K19  XXX  \
XXX  K20  K21  K22  K23  K24  XXX  XXX  K25  K26  K27  K28  K29  XXX  \
XXX  XXX  XXX  K32  K33  K34       K35  K36  K37  XXX  XXX  XXX

// Combo positions for Cornix (if using kludge combos)
// Top row combo positions (adjusted for Cornix matrix - shifted by 1 due to disabled outer pinky)
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_LEFTPINKIE 1 2
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_LEFTINNERINDEX 4 5
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_RIGHTINNERINDEX 6 7
#define MIRYOKU_KLUDGE_TOPROWCOMBOS_RIGHTPINKIE 9 10

// Bottom row combo positions
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_LEFTPINKIE 25 26
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_LEFTINNERINDEX 28 29
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_RIGHTINNERINDEX 32 33
#define MIRYOKU_KLUDGE_BOTTOMROWCOMBOS_RIGHTPINKIE 35 36

// Thumb combo positions
#define MIRYOKU_KLUDGE_THUMBCOMBOS_LEFT 42 43
#define MIRYOKU_KLUDGE_THUMBCOMBOS_RIGHT 44 45

#endif

#define MIRYOKU_MAPPING MIRYOKU_LAYOUTMAPPING_CORNIX
