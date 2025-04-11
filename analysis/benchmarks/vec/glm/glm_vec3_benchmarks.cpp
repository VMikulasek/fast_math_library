#define GLM_FORCE_INTRINSICS
#define GLM_FORCE_ALIGNED_GENTYPES

#include <glm/glm.hpp>

#include <benchmark/benchmark.h>

namespace analysis
{
namespace benchmarks
{
    static void BM_Add(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = vec + vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Sub(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = vec - vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Mul(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = vec * vec;
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Div(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = vec / vec;
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Abs(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::abs(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Min(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::min(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Max(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::max(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Sqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::sqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_SqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_lowp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_lowp> res = glm::sqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_InvSqrt(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::inversesqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_InvSqrtLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_lowp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_lowp> res = glm::inversesqrt(vec);
            benchmark::DoNotOptimize(res);
        }
    }

    static void BM_Sin(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_SinLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_lowp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_lowp> res = glm::sin(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Cos(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::cos(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_CosLowp(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_lowp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_lowp> res = glm::cos(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Tan(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::tan(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Cot(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::vec<3, float, glm::aligned_highp>(num, num, num) / glm::tan(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    
    static void BM_Dot(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = glm::dot(vec, vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Length(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            float res = length(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Normalize(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::normalize(vec);
            benchmark::DoNotOptimize(res);
        }
    }
    static void BM_Cross(benchmark::State &state)
    {
        volatile float num = std::rand();
        glm::vec<3, float, glm::aligned_highp> vec(num, num, num);

        for (auto _ : state)
        {
            benchmark::DoNotOptimize(vec);
            glm::vec<3, float, glm::aligned_highp> res = glm::cross(vec, vec);
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
    BENCHMARK(BM_Cross);
} // namespace benchmarks
} // namespace analysis