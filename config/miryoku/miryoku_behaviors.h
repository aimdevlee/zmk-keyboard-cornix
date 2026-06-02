// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#pragma once

#define U_MT(MOD, TAP) &u_mt MOD TAP
#define U_MT_SHIFT(MOD, TAP) &u_mt_shift MOD TAP
#define U_LT(LAYER, TAP) &u_lt LAYER TAP

// Positional (cross-hand) home-row mods. Use the *_L variant on the left
// hand and the *_R variant on the right hand so each only triggers its
// modifier when the opposite hand presses a key.
#define U_HML(MOD, TAP) &u_hml MOD TAP
#define U_HMR(MOD, TAP) &u_hmr MOD TAP
#define U_HML_SHIFT(MOD, TAP) &u_hml_shift MOD TAP
#define U_HMR_SHIFT(MOD, TAP) &u_hmr_shift MOD TAP
