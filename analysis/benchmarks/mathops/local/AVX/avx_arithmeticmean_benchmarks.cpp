#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <mathops/detail/VEC/vec_statisticals.hpp>
#include <simd/simd_common.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_ArithmeticMean(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::vec::arithmetic_mean<float, simd::InstructionSet::AVX>(arr, size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_ArithmeticMean9Elem(benchmark::State &state)
    {
        BM_ArithmeticMean(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_ArithmeticMean10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_ArithmeticMean(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_ArithmeticMean15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_ArithmeticMean(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_ArithmeticMean9Elem);
    BENCHMARK(BM_ArithmeticMean10kElem);
    BENCHMARK(BM_ArithmeticMean15MElem);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis