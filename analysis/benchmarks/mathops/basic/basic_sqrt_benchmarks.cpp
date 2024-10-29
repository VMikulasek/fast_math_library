#include <mathops/transcedentals.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_InvSqrt(benchmark::State &state)
    {
        volatile float num = 90913408134.8;

        for (auto _ : state)
        {
            float res = mathops::invsqrt(num);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Sqrt(benchmark::State &state)
    {
        volatile float num = 90913408134.8;

        for (auto _ : state)
        {
            float res = mathops::sqrt(num);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_InvSqrt);
    BENCHMARK(BM_Sqrt);
}
}