#include <mathops_shared_fields.hpp>
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
    static void BM_SumMedArr(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_Sum(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
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
    BENCHMARK(BM_SumMedArr);
    BENCHMARK(BM_SumBigArr);
} // namespace benchmarks
} // namespace analysis