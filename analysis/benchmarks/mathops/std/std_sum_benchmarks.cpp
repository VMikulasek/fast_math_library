#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>

#include <numeric>
#include <execution>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Sum(benchmark::State &state)
    {
        size_t size = state.range(0);
        float *arr = AllocAvxAlignedArr(size);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = std::reduce(std::execution::par, arr, arr + size);
            benchmark::DoNotOptimize(res);
        }

        _free_aligned_memory(arr);
    }

    BENCHMARK(BM_Sum)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);

} // namespace benchmarks
} // namespace analysis