#include <iostream>
#include "lapack_c_interface.h"

using namespace std;


/*
	MATLAB equivalent of A\B, where

      [ 2.3 3.2 3.4 5.5 2.0 2.1 ]         [ 2.3 ]
      [ 4.2 3.4 3.2 4.5 5.6 5.5 ]         [ 5.3 ]
  A =	[ 3.4 8.5 4.3 6.5 9.9 9.2 ] ,   B = [ 6.0 ]
      [ 4.6 7.5 3.0 0.3 4.5 4.4 ]         [ 5.3 ]
      [ 0.2 4.4 2.2 5.4 2.4 2.1 ]         [ 2.4 ]
                                          [ 3.2 ]

        [  1.7995 ]
        [  0.6552 ]
  A\B = [ -2.6688 ]
        [  0.9480 ]
        [ -0.0377 ]
*/

// transpose of a matrix
void dgetsp(double **a, int n);

int main(){
	int i, j;
	// Values needed for dgesv
	int n = 5;
	int nrhs = 1;
	int lda = n;
	int ldb = n;
	int info;
	double **a, **b;
	int *ipiv;

	// a[n][n] contiguous 2d array
	a = new double*[n];
	a[0] = new double[n*n];
	for (i=1; i<n; i++)
		a[i] = a[i-1] + n;

	// b[1][n] contiguous 2d array
	b = new double*[1];
	b[0] = new double[n];

	ipiv = new int[n];

	// populate matrix a : column-major --> Fortran style
	a[0][0]=2.3; a[0][1]=3.2; a[0][2]=3.4; a[0][3]=5.5; a[0][4]=2.0;
	a[1][0]=4.2; a[1][1]=3.4; a[1][2]=3.2; a[1][3]=4.5; a[1][4]=5.6;
	a[2][0]=3.4; a[2][1]=8.5; a[2][2]=4.3; a[2][3]=6.5; a[2][4]=9.9;
	a[3][0]=4.6; a[3][1]=7.5; a[3][2]=3.0; a[3][3]=0.3; a[3][4]=4.5;
	a[4][0]=0.2; a[4][1]=4.4; a[4][2]=2.2; a[4][3]=5.4; a[4][4]=2.4;	

	// transpose of a
	dgetsp(a, n);

	// populate matrix b
	b[0][0]=2.3; b[0][1]=5.3; b[0][2]=6.0; b[0][3]=5.3; b[0][4]=2.4; 

	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	for (i=0; i<n; i++)
	{
		cout << b[0][i] << " ";
		cout << endl;
	}
	
	// Solve the linear system
	dgesv_(&n, &nrhs, &a[0][0], &lda, ipiv, &b[0][0], &ldb, &info);
	
	// Check for success
	if(info == 0)
	{
	   // Write the answer
	   cout << "The answer is\n";
	   for(i = 0; i < n; i++)
	     cout << "b[" << i << "]\t" << b[0][i] << "\n";
	}
	else
	{
	   // Write an error message
	   cerr << "dgesv returned error " << info << "\n";
	}

	for (i=0; i<n; i++)
	{
		cout << ipiv[i] << " ";
	}
	cout << endl;

	delete [] a[0];
	delete [] a;
	delete [] b[0];
	delete [] b;
	delete [] ipiv;
	return info;
}

void dgetsp(double **a, int n)
{
	int i, j;
	double **tmp;
	tmp = new double*[n];
	tmp[0] = new double[n*n];
	for (i=1; i<n; i++)
		tmp[i] = tmp[i-1] + n;

	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			tmp[i][j] = a[j][i];

	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			a[i][j] = tmp[i][j];

	delete [] tmp[0];
	delete [] tmp;
}
