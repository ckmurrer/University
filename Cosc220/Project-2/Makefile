main: main.o hanoistack.o
	g++ -o main main.o hanoistack.o -std=c++11

main.o: main.cpp hanoistack.h
	g++ -c main.cpp -std=c++11

hanoistack.o: hanoistack.cpp hanoistack.h
	g++ -c hanoistack.cpp -std=c++11
