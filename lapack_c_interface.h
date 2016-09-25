

// C interfaces for lapack functions

// dgesv
extern "C" {

	// degmv performs one of the matrix-vector operations
	// y = alpha*A*x + beta*y, or y = alpha*A'*x + beta*y, where alpha and beta are scalars,
	// x and y are vectors and A is an m by n matrix.                                              
	void dgemv_(const char* trans, int* m, int* n, double* alpha, double* a, const int* lda, 
		double* x, int* incx, double* beta, double* y, int* incy);

	// dgemm performs one of the matrix-matrix operations
	// C = alpha*op(A)*op(B) + beta*C, where op(X) is one of op(X) = X or op(X) = X',
	// alpha and beta are scalars, and A, B and C are matrices, with op(A) an m by k matrix,
	// op(B) a k by n matrix and C an m by n matrix.
	void dgemm_(const char* transa, const char* transb, int* m, int* n, int* k, double* alpha, 
		double* a, int* lda, double* b, const int* ldb, double* beta, double* c, int* ldc);

	// dgesv computes the solution to a real system of linear equations A*X = B where A is an
	// N-by-N matrix and X and B are N-by-NRHS matrices
	// The LU decomposition with partial pivoting and row interchanges is used to factor A as
	// A = P*L*U where P is a permutation matrix, L is unit lower triangular, and U is upper
	// triangular. The factored form of A is then used to solve the system of equations A*X = B
	void dgesv_(const int *n, const int *nrhs,  double *a, const int  *lda, int *ipivot, double *b,
		const int *ldb, int *info);

	// dgetrf computes an LU factorization of a general M by N matrix A using partial pivoting
	// with row interchanges.
	// The factorization has the form
	// A = P*L*U
	// where P is a permutation matrix, L is lower triangular with unit diagonal elements
	// (lower trapezoidal if m>n), and U is upper traingular (upper trapezoidal if m<n).
	void dgetrf_(const int *m, const int *n, double *a, const int *lda, int *ipivot, int *info);

	// dgetrs solves a system of linear equations A*X = B or A'*X = B with a general N by N matrix
	// A using the LU factorization computed by dgetrf
	void dgetrs_(const char *trans, const int *n, const int *nhrs, const double *a, const int *lda,
		const int *ipivot, double *b, const int *ldb, int *info);

	// dpotrf computes the Cholesky factorization of a real symmetric positive definite matrix A
	void dpotrf_(const char *uplo, const int *n, double *a, const int *lda, int *info);

	// dpotrs solves a system of linear equations A*X=B with a symmetric positive definite matrix A
	// using the Cholesky factorization A = U**T*U or A = L*L**T computed by dpotrf
	void dpotrs_(const char *uplo, const int *n, const int *nrhs, const double *a, const int *lda, 
		double *b, const int *ldb, int *info);
}
