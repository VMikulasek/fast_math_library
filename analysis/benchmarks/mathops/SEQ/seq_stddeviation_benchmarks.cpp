#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <mathops/detail/SEQ/seq_statisticals.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_StdDeviation(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            float res = mathops::seq::std_deviation(arr, size);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_StdDeviationWithProbabilities(benchmark::State &state, const float *arr, const float *probabilities, size_t size)
    {
        for (auto _ : state)
        {
            float res = mathops::seq::std_deviation(arr, probabilities, size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_SampleStdDeviation(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            float res = mathops::seq::sample_std_deviation(arr, size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_StdDeviation9Elem(benchmark::State &state)
    {
        BM_StdDeviation(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_StdDeviation10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_StdDeviation(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_StdDeviation15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_StdDeviation(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    static void BM_StdDeviationWithProbabilities9Elem(benchmark::State &state)
    {
        alignas(AVX_ALIGNMENT) float probabilities[_9_ELEM_ARR_SIZE] { 0, 0, 0, 0, 0, 0, 0, 0, 1 }; 
        BM_StdDeviationWithProbabilities(state, _9ElemArr, probabilities, _9_ELEM_ARR_SIZE);
    }
    static void BM_StdDeviationWithProbabilities10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();
        float *probabilities = AllocMediumArr();
        std::fill(probabilities, probabilities + MEDIUM_ARR_SIZE, 0.f);
        probabilities[0] = 1.f;

        BM_StdDeviationWithProbabilities(state, medArr, probabilities, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
        _free_aligned_memory(probabilities);
    }
    static void BM_StdDeviationWithProbabilities15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();
        float *probabilities = AllocBigArr();
        std::fill(probabilities, probabilities + BIG_ARR_SIZE, 0.f);
        probabilities[0] = 1.f;

        BM_StdDeviationWithProbabilities(state, bigArr, probabilities, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
        _free_aligned_memory(probabilities);
    }

    static void BM_SampleStdDeviation9Elem(benchmark::State &state)
    {
        BM_SampleStdDeviation(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_SampleStdDeviation10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_SampleStdDeviation(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_SampleStdDeviation15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_SampleStdDeviation(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_StdDeviation9Elem);
    BENCHMARK(BM_StdDeviation10kElem);
    BENCHMARK(BM_StdDeviation15MElem);

    BENCHMARK(BM_StdDeviationWithProbabilities9Elem);
    BENCHMARK(BM_StdDeviationWithProbabilities10kElem);
    BENCHMARK(BM_StdDeviationWithProbabilities15MElem);

    BENCHMARK(BM_SampleStdDeviation9Elem);
    BENCHMARK(BM_SampleStdDeviation10kElem);
    BENCHMARK(BM_SampleStdDeviation15MElem);
} // namespace benchmarks
} // namespace analysis