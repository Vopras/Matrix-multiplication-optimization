/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */

double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");

	int index = -1;
	int i, j, k;

	double *p1 = (double *)calloc(N * N, sizeof(double));
	double *p12 = (double *)calloc(N * N, sizeof(double));


	//B*A
for (i = 0; i < N; i++) {
    double *orig_pb = &B[i * N];

    for (j = 0; j < N; j++) {
        register double suma = 0.0;
        index = i * N + j;
        register double *pb = orig_pb;
        register double *pa = &A[j];

        for (k = 0; k <= j; k++) {
            
            suma += *pb * *pa;
            pa += N;
            pb++;
        }
        p1[index] = suma;
    }
}

	//(B*A)*At
for (i = 0; i < N; i++) {
    double *orig_p1 = &p1[i * N];

    for (j = 0; j < N; j++) {
        register double suma = 0.0;
        index = i * N + j;
        register double *pp1 = orig_p1;
        register double *pat = &A[j * N];

        for (k = 0; k < N; k++) {
            
            suma += *pp1 * *pat;
            pat++;
            pp1++;
        }
        p12[index] = suma;
    }
}

	double *p3 = (double *)calloc(N * N, sizeof(double));

	//B*Bt
	for (i = 0; i < N; i++) {
    double *orig_pb = &B[i * N];
    for (j = 0; j < N; j++) {

        register double suma = 0.0;
        index = i * N + j;
        register double *pb = orig_pb;
        register double *pbt = &B[j * N];

        for (k = 0; k < N; k++) {
            
            suma += *pb * *pbt;
            pbt++;
            pb++;
        }
        p3[index] = suma;
    }
}


	double *result = (double *)calloc(N * N, sizeof(double));

	//((B*Bt)*At) + (B*Bt)
	register double *pp12 = &p12[0];
	register double *pp3 = &p3[0];

	for (i = 0; i < N * N; i++) {
		result[i] = *pp12 + *pp3;
		pp12++;
		pp3++;
	}

	free(p1);
	free(p12);
	free(p3);


	return result;	
}
