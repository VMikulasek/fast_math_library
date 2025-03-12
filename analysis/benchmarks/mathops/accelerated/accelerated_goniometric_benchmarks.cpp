#include <mathops/transcedentals.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Sin(benchmark::State &state)
    {
        volatile float num = std::rand();

        for (auto _ : state)
        {
            float res = mathops::fast_sin(num);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Cos(benchmark::State &state)
    {
        volatile float num = std::rand();

        for (auto _ : state)
        {
            float res = mathops::fast_cos(num);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Sin);
    BENCHMARK(BM_Cos);
}
}