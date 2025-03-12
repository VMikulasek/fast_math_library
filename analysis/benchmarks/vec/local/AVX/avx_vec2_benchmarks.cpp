#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/detail/vec/AVX/simd_vec2_avx_float.hpp>

#include <benchmark/benchmark.h>

#undef addv2f
#undef subv2f
#undef mulv2f
#undef divv2f
#undef absv2f
#undef minv2f
#undef maxv2f
#undef fast_sqrtv2f
#undef fast_invsqrtv2f
#undef fast_sinv2f
#undef fast_cosv2f
#undef dotv2f
#undef lengthv2f
#undef normalizev2f

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Vec2Add(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::addv2f(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Sub(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::subv2f(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Mul(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::mulv2f(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Div(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::divv2f(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec2Abs(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::absv2f(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Min(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::minv2f(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Max(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::maxv2f(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec2Sqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::seq::sqrtv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2SqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::fast_sqrtv2f(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2InvSqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::seq::invsqrtv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2InvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::fast_invsqrtv2f(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec2Sin(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::seq::sinv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2SinLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::fast_sinv2f(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Cos(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::seq::cosv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2CosLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::fast_cosv2f(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Tan(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::seq::tanv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Cot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::seq::cotv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Vec2Dot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            float res = simd::avx::dotv2f(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Length(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            float res = simd::avx::lengthv2f(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Normalize(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            simd::Vec2f res = simd::avx::normalizev2f(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Vec2Add);
    BENCHMARK(BM_Vec2Sub);
    BENCHMARK(BM_Vec2Mul);
    BENCHMARK(BM_Vec2Div);
    BENCHMARK(BM_Vec2Abs);
    BENCHMARK(BM_Vec2Min);
    BENCHMARK(BM_Vec2Max);
    BENCHMARK(BM_Vec2Sqrt);
    BENCHMARK(BM_Vec2SqrtLowp);
    BENCHMARK(BM_Vec2InvSqrt);
    BENCHMARK(BM_Vec2InvSqrtLowp);
    BENCHMARK(BM_Vec2Sin);
    BENCHMARK(BM_Vec2SinLowp);
    BENCHMARK(BM_Vec2Cos);
    BENCHMARK(BM_Vec2CosLowp);
    BENCHMARK(BM_Vec2Tan);
    BENCHMARK(BM_Vec2Cot);
    BENCHMARK(BM_Vec2Dot);
    BENCHMARK(BM_Vec2Length);
    BENCHMARK(BM_Vec2Normalize);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis