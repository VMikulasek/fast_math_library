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

    static void BM_InvSqrt(benchmark::State &state, const float *arr, size_t size)
    {
        float *dst = _alloc_avxaligned_memory_float(size * sizeof(float), simd::SIMDOperations<float, simd::InstructionSet::AVX>::ALIGNMENT);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            mathops::vec::fast_invsqrt_arr<float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(arr, size, dst);
            benchmark::DoNotOptimize(dst);
        }

        _free_aligned_memory(dst);
    }

    static void BM_InvSqrt9Elem(benchmark::State &state)
    {
        BM_InvSqrt(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_InvSqrt10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_InvSqrt(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_InvSqrt15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_InvSqrt(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_InvSqrt9Elem);
    BENCHMARK(BM_InvSqrt10kElem);
    BENCHMARK(BM_InvSqrt15MElem);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis