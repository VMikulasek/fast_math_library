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
        static AvxReg set_register_zero();

        /**
         * @brief Sets every field of register to num
         */
        static AvxReg set_register(float num);

        /**
         * @brief Stores vector from register to float *dst
         * 
         * @param reg register to materialize
         * @param dst float * aligned to 32 bytes with at least 8 floats
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
         * @tparam variant Variant of comparison {EQ, NEQ, LT, LE, GT, GE}
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
         * @brief Rotates both 128 bit lanes of vec 32 bits right
         * 
         * @return AvxReg rotated register
         */
        static AvxReg rotate_halves_right_32bits(AvxReg &vec);

        /**
         * @brief Rotates both 128 bit lanes of vec 32 bits left
         * 
         * @return AvxReg rotated register
         */
        static AvxReg rotate_halves_left_32bits(AvxReg &vec);

        /**
         * @brief Rotates both 128 bit lanes of vec 64 bits
         * 
         * @return AvxReg rotated register
         */
        static AvxReg rotate_halves_64bits(AvxReg &vec);

        /**
         * @brief Swaps 128 bit lines of register
         *
         * @return AvxReg register with swapped halves 
         */
        static AvxReg swap_halves(AvxReg &vec);

        /**
         * @brief Permutes numbers in register via pseudocode:
         * DEFINE SELECT4(src, control) {
	     *      CASE(control[1:0]) OF
	     *      0:	tmp[31:0] := src[31:0]
	     *      1:	tmp[31:0] := src[63:32]
	     *      2:	tmp[31:0] := src[95:64]
	     *      3:	tmp[31:0] := src[127:96]
	     *      ESAC
	     *      RETURN tmp[31:0]
         * }
         * dst[31:0] := SELECT4(vec[127:0], pattern[1:0])
         * dst[63:32] := SELECT4(vec[127:0], pattern[3:2])
         * dst[95:64] := SELECT4(vec[127:0], pattern[5:4])
         * dst[127:96] := SELECT4(vec[127:0], pattern[7:6])
         * dst[159:128] := SELECT4(a[255:128], pattern[1:0])
         * dst[191:160] := SELECT4(a[255:128], pattern[3:2])
         * dst[223:192] := SELECT4(a[255:128], pattern[5:4])
         * dst[255:224] := SELECT4(a[255:128], pattern[7:6])
         * dst[MAX:256] := 0
         * 
         * @return AvxReg permuted register
         */
        template<int pattern>
        static AvxReg permute_reg_inside_halves(AvxReg &vec);

        /**
         * @brief Copies low half of register
         * and pastes to the high half
         */
        static AvxReg distribute_low_half(AvxReg &vec);

        /**
         * @brief Copies high half of register
         * and pastes to the low half
         */
        static AvxReg distribute_high_half(AvxReg &vec);
    };
} // namespace simd

#include <simd/detail/operations/simd_operations_avx_float.inl>

#endif // SIMD_OPERATIONS_AVX_FLOAT_HPP