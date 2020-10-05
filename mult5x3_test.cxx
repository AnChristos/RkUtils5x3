#include "mult5x3.h"
#include <iostream>

int
main()
{
  constexpr double P[40] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0,
                             1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0,
                             2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0,
                             3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0 };

  constexpr double Ax[3] = { 1e-2, 2e-2, 3e-2 };
  double Jac[5] = {};
  M5x3Vec(Jac, Ax, &P[7]);
  for (int i = 0; i < 5; ++i) {
    std::cout << Jac[i] << '\n';
  }
  std::cout << '\n';
  M5x3(Jac, Ax, P);
  for (int i = 0; i < 5; ++i) {
    std::cout << Jac[i] << '\n';
  }
  std::cout << '\n';
  M5x3Vec1(Jac, Ax, &P[7], &P[14], &P[21], &P[28], &P[35]);
  for (int i = 0; i < 5; ++i) {
    std::cout << Jac[i] << '\n';
  }
  std::cout << '\n';
  M5x3Eigen(Jac, Ax, P);
  for (int i = 0; i < 5; ++i) {
    std::cout << Jac[i] << '\n';
  }


  return 0;
}

