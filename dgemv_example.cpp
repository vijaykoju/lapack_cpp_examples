#include "lapack_c_interface.h"
#include "utils.h"

/*
	MATLAB equivalent of A*B, where

      [ 2.3 3.2 3.4 5.5 2.0 2.1 ]         [ 2.3 ]
      [ 4.2 3.4 3.2 4.5 5.6 5.5 ]         [ 5.3 ]
  A = [ 3.4 8.5 4.3 6.5 9.9 9.2 ] ,   B = [ 6.0 ]
      [ 4.6 7.5 3.0 0.3 4.5 4.4 ]         [ 5.3 ]
      [ 0.2 4.4 2.2 5.4 2.4 2.1 ]         [ 2.4 ]
                                          [ 3.2 ]

        [ 83.32  ]
        [ 101.77 ]
  A*B = [ 166.32 ]
        [ 94.80  ]
        [ 78.08  ]
*/

int main()
{
	int i, j;
	char no = 'N', tr = 'T';
	int m = 5, n = 6;
	double alpha = 1.0, beta = 0.0;
	double **a, *x, *y;
	int lda = n, incx = 1, incy = 1;

	a = dmatrix_malloc(m, n);
	x = dvector_malloc(n);
	y = dvector_malloc(m);

	// populate matrix a
	a[0][0]=2.3; a[0][1]=3.2; a[0][2]=3.4; a[0][3]=5.5; a[0][4]=2.0; a[0][5]=2.1; 
	a[1][0]=4.2; a[1][1]=3.4; a[1][2]=3.2; a[1][3]=4.5; a[1][4]=5.6; a[1][5]=5.5; 
	a[2][0]=3.4; a[2][1]=8.5; a[2][2]=4.3; a[2][3]=6.5; a[2][4]=9.9; a[2][5]=9.2; 
	a[3][0]=4.6; a[3][1]=7.5; a[3][2]=3.0; a[3][3]=0.3; a[3][4]=4.5; a[3][5]=4.4;
	a[4][0]=0.2; a[4][1]=4.4; a[4][2]=2.2; a[4][3]=5.4; a[4][4]=2.4; a[4][5]=2.1;

	// populate matrix x
	x[0]=2.3; x[1]=5.3; x[2]=6.0; x[3]=5.3; x[4]=2.4; x[5]=3.2; 

	print_dmatrix(a, m, n);
	print_dvector(x, n);

	// matrix-vector product
	dgemv_(&tr, &n, &m, &alpha, &a[0][0], &lda, x, &incx, &beta, y, &incy);

	print_dvector(y, m);

	dmatrix_dealloc(a);
	dvector_dealloc(x);
	dvector_dealloc(y);
	return 0;
}
