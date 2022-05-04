/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("NEOPT SOLVER\n");

	double *At = (double *)calloc(N * N, sizeof(double));
	double *Bt = (double *)calloc(N * N, sizeof(double));
	
	int index = -1;
	int index1 = -1;
	int index2 = -1;
	

	int i, j, k;
	// calculate A^t and B^t
	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index1 = i * N + j;
			index2 = j * N + i;

			At[index2] = A[index1];
			Bt[index2] = B[index1];
		}
	}
	
	double *temp1 = (double *)calloc(N * N, sizeof(double));
	double *temp2 = (double *)calloc(N * N, sizeof(double));

	index1 = -1;
	index2 = -1;

	// calculate A*A^t and B^t*B
	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index = i * N + j;
			for ( k = 0; k < N; k++) {
				index1 = i * N + k;
				index2 = k * N + j;
				
				temp1[index] += A[index1] * At[index2];
				temp2[index] += Bt[index1] * B[index2];
			}
		}
	}
	
	index1 = -1;
	index2 = -1;

double *temp3 = (double *)calloc(N * N, sizeof(double));

	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index = i * N + j;
			for ( k = 0; k < N; k++) {
				index1 = i * N + k;
				index2 = k * N + j;
				
				temp3[index] += B[index1] * temp1[index2];

			}
		}
	}

	double *res = (double *)calloc(N * N, sizeof(double));

	for (i = 0; i < N * 2; i++) {
		res[i] = temp3[i] + temp2[i];
	}

	free(temp1);
	free(temp2);
	free(temp3);
	free(At);
	free(Bt);

	return res;
}
