#include <sums_shared_fields.hpp>
#include <mathops/detail/SEQ/seq_sums.hpp>

#include <benchmark/benchmark.h>
#include <iostream>

namespace analysis
{
namespace benchmarks
{
    static void BM_SeqSum1Elem(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::seq::sum(_1ElemArr, _1_ELEM_ARR_SIZE);
        }
    }

    static void BM_SeqSumBigArr(benchmark::State &state)
    {
        AllocBigArr();

        std::cout << bigArr << std::endl;
        for (auto _ : state)
        {
            mathops::seq::sum(bigArr, BIG_ARR_SIZE);
        }

        FreeBigArr();
    }

    BENCHMARK(BM_SeqSum1Elem);
    BENCHMARK(BM_SeqSumBigArr);
}
}