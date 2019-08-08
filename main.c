
#include <stdlib.h>

#include <matrix.h>

int _start(){

    const double mconst[3][3] __attribute__((aligned(VECT_SIZE))) = { 
        {  2.2,  1.0, -1.0 },
        { .001,  5.0,  1.0 },
        {    2, -1.0,  5.0 } 
    };

    matrix_t m;

    matrix_init(m, 3);

    matrix_set(m, (double*) mconst);

    matrix_print(m);

    matrix_clear(m);

    _Exit(0);
}

