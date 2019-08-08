/* vector.c */

#include <stdio.h>

#include <intel.h>
#include <vector.h>

#define CPUID01_ECX_TEST        (   CPUID01_ECX_SSE3        | \
                                    CPUID01_ECX_PCLMULQDQ   | \
                                    CPUID01_ECX_SSSE3       | \
                                    CPUID01_ECX_FMA         | \
                                    CPUID01_ECX_SSE41       | \
                                    CPUID01_ECX_SSE42       | \
                                    CPUID01_ECX_AESNI       | \
                                    CPUID01_ECX_OSXSAVE     | \
                                    CPUID01_ECX_AVX         | \
                                    CPUID01_ECX_F16C    )

#define CPUID07_00_EBX_TEST     ( CPUID07_00_EBX_AVX2 )

#define XCR0_TEST               ( XCR0_SSE | XCR0_AVX )

int vect_checkmach(){

#if !defined(__AVX2__) || !defined(__FMA__) || !defined(__AES__) || \
    !defined(__PCLMUL__) || !defined(__F16C__)
    return 1;
#else

    unsigned int cpuid01_ecx, cpuid07_00_ebx, xcr0low;

    __asm__("cpuid"
            : "=c" (cpuid01_ecx)
            : "a" (0x1)
            : "rbx", "rdx"
           );

    if( (cpuid01_ecx & CPUID01_ECX_TEST) != CPUID01_ECX_TEST ){
        return 1;
    }

    __asm__("cpuid"
            : "=b" (cpuid07_00_ebx)
            : "a" (0x7), "c" (0x0)
            : "rdx"
           );

    if( (cpuid07_00_ebx & CPUID07_00_EBX_TEST) != CPUID07_00_EBX_TEST ){
        return 1;
    }

    __asm__("xgetbv"
            : "=a" (xcr0low)
            : "c"  (0x0)
            : "rdx"
           );

    if( (xcr0low & XCR0_TEST) != XCR0_TEST ){
        return 1;
    }

    return 0;
#endif

}

