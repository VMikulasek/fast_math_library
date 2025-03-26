    #include <mathops_shared_fields.hpp>
    #include <common/detail/memory_common.inl>
    #include <mathops/detail/SEQ/seq_transcendentals.hpp>

    #include <benchmark/benchmark.h>

    namespace analysis
    {
    namespace benchmarks
    {
        static void BM_Sqrt(benchmark::State &state, const float *arr, size_t size)
        {
            float *dst = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);

            for (auto _ : state)
            {
                benchmark::DoNotOptimize(arr);
                mathops::seq::sin_arr(arr, size, dst);
                benchmark::DoNotOptimize(dst);
            }

            _free_aligned_memory(dst);
        }

        static void BM_Sqrt9Elem(benchmark::State &state)
        {
            BM_Sqrt(state, _9ElemArr, _9_ELEM_ARR_SIZE);
        }
        static void BM_Sqrt10kElem(benchmark::State &state)
        {
            float *medArr = AllocMediumArr();

            BM_Sqrt(state, medArr, MEDIUM_ARR_SIZE);

            _free_aligned_memory(medArr);
        }
        static void BM_Sqrt15MElem(benchmark::State &state)
        {
            float *bigArr = AllocBigArr();

            BM_Sqrt(state, bigArr, BIG_ARR_SIZE);

            _free_aligned_memory(bigArr);
        }

        BENCHMARK(BM_Sqrt9Elem);
        BENCHMARK(BM_Sqrt10kElem);
        BENCHMARK(BM_Sqrt15MElem);
    } // namespace benchmarks
    } // namespace analysis