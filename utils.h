#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;

int* ivector_malloc(int m);
double* dvector_malloc(int m);
int** imatrix_malloc(int m, int n);
double** dmatrix_malloc(int m, int n);
void dmatrix_dealloc(double **a);
void imatrix_dealloc(int **a);
void ivector_dealloc(int *a);
void dvector_dealloc(double *a);

void print_dvector(double *a, int m);
void print_dmatrix(double **a, int m, int n);


// compute the transpose of a square matrix A and store it in A.
void sqrmatrix_transpose(double **a, int n);

#endif
