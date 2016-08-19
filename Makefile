CC    = g++
CFLAGS = -g
LIBS  = -llapack -lblas

dgemv: dgemv_example.cpp
	$(CC) $(CFLAGS) dgemv_example.cpp -o dgemv $(LIBS) 

dgemm: dgemm_example.cpp
	$(CC) $(CFLAGS) dgemm_example.cpp -o dgemm $(LIBS) 

dgesv: dgesv_example.cpp
	$(CC) $(CFLAGS) dgesv_example.cpp -o dgesv $(LIBS) 

clean:
	rm -f dgemv dgemm dgesv

help:
	-@echo "make dgemv: makes the executible "dgemv" for dgemv_example.cpp"
	-@echo "make dgemm: makes the executible "dgemm" for dgemm_example.cpp"
	-@echo "make dgesv: makes the executible "dgesv" for dgesv_example.cpp"
