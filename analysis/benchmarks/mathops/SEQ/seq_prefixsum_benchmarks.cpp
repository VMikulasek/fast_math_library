#include <mathops_shared_fields.hpp>
#include <mathops/detail/SEQ/seq_sums.hpp>
#include <common/memory_common.inl>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_PrefixSum(benchmark::State &state, const float *srcArr, size_t size)
    {
        float *dst = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);

        for (auto _ : state)
        {
            mathops::seq::prefix_sum(srcArr, size, dst);
        } 

        _free_aligned_memory(dst);
    }

    static void BM_PrefixSum1Elem(benchmark::State &state)
    {
        BM_PrefixSum(state, _1ElemArr, _1_ELEM_ARR_SIZE);
    }
    static void BM_PrefixSum8Elem(benchmark::State &state)
    {
        BM_PrefixSum(state, _8ElemArr, _8_ELEM_ARR_SIZE);
    }
    static void BM_PrefixSum9Elem(benchmark::State &state)
    {
        BM_PrefixSum(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_PrefixSum16Elem(benchmark::State &state)
    {
        BM_PrefixSum(state, _16ElemArr, _16_ELEM_ARR_SIZE);
    }
    static void BM_PrefixSum17Elem(benchmark::State &state)
    {
        BM_PrefixSum(state, _17ElemArr, _17_ELEM_ARR_SIZE);
    }
    static void BM_PrefixSum24Elem(benchmark::State &state)
    {
        BM_PrefixSum(state, _24ElemArr, _24_ELEM_ARR_SIZE);
    }
    static void BM_PrefixSum25Elem(benchmark::State &state)
    {
        BM_PrefixSum(state, _25ElemArr, _25_ELEM_ARR_SIZE);
    }
    static void BM_PrefixSumMedArr(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_PrefixSum(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_PrefixSumBigArr(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_PrefixSum(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_PrefixSum1Elem);
    BENCHMARK(BM_PrefixSum8Elem);
    BENCHMARK(BM_PrefixSum9Elem);
    BENCHMARK(BM_PrefixSum16Elem);
    BENCHMARK(BM_PrefixSum17Elem);
    BENCHMARK(BM_PrefixSum24Elem);
    BENCHMARK(BM_PrefixSum25Elem);
    BENCHMARK(BM_PrefixSumMedArr);
    BENCHMARK(BM_PrefixSumBigArr);
} // benchmarks
} // analysis