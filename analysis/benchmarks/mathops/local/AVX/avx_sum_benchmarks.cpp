#include <mathops_shared_fields.hpp>
#include <mathops/detail/VEC/vec_sums.hpp>
#include <simd/simd_common.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Sum(benchmark::State &state)
    {
        size_t size = state.range(0);
        float *arr = AllocAvxAlignedArr(size);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::vec::sum<float, simd::InstructionSet::AVX>(arr, size);
            benchmark::DoNotOptimize(res);
        }

        _free_aligned_memory(arr);
    }

    BENCHMARK(BM_Sum)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis