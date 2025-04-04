    #include <mathops_shared_fields.hpp>
    #include <common/detail/memory_common.inl>
    #include <mathops/detail/SEQ/seq_transcendentals.hpp>
    #include <simd/simd_operations.hpp>

    #include <benchmark/benchmark.h>

    namespace analysis
    {
    namespace benchmarks
    {
        static void BM_Cos(benchmark::State &state)
        {
            size_t size = state.range(0);
            float *arr = AllocAvxAlignedArr(size);
            float *dst = AllocAvxAlignedArr(size);
    
            for (auto _ : state)
            {
                benchmark::DoNotOptimize(arr);
                mathops::seq::cos_arr(arr, size, dst);
                benchmark::DoNotOptimize(dst);
            }
            
            _free_aligned_memory(arr);
            _free_aligned_memory(dst);
        }

        BENCHMARK(BM_Cos)->Range(_8_ELEM_ARR_SIZE, BIG_ARR_SIZE);
    } // namespace benchmarks
    } // namespace analysis