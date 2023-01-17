#include "LinAlg.h"

void init_mat(Matrix *mat, size_t _rows, size_t _cols, double *_data){
    mat->rows = _rows;
    mat->cols = _cols;
    mat->data = malloc(_rows * _cols * sizeof(double));
    if(mat->data == NULL){
        printf("LinAlg::init_mat: malloc() for memory allocation failed.\n");
    }
    if(_data == NULL){
        printf("Allocating random values\n");
        for(int i=0; i < _rows * _cols; i++) mat->data[i] = (double)(rand() % 10);
    }
    else{
        memcpy(mat->data, _data, sizeof(double)*_rows*_cols);
    }
}

void print_mat(Matrix *mat){
    for(int i=0; i < mat->rows*mat->cols; i++){
        printf("%f ", mat->data[i]);
        if((i+1)%mat->cols == 0) printf("\n");
    }
}

void free_mat(Matrix *mat){
    free(mat->data);
    mat->data = NULL;
}

void init_compmat(ComplexMatrix *mat, size_t rows, size_t cols, double* data_re, double *data_im){
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(Complex)*rows*cols);
    if(data_re == NULL) {
        for(int i=0; i < rows*cols; i++) {
            mat->data[i].re = (double)(rand() % 10);
        }
    }else{
        // Probably not working but irrelevant 
        memcpy(&(mat->data[0].re), data_re, sizeof(double)*rows*cols);
    }

    if(data_im == NULL){
        for(int i=0; i<rows*cols; i++) mat->data[i].im = (double)(rand() % 10);
    } else{
        memcpy(&(mat->data[0].im), data_im, sizeof(double)*rows*cols);
    }
}

void free_compmat(ComplexMatrix *mat){
    free(mat->data);
    mat->rows=0;
    mat->cols=0;
}

void print_compmat(ComplexMatrix *mat){
    for(int i=0; i < mat->cols*mat->rows; i++){
        if(i%(mat->cols) == 0) printf("\n");
        print_comp(&(mat->data[i]));
    }
    printf("\n");
}




void neg(Matrix *A, Matrix *out){
    if(A->data == NULL){
        printf("LinAlg::neg(A, out) [Memory Error] Matrix A has no allocated memory.\n");
        exit(0);
    }
    
    size_t _rows = A->rows;
    size_t _cols = A->cols;
    out->rows = _rows;
    out->cols = _cols;
    out->data = malloc(_cols * _rows * sizeof(double));

    for(int i=0; i<_rows*_cols; i++) out->data[i] = -(A->data[i]);
}

void matadd(Matrix *A, Matrix *B, Matrix *out){
    if(A->data == NULL || B->data == NULL){
        printf("LinAlg::matadd(A, B, out) [Memory Error] A or B have no allocated memory.\n");
        exit(0);
    }
    
    if(A->rows != B->rows || A->cols != B->cols){
        printf("LinAlg::matadd(A, B, out) [Math Error] A and B must have the same size.\n");
        exit(0);
    }
    size_t _rows = A->rows;
    size_t _cols = A->cols;
    
    out->rows = _rows;
    out->cols = _cols;
    out->data = malloc(_cols * _rows * sizeof(double));   

    for(int i=0; i<_rows*_cols; i++) out->data[i] = A->data[i]+B->data[i];
}
void compmat_add(ComplexMatrix *A, ComplexMatrix *B, ComplexMatrix *out){
    if(A->data == NULL || B->data == NULL){
        printf("LinAlg::matadd(A, B, out) [Memory Error] A or B have no allocated memory.\n");
        exit(0);
    }
    
    if(A->rows != B->rows || A->cols != B->cols){
        printf("LinAlg::matadd(A, B, out) [Math Error] A and B must have the same size.\n");
        exit(0);
    }
    size_t _rows = A->rows;
    size_t _cols = A->cols;
    out->rows = _rows;
    out->cols = _cols;
    out->data = malloc(_cols * _rows * sizeof(Complex));   
    for(int i=0; i<_rows*_cols; i++) compadd(&A->data[i], &B->data[i], &out->data[i]);
}


void matsub(Matrix *A, Matrix *B, Matrix *out){
    if(A->data == NULL || B->data == NULL){
        printf("LinAlg::matsub(A, B, out) [Memory Error] A or B have no allocated memory.\n");
        exit(0);
    }
    
    if(A->rows != B->rows || A->cols != B->cols){
        printf("LinAlg::matsub(A, B, out) [Math Error] A and B must have the same size.\n");
        exit(0);
    }
    size_t _rows = A->rows;
    size_t _cols = A->cols;
    out->rows = _rows;
    out->cols = _cols;
    out->data = malloc(_cols * _rows * sizeof(double));
    for(int i=0; i<_rows*_cols; i++) out->data[i] = A->data[i]-B->data[i];
}

void matmul(Matrix *A, Matrix *B, Matrix *out){
    // Remark: this implementation of naive matmul is fasted than the standard one by around 10%
    if(A->cols != B->rows){
        printf("LinAlg::matmul(A, B, out) [Math Error] A and B have invalid sizes for matrix multiplication.\n");
    }
    size_t _rows = A->rows;
    size_t _cols = B->cols;
    size_t mid = A->cols;
    out->cols = _cols;
    out->rows = _rows;
    out->data = calloc(_cols*_rows, sizeof(double));
    for(int i=0; i < _rows * mid; i++){
        for(int j=0; j < _cols; j++){
            out->data[i/mid*_cols+j] += A->data[i] * B->data[i%mid*_cols+j];
        }
    }
}

void GaussPivot(Matrix* A, Matrix *out, int RANGE_FLAG){
    size_t w, h;
    w = A->cols;
    h = A->rows;
    
    out->rows = h;
    out->cols = w;
    out->data = calloc(h*w, sizeof(double));
    memcpy(out->data, A->data, h*w*sizeof(double));

    for(int i=0; i<w; i++){
        double pivot = out->data[i*(1+w)];
        if(pivot == 0) continue;
        double coef = 0;
        for(int j = i+1; j < h; j++){
            if(out->data[j*w+i] == 0) continue;
            coef = out->data[j*w+i]/pivot;
            for(int k=0; k<w; k++) out->data[j*w+k] -= coef * out->data[i*w+k];
        }
    }
    if(RANGE_FLAG!=0){
        int counter = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j < w; j++){
                if(abs(out->data[i*w+j]) > 1e-4){
                    counter++;
                    break;
                }
            }
        }
        printf("Le rang de la matrix est %d\n", counter);
    }
}