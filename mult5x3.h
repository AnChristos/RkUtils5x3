#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#if defined(__GNUC__) && !defined(__clang__) && !defined(__ICC) &&             \
  !defined(__COVERITY__) && !defined(__CUDACC__)
#define ATH_ENABLE_VECTORIZATION                                               \
  _Pragma("GCC optimize (\"tree-vectorize\")") class                           \
    ATH_ENABLE_VECTORIZATION_SWALLOW_SEMICOLON
#else
#define ATH_ENABLE_VECTORIZATION                                               \
  class ATH_ENABLE_VECTORIZATION_SWALLOW_SEMICOLON
#endif

void
M5x3(double* __restrict__ Jac,
     const double* __restrict__ Ax,
     const double* __restrict__ P);

void
M5x3Vec(double* __restrict__ Jac,
        const double* __restrict__ Ax,
        const double* __restrict__ P);

void
M5x3Eigen(double* __restrict__ Jac,
          const double* __restrict__ Ax,
          const double* __restrict__ P);
#endif
