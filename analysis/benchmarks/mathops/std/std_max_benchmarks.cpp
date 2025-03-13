#include <mathops_shared_fields.hpp>

#include <algorithm>
#include <execution>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Max(benchmark::State &state, const float *arr, size_t size)
    {
        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            auto res = std::max_element(std::execution::unseq, arr, arr + size);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Max9Elem(benchmark::State &state)
    {
        BM_Max(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_Max10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_Max(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_Max15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_Max(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_Max9Elem);
    BENCHMARK(BM_Max10kElem);
    BENCHMARK(BM_Max15MElem);
} // namespace benchmarks
} // namespace analysis