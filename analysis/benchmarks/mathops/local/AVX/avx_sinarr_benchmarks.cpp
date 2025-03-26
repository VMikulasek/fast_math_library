#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <mathops/detail/VEC/vec_transcendentals.hpp>
#include <simd/simd_common.hpp>
#include <simd/simd_operations.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Sin(benchmark::State &state, const float *arr, size_t size)
    {
        float *dst = _alloc_avxaligned_memory_float(size * sizeof(float), simd::SIMDOperations<float, simd::InstructionSet::AVX>::ALIGNMENT);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            mathops::vec::fast_sin_arr<float, simd::InstructionSet::AVX>(arr, size, dst);
            benchmark::DoNotOptimize(dst);
        }

        _free_aligned_memory(dst);
    }

    static void BM_Sqrt9Elem(benchmark::State &state)
    {
        BM_Sin(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_Sqrt10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_Sin(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_Sqrt15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_Sin(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_Sqrt9Elem);
    BENCHMARK(BM_Sqrt10kElem);
    BENCHMARK(BM_Sqrt15MElem);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis