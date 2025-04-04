#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>

#include <algorithm>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Max(benchmark::State &state)
    {
        size_t size = state.range(0);
        float *arr = AllocAvxAlignedArr(size);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            auto res = std::max_element(arr, arr + size);
            benchmark::DoNotOptimize(res);
        }

        _free_aligned_memory(arr);
    }

    BENCHMARK(BM_Max)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);

} // namespace benchmarks
} // namespace analysis