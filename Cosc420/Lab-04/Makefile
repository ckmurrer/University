all: main filewriter

main: matrix.o main.o matrix.h
	mpicc -std=c99 -g matrix.o main.o -o main

main.o: main.c matrix.h
	mpicc -c main.c -g -std=c99

matrix.o: matrix.c matrix.h
	mpicc -c matrix.c -g -std=c99

filewriter: filewriter.o
	mpicc -std=c99 -g filewriter.o -o filewriter

filewriter.o: filewriter.c
	mpicc -c filewriter.c -g -std=c99

clean:
	rm main main.o matrix.o filewriter
