CC     = g++
CFLAGS = -g
LIBS   = -llapack -lblas

dgemv: dgemv_example.cpp
	$(CC) $(CFLAGS) dgemv_example.cpp utils.cpp -o dgemv $(LIBS) 

dgemm: dgemm_example.cpp
	$(CC) $(CFLAGS) dgemm_example.cpp utils.cpp -o dgemm $(LIBS) 

dgesv: dgesv_example.cpp
	$(CC) $(CFLAGS) dgesv_example.cpp utils.cpp -o dgesv $(LIBS) 

dgetrf: dgetrf_dgetrs_example.cpp
	$(CC) $(CFLAGS) dgetrf_dgetrs_example.cpp utils.cpp -o dgetrf $(LIBS) 

clean:
	rm -f dgemv dgemm dgesv dgetrf

help:
	-@echo "make dgemv : makes the executible "dgemv" for dgemv_example.cpp"
	-@echo "make dgemm : makes the executible "dgemm" for dgemm_example.cpp"
	-@echo "make dgesv : makes the executible "dgesv" for dgesv_example.cpp"
	-@echo "make dgetrf: makes the executible "dgetrf" for dgesv_example.cpp"
