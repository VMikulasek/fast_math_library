#ifndef SIMD_VEC_VEC_INL
#define SIMD_VEC_VEC_INL

#include <simd/detail/vec/VEC/simd_vec_vec.hpp>
#include <simd/simd_operations_avx.hpp>
#include <simd/simd_common.hpp>
#include <mathops/detail/VEC/avx_transcedentals.hpp>

#include <cmath>

namespace simd
{
namespace vec
{
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> addv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            auto reg1 = Ops::load_vector(&(vec1.data[i]));
            auto reg2 = Ops::load_vector(&(vec2.data[i]));

            auto resReg = Ops::add(reg1, reg2);

            Ops::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = vec1.data[i] + vec2.data[i];
        }

        return result;
    }
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> subv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            auto reg1 = Ops::load_vector(&(vec1.data[i]));
            auto reg2 = Ops::load_vector(&(vec2.data[i]));

            auto resReg = Ops::sub(reg1, reg2);

            Ops::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = vec1.data[i] - vec2.data[i];
        }

        return result;
    }
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> mulv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            auto reg1 = Ops::load_vector(&(vec1.data[i]));
            auto reg2 = Ops::load_vector(&(vec2.data[i]));

            auto resReg = Ops::mul(reg1, reg2);

            Ops::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = vec1.data[i] * vec2.data[i];
        }
        
        return result;
    }
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> divv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            auto reg1 = Ops::load_vector(&(vec1.data[i]));
            auto reg2 = Ops::load_vector(&(vec2.data[i]));

            auto resReg = Ops::div(reg1, reg2);

            Ops::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = vec1.data[i] / vec2.data[i];
        }
        
        return result;
    }

    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> absv(const Vec<L, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            auto reg = Ops::load_vector(&(vec.data[i]));

            auto resReg = Ops::abs(reg);

            Ops::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = std::abs(vec.data[i]);
        }
        
        return result;
    }
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> minv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            auto reg1 = Ops::load_vector(&(vec1.data[i]));
            auto reg2 = Ops::load_vector(&(vec2.data[i]));

            auto resReg = Ops::min(reg1, reg2);

            Ops::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = std::min(vec1.data[i], vec2.data[i]);
        }
        
        return result;
    }
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> maxv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            auto reg1 = Ops::load_vector(&(vec1.data[i]));
            auto reg2 = Ops::load_vector(&(vec2.data[i]));

            auto resReg = Ops::max(reg1, reg2);

            Ops::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = std::max(vec1.data[i], vec2.data[i]);
        }
        
        return result;
    }

    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> fast_sqrtv(const Vec<L, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;
        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            mathops::avx::fast_sqrt_arr(&(vec.data[i]), L, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = mathops::fast_sqrt(vec.data[i]);
        }
        
        return result;
    }
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> fast_invsqrtv(const Vec<L, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;
        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            mathops::avx::fast_invsqrt_arr(&(vec.data[i]), L, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = mathops::fast_invsqrt(vec.data[i]);
        }
        
        return result;
    }

    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> fast_sinv(const Vec<L, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;
        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            mathops::avx::fast_sin_arr(&(vec.data[i]), L, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = mathops::fast_sin(vec.data[i]);
        }
        
        return result;
    }
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> fast_cosv(const Vec<L, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;
        Vec<L, T> result;

        size_t i = 0;

        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            mathops::avx::fast_cos_arr(&(vec.data[i]), L, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = mathops::fast_cos(vec.data[i]);
        }
        
        return result;
    }

    template<size_t L, typename T, InstructionSet S>
    inline T dotv(const Vec<L, T> &vec1, const Vec<L, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        T result = 0;

        size_t i = 0;
        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            auto reg1 = Ops::load_vector(&(vec1.data[i]));
            auto reg2 = Ops::load_vector(&(vec2.data[i]));

            auto tmpResReg = Ops::mul(reg1, reg2);
            auto zeroReg = Ops::set_register_zero();
            tmpResReg = Ops::horizontal_add(tmpResReg, zeroReg);
            tmpResReg = Ops::horizontal_add(tmpResReg, zeroReg);

            alignas(Ops::ALIGNMENT) T tmpRes[Ops::REG_SIZE];
            Ops::materialize_register(tmpResReg, tmpRes);

            result += tmpRes[0] + tmpRes[4];
        }

        for (; i < L; i++)
        {
            result += vec1.data[i] * vec2.data[i];
        }

        return result;
    }
    template<size_t L, typename T, InstructionSet S>
    inline T lengthv(const Vec<L, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;
        
        T length = 0;
        auto tmpResult = Ops::set_register_zero();

        size_t i = 0;
        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            auto loaded = Ops::load_vector(&(vec.data[i]));
            loaded = Ops::mul(loaded, loaded);
            tmpResult = Ops::add(tmpResult, loaded);
        }

        for (; i < L; i++)
        {
            length += vec.data[i] * vec.data[i];
        }

        tmpResult = Ops::horizontal_add(tmpResult, tmpResult);
        tmpResult = Ops::horizontal_add(tmpResult, tmpResult);
        length += Ops::materialize_register_at_index(tmpResult, 0) + Ops::materialize_register_at_index(tmpResult, 4);

        return mathops::sqrt(length);
    }
    template<size_t L, typename T, InstructionSet S>
    inline Vec<L, T> normalizev(const Vec<L, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        T length = lengthv<L, T, S>(vec);
        auto lengthReg = Ops::set_register(length);

        Vec<L, T> normalized;

        size_t i = 0;
        for (; i + Ops::REG_SIZE < L; i += Ops::REG_SIZE)
        {
            auto loaded = Ops::load_vector(&(vec.data[i]));
            auto normalizedReg = Ops::div(loaded, lengthReg);
            Ops::materialize_register(normalizedReg, &(normalized.data[i]));
        }

        for (; i < L; i++)
        {
            normalized.data[i] = vec.data[i] / length;
        }

        return normalized;
    }
} // namespace vec
} // namespace simd

#endif // SIMD_VEC_VEC_INL