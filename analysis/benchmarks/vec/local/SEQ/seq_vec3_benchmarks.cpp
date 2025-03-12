#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>

#include <benchmark/benchmark.h>

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
            simd::Vec3f res = simd::seq::addv(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Sub(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::subv(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Mul(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::mulv(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Div(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::divv(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Abs(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::absv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Min(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::minv(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Max(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::maxv(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Sqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::sqrtv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3SqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::fast_sqrtv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3InvSqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::invsqrtv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3InvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::fast_invsqrtv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Sin(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::sinv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3SinLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::fast_sinv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Cos(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::cosv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3CosLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::fast_cosv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Tan(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::tanv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Cot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::cotv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Vec3Dot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            float res = simd::seq::dotv(vec, vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Length(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            float res = simd::seq::lengthv(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Normalize(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::normalizev(vec);
            benchmark::DoNotOptimize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Cross(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            simd::Vec3f res = simd::seq::crossv3(vec, vec);
            benchmark::DoNotOptimize(vec);
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