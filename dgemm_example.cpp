#include <iostream>
#include "lapack_c_interface.h"

using namespace std;


/*
	MATLAB equivalent of A*B, where

       [ 2.3 3.2 3.4 5.5 2.0 2.1 ]
   		 [ 4.2 3.4 3.2 4.5 5.6 5.5 ]
   A = [ 3.4 8.5 4.3 6.5 9.9 9.2 ]
   		 [ 4.6 7.5 3.0 0.3 4.5 4.4 ]
   		 [ 0.2 4.4 2.2 5.4 2.4 2.1 ]

       [ 2.3 3.2 3.4 5.5 2.0 2.1 1.1 ]
   		 [ 4.2 3.4 3.2 4.5 5.6 5.5 4.5 ]
   B = [ 3.4 8.5 4.3 6.5 9.9 9.2 8.2 ]
   		 [ 4.6 7.5 3.0 0.3 4.5 4.4 3.4 ]
   		 [ 0.2 4.4 2.2 5.4 2.4 2.1 1.1 ]
   		 [ 1.2 5.4 3.2 6.4 3.4 3.1 1.1 ]

 			       [  58.51 108.53  60.30  75.04  92.87  88.62  68.02 ]
 			       [  63.24 140.29  82.34 125.99 111.51 105.57  73.67 ]
 	 C = A*B = [ 101.06 218.32 127.97 199.19 181.26 171.36 120.36 ]
 			       [  59.84 111.53  77.42 131.10 108.01 102.92  74.22 ]
 			       [  54.26  96.70  52.42  63.22  84.02  80.17  61.37 ]
*/

int main()
{
	int i, j;
	char no = 'N', tr = 'T';
	int m = 5, k = 6, n = 7;
	double alpha = 1.0, beta = 0.0;
	double **a, **b, **c;
	int lda = n, ldb = k, ldc = n;

	// a[n][n] contiguous 2d array
	a = new double*[m];
	a[0] = new double[m*k];
	for (i=1; i<m; i++)
		a[i] = a[i-1] + k;
	
	b = new double*[k];
	b[0] = new double[k*n];
	for (i=1; i<k; i++)
		b[i] = b[i-1] + n;

	c = new double*[m];
	c[0] = new double[m*n];
	for (i=1; i<m; i++)
		c[i] = c[i-1] + n;

	// populate matrix a : column-major --> Fortran style
	a[0][0]=2.3; a[0][1]=3.2; a[0][2]=3.4; a[0][3]=5.5; a[0][4]=2.0; a[0][5]=2.1; 
	a[1][0]=4.2; a[1][1]=3.4; a[1][2]=3.2; a[1][3]=4.5; a[1][4]=5.6; a[1][5]=5.5; 
	a[2][0]=3.4; a[2][1]=8.5; a[2][2]=4.3; a[2][3]=6.5; a[2][4]=9.9; a[2][5]=9.2; 
	a[3][0]=4.6; a[3][1]=7.5; a[3][2]=3.0; a[3][3]=0.3; a[3][4]=4.5; a[3][5]=4.4;
	a[4][0]=0.2; a[4][1]=4.4; a[4][2]=2.2; a[4][3]=5.4; a[4][4]=2.4; a[4][5]=2.1;

	// populate matrix a : column-major --> Fortran style
	b[0][0]=2.3; b[0][1]=3.2; b[0][2]=3.4; b[0][3]=5.5; b[0][4]=2.0; b[0][5]=2.1; b[0][6]=1.1;
	b[1][0]=4.2; b[1][1]=3.4; b[1][2]=3.2; b[1][3]=4.5; b[1][4]=5.6; b[1][5]=5.5; b[1][6]=4.5;
	b[2][0]=3.4; b[2][1]=8.5; b[2][2]=4.3; b[2][3]=6.5; b[2][4]=9.9; b[2][5]=9.2; b[2][6]=8.2;
	b[3][0]=4.6; b[3][1]=7.5; b[3][2]=3.0; b[3][3]=0.3; b[3][4]=4.5; b[3][5]=4.4; b[3][6]=3.4;
	b[4][0]=0.2; b[4][1]=4.4; b[4][2]=2.2; b[4][3]=5.4; b[4][4]=2.4; b[4][5]=2.1; b[4][6]=1.1;
	b[5][0]=1.2; b[5][1]=5.4; b[5][2]=3.2; b[5][3]=6.4; b[5][4]=3.4; b[5][5]=3.1; b[5][6]=1.1;

	for (i=0; i<m; i++)
	{
		for (j=0; j<k; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (i=0; i<k; i++)
	{
		for (j=0; j<n; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	// matrix-vector product
	dgemm_(&no, &no, &n, &m, &k, &alpha, &b[0][0], &lda, &a[0][0], &ldb, &beta, &c[0][0], &ldc);

	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}

	delete [] a[0];
	delete [] a;
	delete [] b[0];
	delete [] b;
	delete [] c[0];
	delete [] c;
	return 0;
}