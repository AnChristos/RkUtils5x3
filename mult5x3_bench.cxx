#include "benchmark/benchmark.h"
#include "mult5x3.h"
#include <cstring>

ATH_ENABLE_VECTORIZATION;
static void
mult5x3_bench(benchmark::State& state)
{
  constexpr double P[40] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0,
                             1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0,
                             2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0,
                             3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0 };

  constexpr double Ax[3] = { 1e-2, 2e-2, 3e-2 };
  double Jac[5] = {};
  for (auto _ : state) {
    const int n = state.range(0);
    for (int i = 0; i < n; ++i) {
      M5x3(Jac, Ax, P);
      benchmark::DoNotOptimize(Jac);
      benchmark::ClobberMemory();
    }
  }
}
BENCHMARK(mult5x3_bench)->RangeMultiplier(2)->Range(1024, 8192);

static void
mult5x3Vec_bench(benchmark::State& state)
{
  constexpr double P[40] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0,
                             1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0,
                             2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0,
                             3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0 };

  constexpr double Ax[3] = { 1e-2, 2e-2, 3e-2 };
  double Jac[5] = {};
  for (auto _ : state) {
    const int n = state.range(0);
    for (int i = 0; i < n; ++i) {
      M5x3Vec(Jac, Ax, &P[7]);
      benchmark::DoNotOptimize(Jac);
      benchmark::ClobberMemory();
    }
  }
}
BENCHMARK(mult5x3Vec_bench)->RangeMultiplier(2)->Range(1024, 8192);

static void
mult5x3Vec1_bench(benchmark::State& state)
{
  constexpr double P[40] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0,
                             1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0,
                             2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0,
                             3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0 };

  constexpr double Ax[3] = { 1e-2, 2e-2, 3e-2 };
  double Jac[5] = {};
  for (auto _ : state) {
    const int n = state.range(0);
    for (int i = 0; i < n; ++i) {
      M5x3Vec1(Jac, Ax, &P[7], &P[14], &P[21], &P[28], &P[35]);
      benchmark::DoNotOptimize(Jac);
      benchmark::ClobberMemory();
    }
  }
}
BENCHMARK(mult5x3Vec1_bench)->RangeMultiplier(2)->Range(1024, 8192);




BENCHMARK_MAIN();
