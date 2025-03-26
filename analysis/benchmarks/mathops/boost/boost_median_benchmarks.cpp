#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <simd/simd_operations.hpp>
#include <simd/simd_common.hpp>

#include <boost/math/statistics/univariate_statistics.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Median(benchmark::State &state, float *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = boost::math::statistics::median(arr, arr + size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Median9Elem(benchmark::State &state)
    {
        float *arr = _alloc_avxaligned_memory_float(_9_ELEM_ARR_SIZE * sizeof(float), simd::SIMDOperations<float, simd::InstructionSet::AVX>::ALIGNMENT);

        BM_Median(state, arr, _9_ELEM_ARR_SIZE);

        _free_aligned_memory(arr);
    }
    static void BM_Median10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_Median(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_Median15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_Median(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_Median9Elem);
    BENCHMARK(BM_Median10kElem);
    BENCHMARK(BM_Median15MElem);
} // namespace benchmarks
} // namespace analysis