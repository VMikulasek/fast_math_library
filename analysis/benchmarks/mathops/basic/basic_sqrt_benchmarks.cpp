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
            mathops::invsqrt(9);
        }
    }

    static void BM_Sqrt(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::sqrt(9);
        }
    }

    BENCHMARK(BM_InvSqrt);
    BENCHMARK(BM_Sqrt);
}
}