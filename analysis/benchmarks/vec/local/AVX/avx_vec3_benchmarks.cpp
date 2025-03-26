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
            simd::Vec3f res = simd::vec::addv3<float, simd::InstructionSet::AVX>(vec, vec);
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
            simd::Vec3f res = simd::vec::subv3<float, simd::InstructionSet::AVX>(vec, vec);
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
            simd::Vec3f res = simd::vec::mulv3<float, simd::InstructionSet::AVX>(vec, vec);
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
            simd::Vec3f res = simd::vec::divv3<float, simd::InstructionSet::AVX>(vec, vec);
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
            simd::Vec3f res = simd::vec::absv3<float, simd::InstructionSet::AVX>(vec);
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
            simd::Vec3f res = simd::vec::minv3<float, simd::InstructionSet::AVX>(vec, vec);
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
            simd::Vec3f res = simd::vec::maxv3<float, simd::InstructionSet::AVX>(vec, vec);
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

#ifdef HAS_AVX2

    static void BM_Vec3fSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::vec::fast_sqrtv3<float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

#endif // HAS_AVX2

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

#ifdef HAS_AVX2

    static void BM_Vec3fInvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        simd::Vec3f vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            simd::Vec3f res = simd::vec::fast_invsqrtv3<float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(vec);
            benchmark::DoNotOptimize(res);
        }
    }

#endif // HAS_AVX2

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
            simd::Vec3f res = simd::vec::fast_sinv3<float, simd::InstructionSet::AVX>(vec);
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
            simd::Vec3f res = simd::vec::fast_cosv3<float, simd::InstructionSet::AVX>(vec);
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
            float res = simd::vec::dotv3<float, simd::InstructionSet::AVX>(vec, vec);
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
            float res = simd::vec::lengthv3<float, simd::InstructionSet::AVX>(vec);
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
            simd::Vec3f res = simd::vec::normalizev3<float, simd::InstructionSet::AVX>(vec);
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
            simd::Vec3f res = simd::vec::crossv3v<float, simd::InstructionSet::AVX>(vec, vec);
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