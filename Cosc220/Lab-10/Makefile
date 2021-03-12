main: main.o Employee.o
	g++ -o main main.o Employee.o -std=c++11

main.o: main.cpp Employee.h
	g++ -c main.cpp -std=c++11

Employee.o: Employee.cpp Employee.h
	g++ -c Employee.cpp -std=c++11

clean:
	-rm *.o $(objects)
