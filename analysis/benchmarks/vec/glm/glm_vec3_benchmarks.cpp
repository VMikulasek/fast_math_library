#define GLM_FORCE_INTRINSICS
#define GLM_FORCE_ALIGNED_GENTYPES

#include <glm/glm.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Vec3Add(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = vec + vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Sub(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = vec - vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Mul(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = vec * vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Div(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = vec / vec;
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Abs(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = glm::abs(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Min(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = glm::min(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Max(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = glm::max(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Sqrt(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = glm::sqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3SqrtLowp(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_lowp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_lowp> res = glm::sqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3InvSqrt(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = glm::inversesqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3InvSqrtLowp(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_lowp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_lowp> res = glm::inversesqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Sin(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3SinLowp(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_lowp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_lowp> res = glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Cos(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = glm::cos(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3CosLowp(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_lowp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_lowp> res = glm::cos(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Tan(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = glm::tan(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Cot(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = glm::vec<3, float, glm::aligned_highp>(num, num, num) / glm::tan(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Vec3Dot(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            float res = glm::dot(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Length(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            float res = vec.length();
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Normalize(benchmark::State &state)
    {
        volatile float num = 1.f;
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            glm::vec<3, float, glm::aligned_highp> res = glm::normalize(vec);
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
} // namespace benchmarks
} // namespace analysis