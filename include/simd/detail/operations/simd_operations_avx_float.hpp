#ifndef SIMD_OPERATIONS_AVX_FLOAT_HPP
#define SIMD_OPERATIONS_AVX_FLOAT_HPP

#include <simd/simd_common.hpp>
#include <simd/detail/operations/simd_operations_base.hpp>

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
         * @brief Loads array of floats to register which is returned
         * 
         * @param arr Float array to load to register,
         * 8 floats will be loaded to register, so has to be
         * at least 8 floats long, also has to be aligned to 32 bytes
         * otherwise segmentation fault will be generated
         * 
         * @return Register with loaded vector
         */
        static AvxReg load_vector(const float *arr);

        /**
         * @brief Loads zeros to register which is returned
         * 
         * @return Register with zeros
         */
        static AvxReg load_zero_vector();

        /**
         * @brief Stores vector from register to float *dst
         * 
         * @param reg register to materialize
         * @param dst float * aligned to 32 bits with at least 8 floats
         * of size
         */
        static void materialize_register(AvxReg &reg, float *dst);

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
        template<AvxCmpVariant variant>
        static AvxReg cmp(AvxReg &vec1, AvxReg &vec2);

        /**
         * @brief Adds horizontal adjacent floats and stores the
         * into register (result reg: first quarter = first half of vec1
         * results, second quarter = first half of vec2 results,
         * and then second half of vec1, and finally second half of vec2)
         *  
         * @return AvxReg register with 8 result floats
         */
        static AvxReg horizontal_add(AvxReg &vec1, AvxReg &vec2);

        /**
         * @brief Blends two vector registers based on low 8 bits of mask
         * - 0 bit = vec1 element, 1 bit = vec2 element
         * 
         * @return AvxReg blended vector 
         */
        template<int mask>
        static AvxReg blend(AvxReg &vec1, AvxReg &vec2);

        /**
         * @brief Shifts both 128 bit lanes of vec 32 bits right
         * 
         * @return AvxReg shifted register
         */
        static AvxReg rotate_halves_right_32bits(AvxReg &vec);

        /**
         * @brief Shifts both 128 bit lanes of vec 32 bits left
         * 
         * @return AvxReg shifted register
         */
        static AvxReg rotate_halves_left_32bits(AvxReg &vec);

        /**
         * @brief Shifts both 128 bit lanes of vec 64 bits
         * 
         * @return AvxReg shifted register
         */
        static AvxReg rotate_halves_64bits(AvxReg &vec);

        /**
         * @brief Swaps 128 bit lines of register
         *
         * @return AvxReg register with swapped halves 
         */
        static AvxReg swap_halves(AvxReg &vec);
    };
}

#include <simd/detail/operations/simd_operations_avx_float.inl>

#endif // SIMD_OPERATIONS_AVX_FLOAT_HPP