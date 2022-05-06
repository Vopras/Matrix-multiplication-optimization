/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"
#include <stdlib.h>
/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("NEOPT SOLVER\n");

	double *A_transpose = (double *)calloc(N * N, sizeof(double));
	double *B_transpose = (double *)calloc(N * N, sizeof(double));
	
	int index_result = -1;
	int index_left = -1;
	int index_right = -1;
	int i, j, k;

for ( i = 0; i < N; i++) {
	for ( j = 0; j < N; j++) {
		index_left = i * N + j;
		index_right = j * N + i;

		A_transpose[index_right] = A[index_left];
		B_transpose[index_right] = B[index_left];
	}
}
	
	double *A_A_transpose = (double *)calloc(N * N, sizeof(double));
	

	index_left = -1;
	index_right = -1;


	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index_result = i * N + j;
			for ( k = j;  k < N; k++) {
				index_left = i * N + k;
				index_right = k * N + j;
				
				A_A_transpose[index_result] += A[index_left] * 
										A_transpose[index_right];
			}
		}
	}

	double *B_transpose_B = (double *)calloc(N * N, sizeof(double));

	index_left = -1;
	index_right = -1;


	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index_result = i * N + j;
			for ( k = 0;  k < N; k++) {
				index_left = i * N + k;
				index_right = k * N + j;
				
				B_transpose_B[index_result] += B_transpose[index_left] * 
										B[index_right];
			}
		}
	}
	
	index_left = -1;
	index_right = -1;

double *temp = (double *)calloc(N * N, sizeof(double));

	for ( i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			index_result = i * N + j;
			for ( k = 0; k < N; k++) {
				index_left = i * N + k;
				index_right = k * N + j;
				
				temp[index_result] += B[index_left] * 
										A_A_transpose[index_right];

			}
		}
	}

	double *result = (double *)calloc(N * N, sizeof(double));

	for (i = 0; i < N * N; i++) {
		result[i] = temp[i] + B_transpose_B[i];
	}

	free(A_transpose);
	free(B_transpose);
	free(A_A_transpose);
	free(B_transpose_B);
	free(temp);
	

	return result;
}