#include <mathops/transcedentals.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_InvSqrt(benchmark::State &state)
    {
        for (auto _ : state)
        {
            float res = mathops::fast_invsqrt(9.8);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Sqrt(benchmark::State &state)
    {
        for (auto _ : state)
        {
            float res = mathops::fast_sqrt(9.8);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_InvSqrt);
    BENCHMARK(BM_Sqrt);
}
}