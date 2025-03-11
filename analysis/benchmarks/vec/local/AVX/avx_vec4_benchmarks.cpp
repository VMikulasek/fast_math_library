#include <simd/detail/vec/simd_vec4.hpp>
#include <simd/detail/vec/AVX/simd_vec4_avx_float.hpp>

#include <benchmark/benchmark.h>

#undef addv4f
#undef subv4f
#undef mulv4f
#undef divv4f
#undef absv4f
#undef minv4f
#undef maxv4f
#undef fast_sqrtv4f
#undef fast_invsqrtv4f
#undef fast_sinv4f
#undef fast_cosv4f
#undef dotv4f
#undef lengthv4f
#undef normalizev4f

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Vec4Add(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::addv4f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Sub(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::subv4f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Mul(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::mulv4f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Div(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::divv4f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec4Abs(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::absv4f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Min(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::minv4f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Max(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::maxv4f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec4Sqrt(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::seq::sqrtv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4SqrtLowp(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::fast_sqrtv4f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4InvSqrt(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::seq::invsqrtv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4InvSqrtLowp(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::fast_invsqrtv4f(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec4Sin(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::seq::sinv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4SinLowp(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::fast_sinv4f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Cos(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::seq::cosv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4CosLowp(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::fast_cosv4f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Tan(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::seq::tanv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Cot(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::seq::cotv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Vec4Dot(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            float res = simd::avx::dotv4f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Length(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            float res = simd::avx::lengthv4f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Normalize(benchmark::State &state)
    {
        simd::Vec4f vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            simd::Vec4f res = simd::avx::normalizev4f(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Vec4Add);
    BENCHMARK(BM_Vec4Sub);
    BENCHMARK(BM_Vec4Mul);
    BENCHMARK(BM_Vec4Div);
    BENCHMARK(BM_Vec4Abs);
    BENCHMARK(BM_Vec4Min);
    BENCHMARK(BM_Vec4Max);
    BENCHMARK(BM_Vec4Sqrt);
    BENCHMARK(BM_Vec4SqrtLowp);
    BENCHMARK(BM_Vec4InvSqrt);
    BENCHMARK(BM_Vec4InvSqrtLowp);
    BENCHMARK(BM_Vec4Sin);
    BENCHMARK(BM_Vec4SinLowp);
    BENCHMARK(BM_Vec4Cos);
    BENCHMARK(BM_Vec4CosLowp);
    BENCHMARK(BM_Vec4Tan);
    BENCHMARK(BM_Vec4Cot);
    BENCHMARK(BM_Vec4Dot);
    BENCHMARK(BM_Vec4Length);
    BENCHMARK(BM_Vec4Normalize);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis