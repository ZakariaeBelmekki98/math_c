#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "Complex.h"

typedef struct {
    double *data;
    size_t rows, cols;
} Matrix;

typedef struct {
    Complex *data;
    size_t rows, cols;
} ComplexMatrix;

void init_mat(Matrix *mat, size_t _rows, size_t _cols, double* data);
void free_mat(Matrix *mat);
void print_mat(Matrix *mat);

void init_compmat(ComplexMatrix *mat, size_t rows, size_t cols, double* data_re, double *data_im);
void free_compmat(ComplexMatrix *mat);
void print_compmat(ComplexMatrix *mat);
/* Basic Matrix operations */

void neg(Matrix *A, Matrix *out);
void matmul(Matrix *A, Matrix *B, Matrix *out);
void matmul2(Matrix *A, Matrix *B, Matrix *out);
void matadd(Matrix *A, Matrix *B, Matrix *out);
void matsub(Matrix *A, Matrix *B, Matrix *out);

void compmat_add(ComplexMatrix *A, ComplexMatrix *B, ComplexMatrix *out);

void GaussPivot(Matrix * A, Matrix *out, int RANGE_FLAG);