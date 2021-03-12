main: main.o SUList.o SUQueue.o SUStack.o payroll.o
	g++ -o main main.o  SUQueue.o SUStack.o payroll.o -std=c++11

main.o: main.cpp SUList.h SUQueue.h SUStack.h payroll.h
	g++ -c main.cpp -std=c++11

SUList.o: SUList.cpp SUList.h
	g++ -c SUList.cpp -std=c++11

SUQueue.o: SUQueue.cpp SUQueue.h
	g++ -c SUQueue.cpp -std=c++11

SUStack.o: SUStack.cpp SUStack.h
	g++ -c SUStack.cpp -std=c++11

payroll.o: payroll.cpp payroll.h

clean:
	-rm *.o $(object)
