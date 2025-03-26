#include <mathops/transcendentals.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Sin(benchmark::State &state)
    {
        volatile float num = 3.1231413412313f;

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(num);
            float res = mathops::fast_sin(num);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Cos(benchmark::State &state)
    {
        volatile float num = 3.1231413412313f;

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(num);
            float res = mathops::fast_cos(num);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Sin);
    BENCHMARK(BM_Cos);
}
}