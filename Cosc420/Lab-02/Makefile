all: vectors main

main: matrix.o main.o matrix.h
	mpicc -std=c99 matrix.o main.o -o main

vectors: vectors.c
	mpicc -std=c99 vectors.c -o vectors

main.o: main.c matrix.h
	mpicc -c main.c -std=c99

matrix.o: matrix.c matrix.h
	mpicc -c matrix.c -std=c99

clean:
	rm vectors main main.o matrix.o
