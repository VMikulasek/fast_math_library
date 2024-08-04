#include <cpuid.h>

int main()
{
    unsigned int eax, ebx, ecx, edx;
    if (__get_cpuid_count(1, 0, &eax, &ebx, &ecx, &edx)) {
        if ((ecx & bit_AVX) != 0)
        {
            // supports AVX
            return 1;
        }
    }

    // does not support AVX
    return 0;
}