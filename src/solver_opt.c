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

	double *At = (double *)calloc(N * N, sizeof(double));
	double *Bt = (double *)calloc(N * N, sizeof(double));

	int index = -1;
	int i, j, k;

	for (i = 0; i < N; i++) {
		double * ai = &A[i * N];
		double * bi = &B[i * N];
		for (j = 0; j < N; j++) {
			index = j * N + i;
		
			At[index] = *ai;
			Bt[index] = *bi;

			ai++;
			bi++;
		}
	}

	double *p1 = (double *)calloc(N * N, sizeof(double));
	double *p12 = (double *)calloc(N * N, sizeof(double));


	//B*A
	for (i = 0; i < N; i++) {
    double *orig_pb = &B[i * N];

    for (j = 0; j < N; j++) {
        register double suma = 0.0;
        index = i * N + j;
        double *pb = orig_pb;
        double *pa = &A[j];

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
        double *pp1 = orig_p1;
        double *pat = &At[j];

        for (k = 0; k < N; k++) {
            
            suma += *pp1 * *pat;
            pat += N;
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
			double *pb = orig_pb;
			double *pbt = &Bt[j];

			for (k = 0; k < N; k++) {
				
				suma += *pb * *pbt;
				pbt += N;
				pb++;
			}
			p3[index] = suma;
		}
	}


	double *result = (double *)calloc(N * N, sizeof(double));

	//((B*Bt)*At) + (B*Bt)
	double *pp12 = &p12[0];
	double *pp3 = &p3[0];

	for (i = 0; i < N * N; i++) {
		result[i] = *pp12 + *pp3;
		pp12++;
		pp3++;
	}

	free(At);
	free(Bt);
	free(p1);
	free(p12);
	free(p3);


	return result;	
}
