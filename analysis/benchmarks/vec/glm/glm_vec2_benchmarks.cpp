#define GLM_FORCE_INTRINSICS
#define GLM_FORCE_ALIGNED_GENTYPES

#include <glm/glm.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Vec2Add(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = vec + vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Sub(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = vec - vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Mul(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = vec * vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Div(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = vec / vec;
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec2Abs(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = glm::abs(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Min(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = glm::min(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Max(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = glm::max(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec2Sqrt(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = glm::sqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2SqrtLowp(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_lowp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_lowp> res = glm::sqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2InvSqrt(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = glm::inversesqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2InvSqrtLowp(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_lowp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_lowp> res = glm::inversesqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec2Sin(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2SinLowp(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_lowp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_lowp> res = glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Cos(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = glm::cos(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2CosLowp(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_lowp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_lowp> res = glm::cos(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Tan(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = glm::tan(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Cot(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = glm::vec<2, float, glm::aligned_highp>(1.f, 1.f) / glm::tan(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Vec2Dot(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            float res = glm::dot(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Length(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            float res = vec.length();
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec2Normalize(benchmark::State &state)
    {
        glm::vec<2, float, glm::aligned_highp> vec(1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec<2, float, glm::aligned_highp> res = glm::normalize(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    BENCHMARK(BM_Vec2Add);
    BENCHMARK(BM_Vec2Sub);
    BENCHMARK(BM_Vec2Mul);
    BENCHMARK(BM_Vec2Div);
    BENCHMARK(BM_Vec2Abs);
    BENCHMARK(BM_Vec2Min);
    BENCHMARK(BM_Vec2Max);
    BENCHMARK(BM_Vec2Sqrt);
    BENCHMARK(BM_Vec2SqrtLowp);
    BENCHMARK(BM_Vec2InvSqrt);
    BENCHMARK(BM_Vec2InvSqrtLowp);
    BENCHMARK(BM_Vec2Sin);
    BENCHMARK(BM_Vec2SinLowp);
    BENCHMARK(BM_Vec2Cos);
    BENCHMARK(BM_Vec2CosLowp);
    BENCHMARK(BM_Vec2Tan);
    BENCHMARK(BM_Vec2Cot);
    BENCHMARK(BM_Vec2Dot);
    BENCHMARK(BM_Vec2Length);
    BENCHMARK(BM_Vec2Normalize);
} // namespace benchmarks
} // namespace analysis