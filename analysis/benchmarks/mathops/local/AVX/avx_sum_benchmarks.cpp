#include <mathops_shared_fields.hpp>
#include <mathops/detail/VEC/vec_sums.hpp>
#include <simd/simd_common.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Sum(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::vec::sum<float, simd::InstructionSet::AVX>(arr, size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Sum9Elem(benchmark::State &state)
    {
        BM_Sum(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_Sum10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_Sum(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_Sum15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_Sum(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_Sum9Elem);
    BENCHMARK(BM_Sum10kElem);
    BENCHMARK(BM_Sum15MElem);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis