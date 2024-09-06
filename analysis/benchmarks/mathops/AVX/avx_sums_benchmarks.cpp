#include <sums_shared_fields.hpp>
#include <mathops/detail/AVX/avx_sums.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_AvxSum1Elem(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::avx::sum(_1ElemArr, _1_ELEM_ARR_SIZE);
        }
    }

    static void BM_AvxSumBigArr(benchmark::State &state)
    {
        AllocBigArr();

        for (auto _ : state)
        {
            mathops::avx::sum(bigArr, BIG_ARR_SIZE);
        }

        FreeBigArr();
    }

    BENCHMARK(BM_AvxSum1Elem);
    BENCHMARK(BM_AvxSumBigArr);
}
}