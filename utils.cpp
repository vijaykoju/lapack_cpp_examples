#include "utils.h"

int* ivector_malloc(int m)
{
	int* a = new int[m];
	return a;
}

double* dvector_malloc(int m)
{
	double* a = new double[m];
	return a;
}

int** imatrix_malloc(int m, int n)
{
	int** a = new int*[m];
	a[0] = new int[m*n];
	if (m > 1)
		for (int i=1; i<m; i++)
			a[i] = a[i-1] + n;
	return a;
}

double** dmatrix_malloc(int m, int n)
{
	double** a = new double*[m];
	a[0] = new double[m*n];
	if (m > 1)
		for (int i=1; i<m; i++)
			a[i] = a[i-1] + n;
	return a;
}

void dmatrix_dealloc(double **a)
{
	delete [] a[0];
	delete [] a;
}

void imatrix_dealloc(int **a)
{
	delete [] a[0];
	delete [] a;
}

void ivector_dealloc(int *a)
{
	delete [] a;
}

void dvector_dealloc(double *a)
{
	delete [] a;
}

void print_dvector(double *a, int m)
{
	cout << endl;
	for (int i=0; i<m; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << endl;
}

void print_dmatrix(double **a, int m, int n)
{
	cout << endl;
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

// compute the transpose of a square matrix A and store it in A.
void sqrmatrix_transpose(double **a, int n)
{
	int i, j;
	double **tmp = dmatrix_malloc(n, n);

	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			tmp[i][j] = a[j][i];

	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			a[i][j] = tmp[i][j];

	delete [] tmp[0];
	delete [] tmp;
}
