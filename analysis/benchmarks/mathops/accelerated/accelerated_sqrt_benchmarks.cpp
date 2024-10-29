#include <mathops/transcedentals.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_InvSqrt(benchmark::State &state)
    {
        volatile float num = 9.8;

        for (auto _ : state)
        {
            float res = mathops::fast_invsqrt(num);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Sqrt(benchmark::State &state)
    {
        volatile float num = 9.8;

        for (auto _ : state)
        {
            float res = mathops::fast_sqrt(num);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_InvSqrt);
    BENCHMARK(BM_Sqrt);
}
}