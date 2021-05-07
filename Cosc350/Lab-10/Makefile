all: msgQsnd msgQrcv task2 task3

msgQsnd: msgQsnd.c
	gcc msgQsnd.c -o msgQsnd

msgQrcv: msgQrcv.c
	gcc -Wall msgQrcv.c -o msgQrcv

task2: task2.c
	gcc -pthread task2.c -o task2

task3: task3.c
	gcc -pthread task3.c -o task3

clean:
	rm msgQsnd msgQrcv task2 task3