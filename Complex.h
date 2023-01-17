#include <math.h>
#include <stdio.h>

typedef struct{
    double re, im;
} Complex;

typedef struct{
    double freq, pha;
} ComplexExp;

void compadd(Complex *a, Complex *b, Complex *out);
void compsub(Complex *a, Complex *b, Complex *out);
void compmult(Complex *a, Complex *b, Complex *out);
void compexp_val(ComplexExp *a, Complex *out);
void print_comp(Complex *a);
void print_compexp(ComplexExp *a);

