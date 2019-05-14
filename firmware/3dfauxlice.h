#ifndef _3DFAUXLICE_H
#define _3DFAUXLICE_H

#define ___ KC_NO

#define LAYOUT( \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, \
    K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, \
    K41,      K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E, \
    K51, K52,      K54,      K56,      K58,      K5A,      K5C, K5D, K5E \
) { \
  { K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E }, \
  { K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E }, \
  { K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E }, \
  { K41, ___, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D, K4E }, \
  { K51, K52, ___, K54, ___, K56, ___, K58, ___, K5A, ___, K5C, K5D, K5E } \
}

#endif
