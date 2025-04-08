#include <simd/detail/vec/simd_vec4.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Add(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::addv(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Sub(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::subv(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Mul(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::mulv(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Div(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::divv(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Abs(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::absv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Min(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::minv(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Max(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::maxv(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Sqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::sqrtv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_SqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::fast_sqrtv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_InvSqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::invsqrtv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_InvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::fast_invsqrtv(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Sin(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::sinv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_SinLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::fast_sinv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Cos(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::cosv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_CosLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::fast_cosv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Tan(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::tanv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Cot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::cotv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Dot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::seq::dotv(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Length(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::seq::lengthv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Normalize(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::seq::normalizev(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Add);
    BENCHMARK(BM_Sub);
    BENCHMARK(BM_Mul);
    BENCHMARK(BM_Div);
    BENCHMARK(BM_Abs);
    BENCHMARK(BM_Min);
    BENCHMARK(BM_Max);
    BENCHMARK(BM_Sqrt);
    BENCHMARK(BM_SqrtLowp);
    BENCHMARK(BM_InvSqrt);
    BENCHMARK(BM_InvSqrtLowp);
    BENCHMARK(BM_Sin);
    BENCHMARK(BM_SinLowp);
    BENCHMARK(BM_Cos);
    BENCHMARK(BM_CosLowp);
    BENCHMARK(BM_Tan);
    BENCHMARK(BM_Cot);
    BENCHMARK(BM_Dot);
    BENCHMARK(BM_Length);
    BENCHMARK(BM_Normalize);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis