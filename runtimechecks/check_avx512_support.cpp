#include <cpuid.h>

int main()
{
    unsigned int eax, ebx, ecx, edx;
    if (__get_cpuid_count(7, 0, &eax, &ebx, &ecx, &edx)) {
        if ((ebx & bit_AVX512F) != 0)
        {
            // supports AVX2
            return 1;
        }
    }

    // does not support AVX2
    return 0;
}