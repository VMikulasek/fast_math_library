    #include <mathops_shared_fields.hpp>
    #include <common/memory_common.inl>
    #include <mathops/detail/AVX/avx_transcedentals.hpp>

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
                mathops::avx::fast_sqrt_arr(arr, size, dst);
            }

            _free_aligned_memory(dst);
        }

        static void BM_Sqrt1Elem(benchmark::State &state)
        {
            BM_Sqrt(state, _1ElemArr, _1_ELEM_ARR_SIZE);
        }
        static void BM_Sqrt8Elem(benchmark::State &state)
        {
            BM_Sqrt(state, _8ElemArr, _8_ELEM_ARR_SIZE);
        }
        static void BM_Sqrt9Elem(benchmark::State &state)
        {
            BM_Sqrt(state, _9ElemArr, _9_ELEM_ARR_SIZE);
        }
        static void BM_Sqrt16Elem(benchmark::State &state)
        {
            BM_Sqrt(state, _16ElemArr, _16_ELEM_ARR_SIZE);
        }
        static void BM_Sqrt17Elem(benchmark::State &state)
        {
            BM_Sqrt(state, _17ElemArr, _17_ELEM_ARR_SIZE);
        }
        static void BM_Sqrt24Elem(benchmark::State &state)
        {
            BM_Sqrt(state, _24ElemArr, _24_ELEM_ARR_SIZE);
        }
        static void BM_Sqrt25Elem(benchmark::State &state)
        {
            BM_Sqrt(state, _25ElemArr, _25_ELEM_ARR_SIZE);
        }
        static void BM_SqrtMedArr(benchmark::State &state)
        {
            float *medArr = AllocMediumArr();

            BM_Sqrt(state, medArr, MEDIUM_ARR_SIZE);

            _free_aligned_memory(medArr);
        }
        static void BM_SqrtBigArr(benchmark::State &state)
        {
            float *bigArr = AllocBigArr();

            BM_Sqrt(state, bigArr, BIG_ARR_SIZE);

            _free_aligned_memory(bigArr);
        }

        BENCHMARK(BM_Sqrt1Elem);
        BENCHMARK(BM_Sqrt8Elem);
        BENCHMARK(BM_Sqrt9Elem);
        BENCHMARK(BM_Sqrt16Elem);
        BENCHMARK(BM_Sqrt17Elem);
        BENCHMARK(BM_Sqrt24Elem);
        BENCHMARK(BM_Sqrt25Elem);
        BENCHMARK(BM_SqrtMedArr);
        BENCHMARK(BM_SqrtBigArr);

    } // namespace benchmarks
    } // namespace analysis