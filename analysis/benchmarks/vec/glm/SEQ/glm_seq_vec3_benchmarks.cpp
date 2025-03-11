#define GLM_FORCE_PURE

#include <glm/glm.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Vec3Add(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = vec + vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Sub(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = vec - vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Mul(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = vec * vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Div(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = vec / vec;
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Abs(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::abs(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Min(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::min(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Max(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::max(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Sqrt(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::sqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3SqrtLowp(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::sqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3InvSqrt(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::inversesqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3InvSqrtLowp(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::inversesqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Vec3Sin(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3SinLowp(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Cos(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::cos(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3CosLowp(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::cos(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Tan(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::tan(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Cot(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::cos(vec) / glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Vec3Dot(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            float res = glm::dot(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Length(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            float res = vec.length();
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Vec3Normalize(benchmark::State &state)
    {
        glm::vec3 vec(1.f, 1.f, 1.f);

        for (auto _ : state)
        {
            glm::vec3 res = glm::normalize(vec);
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