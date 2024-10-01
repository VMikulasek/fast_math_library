#include <mathops_shared_fields.hpp>
#include <mathops/detail/common/memory_common.inl>
#include <mathops/detail/AVX/avx_sums.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Sum(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            mathops::avx::sum(arr, size);
        }
    }

    static void BM_Sum1Elem(benchmark::State &state)
    {
        BM_Sum(state, _1ElemArr, _1_ELEM_ARR_SIZE);
    }
    static void BM_Sum8Elem(benchmark::State &state)
    {
        BM_Sum(state, _8ElemArr, _8_ELEM_ARR_SIZE);
    }
    static void BM_Sum9Elem(benchmark::State &state)
    {
        BM_Sum(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_Sum16Elem(benchmark::State &state)
    {
        BM_Sum(state, _16ElemArr, _16_ELEM_ARR_SIZE);
    }
    static void BM_Sum17Elem(benchmark::State &state)
    {
        BM_Sum(state, _17ElemArr, _17_ELEM_ARR_SIZE);
    }
    static void BM_Sum24Elem(benchmark::State &state)
    {
        BM_Sum(state, _24ElemArr, _24_ELEM_ARR_SIZE);
    }
    static void BM_Sum25Elem(benchmark::State &state)
    {
        BM_Sum(state, _25ElemArr, _25_ELEM_ARR_SIZE);
    }
    static void BM_SumBigArr(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_Sum(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_Sum1Elem);
    BENCHMARK(BM_Sum8Elem);
    BENCHMARK(BM_Sum9Elem);
    BENCHMARK(BM_Sum16Elem);
    BENCHMARK(BM_Sum17Elem);
    BENCHMARK(BM_Sum24Elem);
    BENCHMARK(BM_Sum25Elem);
    BENCHMARK(BM_SumBigArr);

    static void BM_PrefixSum(benchmark::State &state, const float *srcArr, size_t size)
    {
        #if defined(_MSC_VER)
            float* dst = static_cast<float*>(_aligned_malloc(size * sizeof(float), AVX_ALIGNMENT));
#else // _MSC_VER
            float* dst = static_cast<float*>(std::aligned_alloc(AVX_ALIGNMENT, size * sizeof(float)));
#endif // _MSC_VER

        for (auto _ : state)
        {
            mathops::avx::prefix_sum(srcArr, size, dst);
        } 

#if defined(_MSC_VER)
            _aligned_free(dst);
#else // _MSC_VER
            std::free(dst);
#endif // _MSC_VER
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
    BENCHMARK(BM_PrefixSumBigArr);
}
}