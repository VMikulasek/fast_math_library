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
    static void BM_Median(benchmark::State &state)
    {
        size_t size = state.range(0);
        float *arr = AllocAvxAlignedArr(size);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = boost::math::statistics::median(arr, arr + size);
            benchmark::DoNotOptimize(res);
        }

        _free_aligned_memory(arr);
    }

    BENCHMARK(BM_Median)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);
} // namespace benchmarks
} // namespace analysis