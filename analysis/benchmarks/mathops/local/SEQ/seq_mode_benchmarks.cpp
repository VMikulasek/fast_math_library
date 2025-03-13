#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <mathops/detail/SEQ/seq_statisticals.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Mode(benchmark::State &state, const int *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::seq::mode(arr, size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Mode9Elem(benchmark::State &state)
    {
        BM_Mode(state, _9ElemIntArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_Mode10kElem(benchmark::State &state)
    {
        int *medArr = AllocMediumIntArr();

        BM_Mode(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_Mode15MElem(benchmark::State &state)
    {
        int *bigArr = AllocBigIntArr();

        BM_Mode(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_Mode9Elem);
    BENCHMARK(BM_Mode10kElem);
    BENCHMARK(BM_Mode15MElem);
} // namespace benchmarks
} // namespace analysis