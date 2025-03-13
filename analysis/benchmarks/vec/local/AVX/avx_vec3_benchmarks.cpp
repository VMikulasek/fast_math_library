#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/detail/vec/AVX/simd_vec3_avx_float.hpp>

#include <benchmark/benchmark.h>

#undef addv3f
#undef subv3f
#undef mulv3f
#undef divv3f
#undef absv3f
#undef minv3f
#undef maxv3f
#undef fast_sqrtv3f
#undef fast_invsqrtv3f
#undef fast_sinv3f
#undef fast_cosv3f
#undef dotv3f
#undef lengthv3f
#undef normalizev3f
#undef crossv3f

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Vec3Add(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::addv3f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Sub(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::subv3f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Mul(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::mulv3f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Div(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::divv3f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Abs(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::absv3f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Min(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::minv3f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Max(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::maxv3f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Sqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::seq::sqrtv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3SqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::fast_sqrtv3f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3InvSqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::seq::invsqrtv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3InvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::fast_invsqrtv3f(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Sin(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::seq::sinv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3SinLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::fast_sinv3f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Cos(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::seq::cosv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3CosLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::fast_cosv3f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Tan(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::seq::tanv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Cot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::seq::cotv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Vec3Dot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::avx::dotv3f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Length(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::avx::lengthv3f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Normalize(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::normalizev3f(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Cross(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::crossv3f(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Vec3Add);
    BENCHMARK(BM_Vec3Sub);
    BENCHMARK(BM_Vec3Mul);
    BENCHMARK(BM_Vec3Div);
    BENCHMARK(BM_Vec3Abs);
    BENCHMARK(BM_Vec3Min);
    BENCHMARK(BM_Vec3Max);
    BENCHMARK(BM_Vec3Sqrt);
    BENCHMARK(BM_Vec3SqrtLowp);
    BENCHMARK(BM_Vec3InvSqrt);
    BENCHMARK(BM_Vec3InvSqrtLowp);
    BENCHMARK(BM_Vec3Sin);
    BENCHMARK(BM_Vec3SinLowp);
    BENCHMARK(BM_Vec3Cos);
    BENCHMARK(BM_Vec3CosLowp);
    BENCHMARK(BM_Vec3Tan);
    BENCHMARK(BM_Vec3Cot);
    BENCHMARK(BM_Vec3Dot);
    BENCHMARK(BM_Vec3Length);
    BENCHMARK(BM_Vec3Normalize);
    BENCHMARK(BM_Vec3Cross);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis