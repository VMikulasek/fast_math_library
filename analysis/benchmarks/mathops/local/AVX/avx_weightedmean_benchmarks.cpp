#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <mathops/detail/VEC/vec_statisticals.hpp>
#include <simd/simd_common.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_WeightedMean(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::vec::weighted_mean<float, simd::InstructionSet::AVX>(arr, arr, size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_WeightedMean9Elem(benchmark::State &state)
    {
        BM_WeightedMean(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_WeightedMean10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_WeightedMean(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_WeightedMean15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_WeightedMean(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_WeightedMean9Elem);
    BENCHMARK(BM_WeightedMean10kElem);
    BENCHMARK(BM_WeightedMean15MElem);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis