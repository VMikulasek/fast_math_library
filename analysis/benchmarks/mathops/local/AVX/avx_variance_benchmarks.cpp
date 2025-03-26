#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <mathops/detail/VEC/vec_statisticals.hpp>
#include <simd/simd_common.hpp>
#include <simd/simd_operations.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Variance(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::vec::variance<float, simd::InstructionSet::AVX>(arr, size);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_SampleVariance(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::vec::sample_variance<float, simd::InstructionSet::AVX>(arr, size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_VarianceWithProbabilities(benchmark::State &state, const float *arr, const float *probabilities, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::vec::variance<float, simd::InstructionSet::AVX>(arr, probabilities, size);
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

    static void BM_VarianceWithProbabilities9Elem(benchmark::State &state)
    {
        alignas(simd::SIMDOperations<float, simd::InstructionSet::AVX>::ALIGNMENT) float probabilities[_9_ELEM_ARR_SIZE] { 0, 0, 0, 0, 0, 0, 0, 0, 1 }; 
        BM_VarianceWithProbabilities(state, _9ElemArr, probabilities, _9_ELEM_ARR_SIZE);
    }
    static void BM_VarianceWithProbabilities10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();
        float *probabilities = AllocMediumArr();
        std::fill(probabilities, probabilities + MEDIUM_ARR_SIZE, 0.f);
        probabilities[0] = 1.f;

        BM_VarianceWithProbabilities(state, medArr, probabilities, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
        _free_aligned_memory(probabilities);
    }
    static void BM_VarianceWithProbabilities15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();
        float *probabilities = AllocBigArr();
        std::fill(probabilities, probabilities + BIG_ARR_SIZE, 0.f);
        probabilities[0] = 1.f;

        BM_VarianceWithProbabilities(state, bigArr, probabilities, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
        _free_aligned_memory(probabilities);
    }

    BENCHMARK(BM_Variance9Elem);
    BENCHMARK(BM_Variance10kElem);
    BENCHMARK(BM_Variance15MElem);

    BENCHMARK(BM_SampleVariance9Elem);
    BENCHMARK(BM_SampleVariance10kElem);
    BENCHMARK(BM_SampleVariance15MElem);

    BENCHMARK(BM_VarianceWithProbabilities9Elem);
    BENCHMARK(BM_VarianceWithProbabilities10kElem);
    BENCHMARK(BM_VarianceWithProbabilities15MElem);
#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis