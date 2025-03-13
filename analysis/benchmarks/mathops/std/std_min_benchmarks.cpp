#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>

#include <algorithm>
#include <execution>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Min(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            auto res = std::min_element(std::execution::unseq, arr, arr + size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Min9Elem(benchmark::State &state)
    {
        BM_Min(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_Min10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_Min(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_Min15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_Min(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_Min9Elem);
    BENCHMARK(BM_Min10kElem);
    BENCHMARK(BM_Min15MElem);
} // namespace benchmarks
} // namespace analysis