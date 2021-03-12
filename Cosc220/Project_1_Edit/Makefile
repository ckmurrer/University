main: main.o course.o student.o studentDB.o
	g++ -o StudentDB main.o course.o student.o studentDB.o -std=c++11

main.o: main.cpp student.h studentDB.h course.h
	g++ -c main.cpp -std=c++11

course.o: course.cpp course.h
	g++ -c course.cpp -std=c++11

student.o: student.cpp student.h
	g++ -c student.cpp -std=c++11

studentDB.o: studentDB.cpp student.h studentDB.h course.h
	g++ -c studentDB.cpp -std=c++11
