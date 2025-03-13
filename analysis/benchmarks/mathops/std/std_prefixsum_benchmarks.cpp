#include <mathops_shared_fields.hpp>

#include <numeric>
#include <execution>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_PrefixSum(benchmark::State &state, const float *srcArr, size_t size)
    {
        float *dst = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(srcArr);
            std::inclusive_scan(std::execution::unseq, srcArr, srcArr + size, dst);
            benchmark::DoNotOptimize(dst);
        } 

        _free_aligned_memory(dst);
    }

    static void BM_PrefixSum9Elem(benchmark::State &state)
    {
        BM_PrefixSum(state, _9ElemArr, _9_ELEM_ARR_SIZE);
    }
    static void BM_PrefixSum10kElem(benchmark::State &state)
    {
        float *medArr = AllocMediumArr();

        BM_PrefixSum(state, medArr, MEDIUM_ARR_SIZE);

        _free_aligned_memory(medArr);
    }
    static void BM_PrefixSum15MElem(benchmark::State &state)
    {
        float *bigArr = AllocBigArr();

        BM_PrefixSum(state, bigArr, BIG_ARR_SIZE);

        _free_aligned_memory(bigArr);
    }

    BENCHMARK(BM_PrefixSum9Elem);
    BENCHMARK(BM_PrefixSum10kElem);
    BENCHMARK(BM_PrefixSum15MElem);

#endif // HAS_AVX
} // benchmarks
} // analysis