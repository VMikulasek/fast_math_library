#include <sums_shared_fields.hpp>
#include <mathops/detail/AVX/avx_sums.hpp>

#include <benchmark/benchmark.h>
#include <iostream>

namespace analysis
{
namespace benchmarks
{
    static void BM_Sum1Elem(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::avx::sum(_1ElemArr, _1_ELEM_ARR_SIZE);
        }
    }
    static void BM_Sum8Elem(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::avx::sum(_8ElemArr, _8_ELEM_ARR_SIZE);
        }
    }
    static void BM_Sum9Elem(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::avx::sum(_9ElemArr, _9_ELEM_ARR_SIZE);
        }
    }
    static void BM_Sum16Elem(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::avx::sum(_16ElemArr, _16_ELEM_ARR_SIZE);
        }
    }
    static void BM_Sum17Elem(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::avx::sum(_17ElemArr, _17_ELEM_ARR_SIZE);
        }
    }
    static void BM_Sum24Elem(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::avx::sum(_24ElemArr, _24_ELEM_ARR_SIZE);
        }
    }
    static void BM_Sum25Elem(benchmark::State &state)
    {
        for (auto _ : state)
        {
            mathops::avx::sum(_25ElemArr, _25_ELEM_ARR_SIZE);
        }
    }
    static void BM_SumBigArr(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        for (auto _ : state)
        {
            mathops::avx::sum(bigArr, BIG_ARR_SIZE);
        }

        FreeBigArr(bigArr);
    }

    BENCHMARK(BM_Sum1Elem);
    BENCHMARK(BM_Sum8Elem);
    BENCHMARK(BM_Sum9Elem);
    BENCHMARK(BM_Sum16Elem);
    BENCHMARK(BM_Sum17Elem);
    BENCHMARK(BM_Sum24Elem);
    BENCHMARK(BM_Sum25Elem);
    BENCHMARK(BM_SumBigArr);
}
}