#include <simd/detail/vec/simd_vec4.hpp>
#include <simd/detail/vec/VEC/simd_vec4_vec.hpp>
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
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::vec::addv4<float, simd::InstructionSet::AVX>(vec, vec);
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
            simd::Vec4f res = simd::vec::subv4<float, simd::InstructionSet::AVX>(vec, vec);
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
            simd::Vec4f res = simd::vec::mulv4<float, simd::InstructionSet::AVX>(vec, vec);
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
            simd::Vec4f res = simd::vec::divv4<float, simd::InstructionSet::AVX>(vec, vec);
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
            simd::Vec4f res = simd::vec::absv4<float, simd::InstructionSet::AVX>(vec);
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
            simd::Vec4f res = simd::vec::minv4<float, simd::InstructionSet::AVX>(vec, vec);
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
            simd::Vec4f res = simd::vec::maxv4<float, simd::InstructionSet::AVX>(vec, vec);
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

#ifdef HAS_AVX2

    static void BM_SqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::vec::fast_sqrtv4<float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

#endif // HAS_AVX2

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

#ifdef HAS_AVX2

    static void BM_InvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::vec::fast_invsqrtv4<float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

#endif // HAS_AVX2

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
            simd::Vec4f res = simd::vec::fast_sinv4<float, simd::InstructionSet::AVX>(vec);
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
            simd::Vec4f res = simd::vec::fast_cosv4<float, simd::InstructionSet::AVX>(vec);
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
            float res = simd::vec::dotv4<float, simd::InstructionSet::AVX>(vec, vec);
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
            float res = simd::vec::lengthv4<float, simd::InstructionSet::AVX>(vec);
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
            simd::Vec4f res = simd::vec::normalizev4<float, simd::InstructionSet::AVX>(vec);
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