#ifndef MULT3X5_H
#define MULT3X5_H
#include "vec.h"

inline void
M5x3(double* __restrict__ Jac,
     const double* __restrict__ Ax,
     const double* __restrict__ P)
{
  Jac[0] = Ax[0] * P[7] + Ax[1] * P[8] + Ax[2] * P[9];
  Jac[1] = Ax[0] * P[14] + Ax[1] * P[15] + Ax[2] * P[16];
  Jac[2] = Ax[0] * P[21] + Ax[1] * P[22] + Ax[2] * P[23];
  Jac[3] = Ax[0] * P[28] + Ax[1] * P[29] + Ax[2] * P[30];
  Jac[4] = Ax[0] * P[35] + Ax[1] * P[36] + Ax[2] * P[37];
}

inline void
M5x3Vec(double* __restrict__ Jac,
        const double* __restrict__ Ax,
        const double* __restrict__ P)
{
  using vec4 = CxxUtils::vec<double, 4>;

  vec4 Axv1{};
  CxxUtils::vbroadcast(Axv1, Ax[0]);
  vec4 Axv2{};
  CxxUtils::vbroadcast(Axv2, Ax[1]);
  vec4 Axv3{};
  CxxUtils::vbroadcast(Axv3, Ax[2]);
  vec4 Pv1 = { P[0] ,P[7], P[14],P[21]};
  vec4 Pv2 = { P[1] ,P[8], P[15],P[22]};
  vec4 Pv3 = { P[2], P[9], P[16],P[23]};
  // The other 4
  vec4 res = Pv1 * Axv1 + Pv2 * Axv2 + Pv3 * Axv3;
  CxxUtils::vstore(&Jac[0], res);
  Jac[4] = Ax[0] * P[28] + Ax[1] * P[29] + Ax[2] * P[30];
}

#endif
