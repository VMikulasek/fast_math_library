#ifndef SIMD_OPERATIONS_AVX_FLOAT_HPP
#define SIMD_OPERATIONS_AVX_FLOAT_HPP

#include "./simd_operations_base.hpp"
#include "../vector/simd_vector_avx_float.hpp"

#include <immintrin.h>

namespace simd
{
    /**
     * @brief Enum represeting variants of AVX comparison
     */
    enum AvxCmpVariant
    {
        EQ = 0,
        NEQ = 12,
        LT = 17,
        LE = 18,
        GE = 29,
        GT = 30
    };

    template<>
    class SIMDOperations<float, InstructionSet::AVX>
    {
    private:
        using NumType = float;
        static const InstructionSet INS_SET = InstructionSet::AVX;

    public:
        /**
         * @brief 256 b vector register, works as intermediate result,
         * has to be materialized for the value
         */
        using AvxReg = __m256;

        /**
         * @brief Loads vector of floats to register which is returned
         * 
         * @param vector Vector of floats to load to register
         * @return Register with loaded vector
         */
        static AvxReg load_vector(SIMDVector<NumType, INS_SET> &vector);

        /**
         * @brief Stores vector from register to memory and returns
         * wrapped in SIMDVector
         * 
         * @param register 
         * @return SIMDVector<float, InstructionSet::AVX> Content of register
         */
        static SIMDVector<NumType, INS_SET> materialize_register(AvxReg &reg);

        /**
         * @brief Adds vec1 and vec2 and returns result
         */
        static AvxReg add(AvxReg &vec1, AvxReg &vec2);

        /**
         * @brief Subtracts vec2 from vec1 and returns result
         */
        static AvxReg sub(AvxReg &vec1, AvxReg &vec2);

        /**
         * @brief Multiplies vec1 with vec1 and returns result
         */
        static AvxReg mul(AvxReg &vec1, AvxReg &vec2);

        /**
         * @brief Divides vec1 by vec2 and returns result
         */
        static AvxReg div(AvxReg &vec1, AvxReg &vec2);

        /**
         * @brief Computes bitwise and of vec1 and vec2 and returns result
         */
        static AvxReg bitwise_and(AvxReg &vec1, AvxReg &vec2);

        /**
         * @brief Computes bitwise or of vec1 and vec2 and returns result
         */
        static AvxReg bitwise_or(AvxReg &vec1, AvxReg &vec2);

        /**
         * @brief Computes bitwise xor of vec1 and vec2 and returns result
         */
        static AvxReg bitwise_xor(AvxReg &vec1, AvxReg &vec2);

        /**
         * @brief Compares every float in vector with cmp variant based on
         * parameter variant and stores into result on each index either all
         * 0 or all 1
         * 
         * @param variant Variant of comparison {EQ, NEQ, LT, LE, GT, GE}
         */
        static AvxReg cmp(AvxReg &vec1, AvxReg &vec2, AvxCmpVariant variant);
    };
}

#include "simd_operations_avx_float.inl"

#endif // SIMD_OPERATIONS_AVX_FLOAT_HPP