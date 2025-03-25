#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/detail/vec/VEC/simd_vec2_vec.hpp>
#include <simd/simd_common.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Vec2fAdd(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::addv2v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2fSub(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::subv2v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2fMul(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::mulv2v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2fDiv(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::divv2v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec2fAbs(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::absv2v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2fMin(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::minv2v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2fMax(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::maxv2v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec2fSqrt(benchmark::State &state)
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
    static void BM_Vec2fSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::fast_sqrtv2v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2fInvSqrt(benchmark::State &state)
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
    static void BM_Vec2fInvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::fast_invsqrtv2v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec2fSin(benchmark::State &state)
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
    static void BM_Vec2fSinLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::fast_sinv2v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2fCos(benchmark::State &state)
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
    static void BM_Vec2fCosLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::fast_cosv2v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2fTan(benchmark::State &state)
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
    static void BM_Vec2fCot(benchmark::State &state)
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
    
    static void BM_Vec2fDot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::avx::dotv2v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2fLength(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::avx::lengthv2v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2fNormalize(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec2f vec(num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec2f res = simd::avx::normalizev2v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Vec2fAdd);
    BENCHMARK(BM_Vec2fSub);
    BENCHMARK(BM_Vec2fMul);
    BENCHMARK(BM_Vec2fDiv);
    BENCHMARK(BM_Vec2fAbs);
    BENCHMARK(BM_Vec2fMin);
    BENCHMARK(BM_Vec2fMax);
    BENCHMARK(BM_Vec2fSqrt);
    BENCHMARK(BM_Vec2fSqrtLowp);
    BENCHMARK(BM_Vec2fInvSqrt);
    BENCHMARK(BM_Vec2fInvSqrtLowp);
    BENCHMARK(BM_Vec2fSin);
    BENCHMARK(BM_Vec2fSinLowp);
    BENCHMARK(BM_Vec2fCos);
    BENCHMARK(BM_Vec2fCosLowp);
    BENCHMARK(BM_Vec2fTan);
    BENCHMARK(BM_Vec2fCot);
    BENCHMARK(BM_Vec2fDot);
    BENCHMARK(BM_Vec2fLength);
    BENCHMARK(BM_Vec2fNormalize);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis