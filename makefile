all:
	g++  *.cpp -lm -ansi -std=c++0x -pedantic -lboost_serialization -lpthread -o a.out