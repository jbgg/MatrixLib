/* vector.h */

#ifndef __VECTOR_H__
#define __VECTOR_H__

#ifdef __AVX__

#define VECT_TYPE v256
#define VECT_NDOUBLE 4
#define VECT_SIZE 0x20
#define VECT_PDF_TYPE v4df
#define VECT_PSI_TYPE v4si
#define VECT_PUI_TYPE v4ui

#define VECT_PDF(name) (name)->pdf
#define VECT_DF(name) (name)->df

typedef double v4df __attribute__((vector_size(0x20)));
typedef long v4si __attribute__((vector_size(0x20)));
typedef unsigned long v4ui __attribute__((vector_size(0x20)));

typedef union {
    double df[4];
    v4df   pdf;
} v256 __attribute__((aligned(0x20)));

#endif

#endif /* __VECTOR_H__ */

