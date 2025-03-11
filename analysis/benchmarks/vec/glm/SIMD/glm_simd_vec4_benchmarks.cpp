#define GLM_FORCE_INTRINSICS

#include <glm/glm.hpp>
#include <glm/gtc/type_aligned.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Vec4Add(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = vec + vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Sub(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = vec - vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Mul(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = vec * vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Div(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = vec / vec;
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec4Abs(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::abs(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Min(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::min(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Max(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::max(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec4Sqrt(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::sqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4SqrtLowp(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::sqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4InvSqrt(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::inversesqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4InvSqrtLowp(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::inversesqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec4Sin(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4SinLowp(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Cos(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::cos(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4CosLowp(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::cos(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Tan(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::tan(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Cot(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::cos(vec) / glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Vec4Dot(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            float res = glm::dot(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Length(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            float res = vec.length();
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec4Normalize(benchmark::State &state)
    {
        glm::vec4 vec(1.f, 1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec4 res = glm::normalize(vec);
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
} // namespace benchmarks
} // namespace analysis