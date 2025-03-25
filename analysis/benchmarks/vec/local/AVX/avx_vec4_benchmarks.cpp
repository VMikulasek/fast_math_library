#include <simd/detail/vec/simd_vec4.hpp>
#include <simd/detail/vec/VEC/simd_vec4_vec.hpp>
#include <simd/simd_common.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Vec4fAdd(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::addv4v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4fSub(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::subv4v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4fMul(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::mulv4v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4fDiv(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::divv4v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec4fAbs(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::absv4v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4fMin(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::minv4v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4fMax(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::maxv4v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec4fSqrt(benchmark::State &state)
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
    static void BM_Vec4fSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::fast_sqrtv4v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4fInvSqrt(benchmark::State &state)
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
    static void BM_Vec4fInvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::fast_invsqrtv4v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec4fSin(benchmark::State &state)
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
    static void BM_Vec4fSinLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::fast_sinv4v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4fCos(benchmark::State &state)
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
    static void BM_Vec4fCosLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::fast_cosv4v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4fTan(benchmark::State &state)
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
    static void BM_Vec4fCot(benchmark::State &state)
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
    
    static void BM_Vec4fDot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::avx::dotv4v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4fLength(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::avx::lengthv4v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4fNormalize(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec4f vec(num, num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec4f res = simd::avx::normalizev4v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Vec4fAdd);
    BENCHMARK(BM_Vec4fSub);
    BENCHMARK(BM_Vec4fMul);
    BENCHMARK(BM_Vec4fDiv);
    BENCHMARK(BM_Vec4fAbs);
    BENCHMARK(BM_Vec4fMin);
    BENCHMARK(BM_Vec4fMax);
    BENCHMARK(BM_Vec4fSqrt);
    BENCHMARK(BM_Vec4fSqrtLowp);
    BENCHMARK(BM_Vec4fInvSqrt);
    BENCHMARK(BM_Vec4fInvSqrtLowp);
    BENCHMARK(BM_Vec4fSin);
    BENCHMARK(BM_Vec4fSinLowp);
    BENCHMARK(BM_Vec4fCos);
    BENCHMARK(BM_Vec4fCosLowp);
    BENCHMARK(BM_Vec4fTan);
    BENCHMARK(BM_Vec4fCot);
    BENCHMARK(BM_Vec4fDot);
    BENCHMARK(BM_Vec4fLength);
    BENCHMARK(BM_Vec4fNormalize);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis