#include <mathops_shared_fields.hpp>

#include <boost/math/statistics/univariate_statistics.hpp>
#include <execution>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Variance(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = boost::math::statistics::variance(arr, arr + size);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_SampleVariance(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = boost::math::statistics::sample_variance(arr, arr + size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Variance9Elem(benchmark::State &state)
    {
        BM_Variance(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_Variance10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_Variance(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_Variance15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_Variance(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    static void BM_SampleVariance9Elem(benchmark::State &state)
    {
        BM_SampleVariance(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_SampleVariance10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_SampleVariance(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_SampleVariance15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_SampleVariance(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_Variance9Elem);
    BENCHMARK(BM_Variance10kElem);
    BENCHMARK(BM_Variance15MElem);

    BENCHMARK(BM_SampleVariance9Elem);
    BENCHMARK(BM_SampleVariance10kElem);
    BENCHMARK(BM_SampleVariance15MElem);
} // namespace benchmarks
} // namespace analysiss