

// C interfaces for lapack functions

// dgesv
extern "C" {
	void dgesv_(int *n, int *nrhs,  double *a,  int  *lda,  
		int *ipivot, double *b, int *ldb, int *info) ;

	// product c= alpha*a*b + beta*c                                               
	void dgemm_(const char* transa, const char* transb, int* m,
		int* n, int* k, double* alpha, double* a,
		int* lda, double* b, const int* ldb, double* beta,
		double* c, int* ldc);

	// product y = alpha*a*x + beta*y                                               
	void dgemv_(const char* trans, int* m, int* n,
		double* alpha, double* a, const int* lda, double* x,
		int* incx, double* beta, double* y, int* incy);

	void dpotrf_(const char *, const int *, double *,
  	const int *, int *);

	void dpotrs_(const char *, const int *, const int *,
  	const double *, const int *, double *, const int *, int *);
}
