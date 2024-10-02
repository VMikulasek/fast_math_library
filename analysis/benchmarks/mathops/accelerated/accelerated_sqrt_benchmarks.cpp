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
            mathops::fast_invsqrt(9.8);
        }
    }

    static void BM_Sqrt(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::fast_sqrt(9.8);
        }
    }

    BENCHMARK(BM_InvSqrt);
    BENCHMARK(BM_Sqrt);
}
}