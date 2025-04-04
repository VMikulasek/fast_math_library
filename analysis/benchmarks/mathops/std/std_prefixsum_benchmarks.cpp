#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <simd/simd_operations.hpp>

#include <numeric>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_PrefixSum(benchmark::State &state)
    {
        size_t size = state.range(0);
        float *arr = AllocAvxAlignedArr(size);
        float *dst = AllocAvxAlignedArr(size);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            std::inclusive_scan(arr, arr + size, dst);
            benchmark::DoNotOptimize(dst);
        } 

        _free_aligned_memory(arr);
        _free_aligned_memory(dst);
    }

    BENCHMARK(BM_PrefixSum)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);

} // benchmarks
} // analysis