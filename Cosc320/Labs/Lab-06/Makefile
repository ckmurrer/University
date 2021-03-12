all: Lab06_map Lab06_set

Lab06_map: Lab06_map.o
	g++ -o Lab06_map Lab06_map.o -std=c++11

Lab06_map.o: Lab06_map.cpp d_state.h
	g++ -c Lab06_map.cpp -std=c++11

Lab06_set: Lab06_set.o
	g++ -o Lab06_set Lab06_set.o -std=c++11

Lab06_set.o: Lab06_set.cpp d_state.h
	g++ -c Lab06_set.cpp -std=c++11

clean:
	-rm *.o $(objects)