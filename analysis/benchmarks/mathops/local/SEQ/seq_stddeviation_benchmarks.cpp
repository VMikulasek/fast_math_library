#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <mathops/detail/SEQ/seq_statisticals.hpp>
#include <simd/simd_operations.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_StdDeviation(benchmark::State &state)
    {
        size_t size = state.range(0);
        float *arr = AllocAvxAlignedArr(size);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::seq::std_deviation(arr, size);
            benchmark::DoNotOptimize(res);
        }

        _free_aligned_memory(arr);
    }
    
    static void BM_SampleStdDeviation(benchmark::State &state)
    {
        size_t size = state.range(0);
        float *arr = AllocAvxAlignedArr(size);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::seq::sample_std_deviation(arr, size);
            benchmark::DoNotOptimize(res);
        }

        _free_aligned_memory(arr);
    }

    static void BM_StdDeviationWithProbabilities(benchmark::State &state)
    {
        size_t size = state.range(0);
        float *arr = AllocAvxAlignedArr(size);
        float *probabilities = AllocAvxAlignedArr(size);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(arr);
            float res = mathops::seq::std_deviation(arr, probabilities, size);
            benchmark::DoNotOptimize(res);
        }
    
        _free_aligned_memory(arr);
        _free_aligned_memory(probabilities);
    }

    BENCHMARK(BM_StdDeviation)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);
    BENCHMARK(BM_SampleStdDeviation)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);
    BENCHMARK(BM_StdDeviationWithProbabilities)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);

} // namespace benchmarks
} // namespace analysis