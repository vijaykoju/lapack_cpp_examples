#include "lapack_c_interface.h"
#include "utils.h"

/*
	MATLAB equivalent of A\B, where

      [ 2.3 3.2 3.4 5.5 2.0 2.1 ]         [ 2.3 ]
      [ 4.2 3.4 3.2 4.5 5.6 5.5 ]         [ 5.3 ]
  A = [ 3.4 8.5 4.3 6.5 9.9 9.2 ] ,   B = [ 6.0 ]
      [ 4.6 7.5 3.0 0.3 4.5 4.4 ]         [ 5.3 ]
      [ 0.2 4.4 2.2 5.4 2.4 2.1 ]         [ 2.4 ]
                                          [ 3.2 ]

        [  1.7995 ]
        [  0.6552 ]
  A\B = [ -2.6688 ]
        [  0.9480 ]
        [ -0.0377 ]
*/

int main()
{
	int i, j;
	// Values needed for dgesv
	int n = 5;
	int nrhs = 1;
	int lda = n;
	int ldb = n;
	int info;
	int *ipiv;
	double **a, **b;
	char no = 'N', tr = 'T';

	a = dmatrix_malloc(n,n);
	b = dmatrix_malloc(1,n);
	ipiv = ivector_malloc(n);

	// populate matrix a : column-major --> Fortran style
	a[0][0]=2.3; a[0][1]=3.2; a[0][2]=3.4; a[0][3]=5.5; a[0][4]=2.0;
	a[1][0]=4.2; a[1][1]=3.4; a[1][2]=3.2; a[1][3]=4.5; a[1][4]=5.6;
	a[2][0]=3.4; a[2][1]=8.5; a[2][2]=4.3; a[2][3]=6.5; a[2][4]=9.9;
	a[3][0]=4.6; a[3][1]=7.5; a[3][2]=3.0; a[3][3]=0.3; a[3][4]=4.5;
	a[4][0]=0.2; a[4][1]=4.4; a[4][2]=2.2; a[4][3]=5.4; a[4][4]=2.4;	

	// populate matrix b
	b[0][0]=2.3; b[0][1]=5.3; b[0][2]=6.0; b[0][3]=5.3; b[0][4]=2.4; 

	print_dmatrix(a, n, n);
	print_dmatrix(b, 1, n);

	// without calling external matrix transpose function
	// Solve the linear system
	dgetrf_(&n, &n, &a[0][0], &lda, ipiv, &info);
	dgetrs_(&tr, &n, &nrhs, &a[0][0], &lda, ipiv, &b[0][0], &ldb, &info);
	
	// Check for success
	if(info == 0)
	{
		cout << "The answer is\n";
		print_dmatrix(b, 1, n);
	}
	else
	{
	   cerr << "dgetrs returned error " << info << "\n";
	}

	///////////////////////////////////////////////////////////////////////

	// populate matrix a : column-major --> Fortran style
	a[0][0]=2.3; a[0][1]=3.2; a[0][2]=3.4; a[0][3]=5.5; a[0][4]=2.0;
	a[1][0]=4.2; a[1][1]=3.4; a[1][2]=3.2; a[1][3]=4.5; a[1][4]=5.6;
	a[2][0]=3.4; a[2][1]=8.5; a[2][2]=4.3; a[2][3]=6.5; a[2][4]=9.9;
	a[3][0]=4.6; a[3][1]=7.5; a[3][2]=3.0; a[3][3]=0.3; a[3][4]=4.5;
	a[4][0]=0.2; a[4][1]=4.4; a[4][2]=2.2; a[4][3]=5.4; a[4][4]=2.4;	

	// populate matrix b
	b[0][0]=2.3; b[0][1]=5.3; b[0][2]=6.0; b[0][3]=5.3; b[0][4]=2.4; 

	// calling external matrix transpose function
	sqrmatrix_transpose(a, n);
	
	print_dmatrix(a, n, n);
	print_dmatrix(b, 1, n);

	// Solve the linear system
	dgetrf_(&n, &n, &a[0][0], &lda, ipiv, &info);
	dgetrs_(&no, &n, &nrhs, &a[0][0], &lda, ipiv, &b[0][0], &ldb, &info);
	
	// Check for success
	if(info == 0)
	{
		cout << "The answer is\n";
		print_dmatrix(b, 1, n);
	}
	else
	{
	   cerr << "dgetrs returned error " << info << "\n";
	}

	dmatrix_dealloc(a);
	dmatrix_dealloc(b);
	ivector_dealloc(ipiv);
	return info;
}
