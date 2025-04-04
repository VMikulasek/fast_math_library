#include <mathops_shared_fields.hpp>
#include <mathops/detail/VEC/vec_sums.hpp>
#include <common/detail/memory_common.inl>
#include <simd/simd_common.hpp>
#include <simd/simd_operations.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_PrefixSum(benchmark::State &state)
    {
        size_t size = state.range(0);
        float *arr = AllocAvxAlignedArr(size);
        float *dst = AllocAvxAlignedArr(size);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            mathops::vec::prefix_sum<float, simd::InstructionSet::AVX>(arr, size, dst);
            benchmark::DoNotOptimize(dst);
        }

        _free_aligned_memory(arr);
        _free_aligned_memory(dst);
    }

    BENCHMARK(BM_PrefixSum)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);

#endif // HAS_AVX
} // benchmarks
} // analysis