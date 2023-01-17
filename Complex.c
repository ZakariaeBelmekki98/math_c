#include "Complex.h"

void compadd(Complex *a, Complex *b, Complex *out){
    out->re = a->re + b->re;
    out->im = a->im + b->im;
}

void compsub(Complex *a, Complex *b, Complex *out){
    out->re = a->re - b->re;
    out->im = a->im - b->re;
}

void compmult(Complex* a, Complex *b, Complex *out){
    out->re = a->re*b->re - a->im*b->im;
    out->im = a->re*b->im + a->im*a->re;
}

void compexp_val(ComplexExp *a, Complex *out){
    out->re = cos(a->freq + a->pha);
    out->im = -sin(a->freq+a->pha);
}

void print_comp(Complex *a){
    printf("%f + i %f ", a->re, a->im);
}

void print_compexp(ComplexExp *a){
    printf("exp(-j(%f) + %f)\n", a->freq, a->pha);
}