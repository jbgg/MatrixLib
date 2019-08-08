/* matrix.c */

#include <stdio.h>  /* for printf           */
#include <stdlib.h> /* for malloc and free  */

#include <matrix.h>

void matrix_init(matrix_t m, unsigned long n){

    /* matrix of order 0 ? */
    if(n == 0){
        m->n = n;
        m->a = NULL;
        return;
    }

    m->n = n;

    /* at this moment the elements of the matrix are saved as an array,
     * i.e., the elements are contiguous
     * there could be another approach which is allocating an array for
     * every row, in this last way, more memeory is spent but we have
     * alignment for every row
     */
    if(posix_memalign((void **) &m->a, VECT_SIZE, NVECT(n*n) * VECT_SIZE)){
        m->a = NULL;
        m->n = 0;
    }

#ifdef _DEBUG
    printf(" * NVECT(n) = %lx\n", NVECT(n*n));
    printf(" * m->a = %p\n", m->a);
#endif /* _DEBUG */
}

void matrix_clear(matrix_t m){
    if(m->a != NULL){
        free(m->a);
    }
    m->n = 0;
    m->a = NULL;
}

void matrix_set(matrix_t m, double *a){

    if(m->n == 0 || m->a == NULL){
        return;
    }

    unsigned long i;
    VECT_TYPE *d = m->a;            /* destination  */
    VECT_TYPE *s = (VECT_TYPE*) a;  /* source       */

    for(i=VECT_NDOUBLE; i<= m->n * m->n; i+=VECT_NDOUBLE){
        (d++)->pdf = (s++)->pdf;
    }
    i-=VECT_NDOUBLE;
    for(; i< m->n * m->n; i++){
        d->df[i % VECT_NDOUBLE] = s->df[i % VECT_NDOUBLE];
    }

}

double matrix_getelem(matrix_t m, unsigned long i, unsigned long j){
    return (m->a + (i*m->n+j)/VECT_NDOUBLE)->df[(i*m->n+j)%VECT_NDOUBLE];
}

void matrix_print(matrix_t m){
    unsigned long i,j;

    for(i=0; i<m->n; i++){
        for(j=0; j<m->n; j++){
            printf(" %f, ", matrix_getelem(m, i, j));
        }
        printf("\n");
    }
}

