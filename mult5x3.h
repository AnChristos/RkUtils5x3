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
        const double* __restrict__ V,
        const double* __restrict__ P)
{
  using vec2 = CxxUtils::vec<double, 2>;
  
  // 1st/2nd element
  vec2 P1v1 = { P[0], P[7] };
  vec2 P1v2 = { P[1], P[8] };
  vec2 P1v3 = { P[2], P[9] };
  vec2 res1 = V[0] * P1v1 + V[1] * P1v2 + V[2] * P1v3;
  CxxUtils::vstore(&Jac[0], res1);
  
  // 3th/4th element
  vec2 P2v1 = { P[14], P[21] };
  vec2 P2v2 = { P[15], P[22] };
  vec2 P2v3 = { P[16], P[23] };
  vec2 res2 = V[0] * P2v1 + V[1] * P2v2 + V[2] * P2v3;

  //store results
  CxxUtils::vstore(&Jac[2], res2);
  // The 5th element
  Jac[4] = V[0] * P[28] + V[1] * P[29] + V[2] * P[30];

}

#endif
