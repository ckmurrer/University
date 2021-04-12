all: pipe1 pipe3 pipe4 twoPipesParent twoPipesChild pipeFifo buildsm removesm process1 process2

pipe1: pipe1.c
	gcc -Wall pipe1.c -o pipe1

pipe3: pipe3.c
	gcc -Wall pipe3.c -o pipe3

pipe4: pipe4.c
	gcc -Wall pipe4.c -o pipe4

twoPipesParent: twoPipesParent.c
	gcc -Wall twoPipesParent.c -o twoPipesParent

twoPipesChild: twoPipesChild.c
	gcc -Wall twoPipesChild.c -o twoPipesChild

pipeFifo: pipeFifo.c
	gcc -Wall pipeFifo.c -o pipeFifo

buildsm: buildsm.c
	gcc -Wall buildsm.c -o buildsm

removesm: removesm.c
	gcc -Wall removesm.c -o removesm

process1: process1.c
	gcc -Wall process1.c -o process1

process2: process2.c
	gcc -Wall process2.c -o process2

clean:
	rm pipe1 pipe3 pipe4 twoPipesParent twoPipesChild pipeFifo buildsm removesm process1 process2