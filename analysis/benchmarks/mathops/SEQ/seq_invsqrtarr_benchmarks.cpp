    #include <mathops_shared_fields.hpp>
    #include <common/memory_common.inl>
    #include <mathops/detail/SEQ/seq_transcedentals.hpp>

    #include <benchmark/benchmark.h>

    namespace analysis
    {
    namespace benchmarks
    {
        static void BM_InvSqrt(benchmark::State &state, const float *arr, size_t size)
        {
            float *dst = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);

            for (auto _ : state)
            {
                mathops::seq::fast_invsqrt_arr(arr, size, dst);
            }

            _free_aligned_memory(dst);
        }

        static void BM_InvSqrt1Elem(benchmark::State &state)
        {
            BM_InvSqrt(state, _1ElemArr, _1_ELEM_ARR_SIZE);
        }
        static void BM_InvSqrt8Elem(benchmark::State &state)
        {
            BM_InvSqrt(state, _8ElemArr, _8_ELEM_ARR_SIZE);
        }
        static void BM_InvSqrt9Elem(benchmark::State &state)
        {
            BM_InvSqrt(state, _9ElemArr, _9_ELEM_ARR_SIZE);
        }
        static void BM_InvSqrt16Elem(benchmark::State &state)
        {
            BM_InvSqrt(state, _16ElemArr, _16_ELEM_ARR_SIZE);
        }
        static void BM_InvSqrt17Elem(benchmark::State &state)
        {
            BM_InvSqrt(state, _17ElemArr, _17_ELEM_ARR_SIZE);
        }
        static void BM_InvSqrt24Elem(benchmark::State &state)
        {
            BM_InvSqrt(state, _24ElemArr, _24_ELEM_ARR_SIZE);
        }
        static void BM_InvSqrt25Elem(benchmark::State &state)
        {
            BM_InvSqrt(state, _25ElemArr, _25_ELEM_ARR_SIZE);
        }
        static void BM_InvSqrtBigArr(benchmark::State &state)
        {
            float *bigArr = AllocBigArr();

            BM_InvSqrt(state, bigArr, BIG_ARR_SIZE);

            _free_aligned_memory(bigArr);
        }

        BENCHMARK(BM_InvSqrt1Elem);
        BENCHMARK(BM_InvSqrt8Elem);
        BENCHMARK(BM_InvSqrt9Elem);
        BENCHMARK(BM_InvSqrt16Elem);
        BENCHMARK(BM_InvSqrt17Elem);
        BENCHMARK(BM_InvSqrt24Elem);
        BENCHMARK(BM_InvSqrt25Elem);
        BENCHMARK(BM_InvSqrtBigArr);

    } // namespace benchmarks
    } // namespace analysis