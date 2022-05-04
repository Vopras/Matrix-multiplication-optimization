/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"
#include "cblas.h"
/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	printf("BLAS SOLVER\n");

	// double *aux = (double *) calloc(N* N, sizeof(double));
	// double *aux2 = (double *) calloc(N* N, sizeof(double));
	// double *aux3 = (double *) calloc(N* N, sizeof(double));
	double *result = (double *) calloc(N* N, sizeof(double));

	// cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1, B, N, A, N, 0, aux, N);
	// cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, N, N, N, 1, aux, N, A, N, 0, aux2, N);
	// cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1, B, N, B, N, 0, aux3, N);


	// // int i, j, k;
	// // for (i = 0; i < N; i++) {
	// // 	for (j = 0; j < N; j++) {
	// // 		for (k = 0; k < N; k++) {
	// // 			result[i][j] += aux2[i][k] * aux3[k][j];
 // //      		}
 // //  		}
	// // }

	// free(aux);
	// free(aux2);
	// free(aux3);

	return result;
}
