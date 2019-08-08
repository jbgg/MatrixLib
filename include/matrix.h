/* matrix.h */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector.h>

#define NVECT(n) ((n + VECT_NDOUBLE - 1) / VECT_NDOUBLE)

/* TODO: define type for order */
typedef struct {
    VECT_TYPE *a;           /* array            */
    unsigned long n;        /* order of matrix  */
} _matrix_struct;

typedef _matrix_struct matrix_t[1];
typedef _matrix_struct *matrix_ptr;


void matrix_init(matrix_t, unsigned long);
void matrix_clear(matrix_t);

void matrix_set(matrix_t, double*);

double matrix_getelem(matrix_t, unsigned long, unsigned long);

void matrix_print(matrix_t);

#endif /* __MATRIX_H__ */

