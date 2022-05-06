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

	double *Bt_B = (double *) calloc(N* N, sizeof(double));
	double *result = (double *) calloc(N* N, sizeof(double));

	// cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1, B, N, A, N, 0, aux, N);
	// cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, N, N, N, 1, aux, N, A, N, 0, aux2, N);
	
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1, B, N, B, N, 0, Bt_B, N);


	//B*A devine B
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1, A, N, B, N);


	
	//B*A*At devine B
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans, CblasNonUnit, N, N, 1, A, N, B, N);



	int i;
	for (i = 0; i < N * N; i++) {
		result[i] = B[i] + Bt_B[i];
	}


	free(Bt_B);

	return result;
}
