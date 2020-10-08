#include "benchmark/benchmark.h"
#include "mult5x3.h"
#include <random>
#include <algorithm>
/*
 * A bit hacky way to create random inputs
 */
double P[40];
double Ax[3];
class InitArray
{
public:
  InitArray()
  {
    std::mt19937 gen;
    std::uniform_real_distribution<> dis(1.0, 10.0);
    for (size_t i = 0; i < 40; ++i) {
      P[i] = dis(gen);
    }
    for (size_t i = 0; i < 3; ++i) {
      Ax[i] = dis(gen);
    }
  }
};
InitArray initArray;

static void
mult5x3_bench(benchmark::State& state)
{
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

BENCHMARK_MAIN();
