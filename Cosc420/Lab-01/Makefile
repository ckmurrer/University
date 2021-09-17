all: hello bigNumbers

hello: hello.c
	mpicc -std=c99 hello.c -o hello

bigNumbers: bigNumbers.c
	mpicc -std=c99 bigNumbers.c -o bigNumbers -lm

clean:
	rm hello bigNumbers
