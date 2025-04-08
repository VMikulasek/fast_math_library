#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>

#include <boost/math/statistics/univariate_statistics.hpp>
#include <execution>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_SampleVariance(benchmark::State &state)
    {
        size_t size = state.range(0);
        float *arr = AllocAvxAlignedArr(size);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = boost::math::statistics::sample_variance(arr, arr + size);
            benchmark::DoNotOptimize(res);
        }

        _free_aligned_memory(arr);   
    }

    BENCHMARK(BM_SampleVariance)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);
} // namespace benchmarks
} // namespace analysiss