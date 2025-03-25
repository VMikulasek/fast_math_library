#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/detail/vec/VEC/simd_vec3_vec.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
#ifdef HAS_AVX

    static void BM_Vec3fAdd(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::addv3v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fSub(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::subv3v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fMul(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::mulv3v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fDiv(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::divv3v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3fAbs(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::absv3v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fMin(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::minv3v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fMax(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::maxv3v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3fSqrt(benchmark::State &state)
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
    static void BM_Vec3fSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::fast_sqrtv3v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fInvSqrt(benchmark::State &state)
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
    static void BM_Vec3fInvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::fast_invsqrtv3v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3fSin(benchmark::State &state)
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
    static void BM_Vec3fSinLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::fast_sinv3v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fCos(benchmark::State &state)
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
    static void BM_Vec3fCosLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::fast_cosv3v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fTan(benchmark::State &state)
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
    static void BM_Vec3fCot(benchmark::State &state)
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
    
    static void BM_Vec3fDot(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::avx::dotv3v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fLength(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = simd::avx::lengthv3v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fNormalize(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::normalizev3v<float, simd::InstructionSet::AVX>(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3fCross(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::avx::crossv3v<float, simd::InstructionSet::AVX>(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Vec3fAdd);
    BENCHMARK(BM_Vec3fSub);
    BENCHMARK(BM_Vec3fMul);
    BENCHMARK(BM_Vec3fDiv);
    BENCHMARK(BM_Vec3fAbs);
    BENCHMARK(BM_Vec3fMin);
    BENCHMARK(BM_Vec3fMax);
    BENCHMARK(BM_Vec3fSqrt);
    BENCHMARK(BM_Vec3fSqrtLowp);
    BENCHMARK(BM_Vec3fInvSqrt);
    BENCHMARK(BM_Vec3fInvSqrtLowp);
    BENCHMARK(BM_Vec3fSin);
    BENCHMARK(BM_Vec3fSinLowp);
    BENCHMARK(BM_Vec3fCos);
    BENCHMARK(BM_Vec3fCosLowp);
    BENCHMARK(BM_Vec3fTan);
    BENCHMARK(BM_Vec3fCot);
    BENCHMARK(BM_Vec3fDot);
    BENCHMARK(BM_Vec3fLength);
    BENCHMARK(BM_Vec3fNormalize);
    BENCHMARK(BM_Vec3fCross);

#endif // HAS_AVX
} // namespace benchmarks
} // namespace analysis