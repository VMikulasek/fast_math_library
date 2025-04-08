#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/detail/vec/VEC/simd_vec2_vec.hpp>
#include <simd/simd_common.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Add(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::addv2<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Sub(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::subv2<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Mul(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::mulv2<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Div(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::divv2<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Abs(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::absv2<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Min(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::minv2<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Max(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::maxv2<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Sqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::seq::sqrtv(vec);
            benchmark::DoNotOptimize(res);
        }
    }

#ifdef HAS_AVX2

    static void BM_SqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::fast_sqrtv2<float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

#endif // HAS_AVX2

    static void BM_InvSqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::seq::invsqrtv(vec);
            benchmark::DoNotOptimize(res);
        }
    }

#ifdef HAS_AVX2

    static void BM_InvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::fast_invsqrtv2<float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

#endif // HAS_AVX2

    static void BM_Sin(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::seq::sinv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_SinLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::fast_sinv2<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Cos(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::seq::cosv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_CosLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::fast_cosv2<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Tan(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::seq::tanv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Cot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::seq::cotv(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Dot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::vec::dotv2<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Length(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::vec::lengthv2<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Normalize(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::vec::normalizev2<float, simd::InstructionSet::AVX>(vec);
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