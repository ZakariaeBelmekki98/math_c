#include "LinAlg.h"
#include "SigProc.h"
#include <time.h>

int main(){
    double vector[] = {-2, 1, 0, 0, 0, 
                       -3, 0, 1, 0, 0,
                       -4, 0, 0, 1, 0,
                       -5, 0, 0, 0, 1,
                        0, -3, 2, 0, 0,
                        0, -4, 0, 2, 0,
                        0, -5, 0, 0, 2,
                        0,  0,-4, 3, 0,
                        0,  0,-5, 0, 3,
                        0,  0, 0, -5, 4};
    Matrix A, eA;
    init_mat(&A, 10, 5, vector);
    GaussPivot(&A, &eA, 1);
    print_mat(&eA);
    free_mat(&A);

    return 0x1;
}