main: main.o Mystack.o payroll.o
	g++ -o main main.o Mystack.o payroll.o -std=c++11

main.o: main.cpp Mystack.h
	g++ -c main.cpp -std=c++11

Mystack.o: Mystack.cpp Mystack.h
	g++ -c Mystack.cpp -std=c++11

payroll.o: payroll.cpp payroll.h
	g++ -c payroll.cpp -std=c++11

clean:
	-rm *.o $(objects)
