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
        using Reg = __m256;

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
        static Reg load_vector(const float *arr);

        /**
         * @brief Loads zeros to register which is returned
         * 
         * @return Register with zeros
         */
        static Reg set_register_zero();

        /**
         * @brief Sets every field of register to num
         */
        static Reg set_register(float num);

        /**
         * @brief Sets each field of register to corresponding number
         */
        static Reg set_register_each(float num1, float num2, float num3,
            float num4, float num5, float num6, float num7, float num8);

        /**
         * @brief Stores vector from register to float *dst
         * 
         * @param reg register to materialize
         * @param dst float * aligned to 32 bytes with at least 8 floats
         * of size
         */
        static void materialize_register(const Reg &reg, float *dst);

        /**
         * @brief Returns float from register at given index.
         * 
         * @param reg register to materialize from
         * @param index index of float to materialize
         */
        static float materialize_register_at_index(const Reg &reg, unsigned index);

        /**
         * @brief Adds vec1 and vec2 and returns result
         */
        static Reg add(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Subtracts vec2 from vec1 and returns result
         */
        static Reg sub(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Multiplies vec1 with vec1 and returns result
         */
        static Reg mul(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Divides vec1 by vec2 and returns result
         */
        static Reg div(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Computes bitwise and of vec1 and vec2 and returns result
         */
        static Reg bitwise_and(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Computes bitwise or of vec1 and vec2 and returns result
         */
        static Reg bitwise_or(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Computes bitwise xor of vec1 and vec2 and returns result
         */
        static Reg bitwise_xor(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Compares every float in vector with cmp variant based on
         * parameter variant and stores into result on each index either all
         * 0 or all 1
         * 
         * @tparam variant Variant of comparison {EQ, NEQ, LT, LE, GT, GE}
         */
        template<AvxCmpVariant variant>
        static Reg cmp(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Adds horizontal adjacent floats and stores the
         * into register (result reg: first quarter = first half of vec1
         * results, second quarter = first half of vec2 results,
         * and then second half of vec1, and finally second half of vec2)
         *  
         * @return Reg register with 8 result floats
         */
        static Reg horizontal_add(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Blends two vector registers based on low 8 bits of mask
         * - 0 bit = vec1 element, 1 bit = vec2 element
         * 
         * @return Reg blended vector 
         */
        template<int mask>
        static Reg blend(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Rotates both 128 bit lanes of vec 32 bits right
         * 
         * @return Reg rotated register
         */
        static Reg rotate_halves_right_32bits(const Reg &vec);

        /**
         * @brief Rotates both 128 bit lanes of vec 32 bits left
         * 
         * @return Reg rotated register
         */
        static Reg rotate_halves_left_32bits(const Reg &vec);

        /**
         * @brief Rotates both 128 bit lanes of vec 64 bits
         * 
         * @return Reg rotated register
         */
        static Reg rotate_halves_64bits(const Reg &vec);

        /**
         * @brief Swaps 128 bit lines of register
         *
         * @return Reg register with swapped halves 
         */
        static Reg swap_halves(const Reg &vec);

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
         * @return Reg permuted register
         */
        template<int pattern>
        static Reg permute_reg_inside_halves(const Reg &vec);

        /**
         * @brief Copies low half of register
         * and pastes to the high half
         */
        static Reg distribute_low_half(const Reg &vec);

        /**
         * @brief Copies high half of register
         * and pastes to the low half
         */
        static Reg distribute_high_half(const Reg &vec);

        /**
         * @brief Rounds every float in register
         */
        static Reg round(const Reg &vec);

        /**
         * @brief Performs abs on every float in register
         */
        static Reg abs(const Reg &vec);

        /**
         * @brief Performs min between corresponding floats in registers
         */
        static Reg min(const Reg &vec1, const Reg &vec2);

        /**
         * @brief Performs max between corresponding floats in registers
         */
        static Reg max(const Reg &vec1, const Reg &vec2);
    };
} // namespace simd

#include <simd/detail/operations/simd_operations_avx_float.inl>

#endif // SIMD_OPERATIONS_AVX_FLOAT_HPP