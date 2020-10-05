#include "mult5x3.h"
#include "vec.h"
#include <Eigen/Core>
#include <Eigen/Dense>
ATH_ENABLE_VECTORIZATION;

void
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

void
M5x3Vec(double* __restrict__ Jac,
        const double* __restrict__ Ax,
        const double* __restrict__ P)
{
  using vec2 = CxxUtils::vec<double, 2>;
  vec2 Axv1 {} ;
  CxxUtils::vbroadcast(Axv1,Ax[0]);
  vec2 Axv2 {} ;
  CxxUtils::vbroadcast(Axv2,Ax[1]);
  vec2 Axv3 {} ;
  CxxUtils::vbroadcast(Axv3,Ax[2]);

  vec2 Pv11 = { P[0], P[7] };
  vec2 Pv12 = { P[1], P[8] };
  vec2 Pv13 = { P[2], P[11] };
  vec2 Pv21 = { P[14], P[21] };
  vec2 Pv22 = { P[15], P[22] };
  vec2 Pv23 = { P[16], P[23] };

  // 1st and 2nd element
  vec2 res1 = Pv11 * Axv1 + Pv12 * Axv2 + Pv13 * Axv3;
  // 3th and 4th element
  vec2 res2 = Pv21 * Axv2 + Pv22 * Axv2 + Pv23 * Axv3;
  CxxUtils::vstore(&Jac[0], res1);
  CxxUtils::vstore(&Jac[2], res2);
  // The 5th element
  Jac[4] = Ax[0] * P[28] + Ax[1] * P[29] + Ax[2] * P[30];
}

void
M5x3Vec1(double* __restrict__ Jac,
         const double* __restrict__ Ax,
         const double* __restrict__ P1,
         const double* __restrict__ P2,
         const double* __restrict__ P3,
         const double* __restrict__ P4,
         const double* __restrict__ P5)
{
  using vec2 = CxxUtils::vec<double, 2>;

  vec2 Axv{ Ax[0], Ax[1] };
  vec2 P1v{ P1[0], P1[1] };
  vec2 P2v{ P2[0], P2[1] };
  vec2 P3v{ P3[0], P3[1] };
  vec2 P4v{ P4[0], P4[1] };
  vec2 P5v{ P5[0], P5[1] };
  vec2 part1 = P1v * Axv;
  vec2 part2 = P2v * Axv;
  vec2 part3 = P3v * Axv;
  vec2 part4 = P4v * Axv;
  vec2 part5 = P5v * Axv;

  Jac[0] = part1[0] + part1[1] + Ax[2] * P1[2];
  Jac[1] = part2[0] + part2[1] + Ax[2] * P2[2];
  Jac[2] = part3[0] + part3[1] + Ax[2] * P3[2];
  Jac[3] = part4[0] + part4[1] + Ax[2] * P4[2];
  Jac[4] = part5[0] + part5[1] + Ax[2] * P5[2];
}

void
M5x3Eigen(double* __restrict__ Jac,
          const double* __restrict__ Ax,
          const double* __restrict__ P)
{
  Eigen::Map<Eigen::Matrix<double, 5, 1>> JacMap(&Jac[0], 5, 1);
  Eigen::Map<const Eigen::Matrix<double, 1, 3>> AxMap(&Ax[0], 1, 3);
  Eigen::Map<const Eigen::Matrix<double, 3, 5>, 0, Eigen::OuterStride<>> Pmap(
    &P[7], Eigen::OuterStride<>(7));
  JacMap = AxMap * Pmap;
}

