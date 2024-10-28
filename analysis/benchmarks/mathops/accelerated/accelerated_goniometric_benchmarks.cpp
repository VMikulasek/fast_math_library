#include <mathops/transcedentals.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Sin(benchmark::State &state)
    {
        volatile float num = 3.14;

        for (auto _ : state)
        {
            float res = mathops::fast_sin(num);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Cos(benchmark::State &state)
    {
        volatile float num = 3.14;

        for (auto _ : state)
        {
            float res = mathops::fast_cos(num);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Tan(benchmark::State &state)
    {
        volatile float num = 3.14;

        for (auto _ : state)
        {
            float res = mathops::fast_tan(num);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Cot(benchmark::State &state)
    {
        volatile float num = 3.14;

        for (auto _ : state)
        {
            float res = mathops::fast_cot(num);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Sin);
    BENCHMARK(BM_Cos);
    BENCHMARK(BM_Tan);
    BENCHMARK(BM_Cot);
}
}