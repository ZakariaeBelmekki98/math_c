#include "SigProc.h"

void convolve2D(Matrix* data, Matrix* kernel, Matrix* out){
    out->cols = kernel->cols + data->cols - 1;
    out->rows = kernel->rows + data->rows - 1;
    out->data = calloc(out->cols * out->rows, sizeof(double));
    /*
    for(int i=0; i < out->rows; i++){
        for(int j=0; j < out->cols; j++){
            for(int m=0; m < kernel->rows; m++){
                for(int n=0; n < kernel->cols; n++){
                    if(i-m >= 0 && i-m < data->rows && j-n >= 0 && j-n < data->cols){
                        printf("[%d %d] += [%d %d] * [%d %d]\n", i, j, m, n, i-m, j-n);
                        out->data[i*out->cols+j] += kernel->data[m*kernel->cols+n] * data->data[(i-m)*data->cols+j-n];   
                    }
                }
            }
        }
    }*/
    for(int m=0; m < out->rows; m++){
        for(int n=0; n < out->cols; n++){
            for(int i=0; i < data->rows; i++){
                for(int j=0; j < data->cols; j++){
                    if(m-i >= 0 && m-i < kernel->rows && n-j >= 0 && n-j < kernel->cols){
                        out->data[m*out->cols+n] += data->data[i*data->cols + j] * kernel->data[(m-i)*kernel->cols+n-j];
                    }
                }
            }
        }
    }
}

void dft2D(Matrix* data, Matrix* out){
    out->rows = data->rows;
    out->cols = data->cols;
    out->data = calloc(out->rows*out->cols, sizeof(double));

    for(int i=0; i < out->rows/2; i++){
        for(int j=0; j < out->cols/2; j++){
            for(int m=0; m < data->rows; m++){
                for(int n=0; n < data->cols; n++){

                }
            }

        }
    }
}