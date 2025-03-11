#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <mathops/detail/AVX/avx_statisticals.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_GeometricMean(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            float res = mathops::avx::geometric_mean(arr, size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_GeometricMean9Elem(benchmark::State &state)
    {
        BM_GeometricMean(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_GeometricMean10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_GeometricMean(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_GeometricMean15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_GeometricMean(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_GeometricMean9Elem);
    BENCHMARK(BM_GeometricMean10kElem);
    BENCHMARK(BM_GeometricMean15MElem);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis