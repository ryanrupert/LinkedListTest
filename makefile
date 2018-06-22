all: List.o Source.o
	g++ Source.o List.o

Source.o: Source.cpp
	g++ -c -std=c++11 Source.cpp -o Source.o

List.o: List.cpp
	g++ -c -std=c++11 List.cpp -o List.o
