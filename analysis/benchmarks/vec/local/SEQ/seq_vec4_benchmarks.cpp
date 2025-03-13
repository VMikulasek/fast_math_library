#include <simd/detail/vec/simd_vec4.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Vec4Add(benchmark::State &state)
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
    static void BM_Vec4Sub(benchmark::State &state)
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
    static void BM_Vec4Mul(benchmark::State &state)
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
    static void BM_Vec4Div(benchmark::State &state)
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

    static void BM_Vec4Abs(benchmark::State &state)
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
    static void BM_Vec4Min(benchmark::State &state)
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
    static void BM_Vec4Max(benchmark::State &state)
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

    static void BM_Vec4Sqrt(benchmark::State &state)
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
    static void BM_Vec4SqrtLowp(benchmark::State &state)
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
    static void BM_Vec4InvSqrt(benchmark::State &state)
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
    static void BM_Vec4InvSqrtLowp(benchmark::State &state)
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

    static void BM_Vec4Sin(benchmark::State &state)
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
    static void BM_Vec4SinLowp(benchmark::State &state)
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
    static void BM_Vec4Cos(benchmark::State &state)
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
    static void BM_Vec4CosLowp(benchmark::State &state)
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
    static void BM_Vec4Tan(benchmark::State &state)
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
    static void BM_Vec4Cot(benchmark::State &state)
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
    
    static void BM_Vec4Dot(benchmark::State &state)
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
    static void BM_Vec4Length(benchmark::State &state)
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
    static void BM_Vec4Normalize(benchmark::State &state)
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