# Makefile

CXX = g++
CFLAGS = -std=c++11
HEADERS = prototypes.h struct.h constants.h globals.h
OBJS = input.o colonies.o


all: main $(ARGS)

main : main.o $(OBJS)
	$(CXX) $(CFLAGS) -o main main.o $(OBJS)

main.o : main.cpp $(HEADERS)
	$(CXX) $(CFLAGS) main.cpp -c

words.o : words.cpp $(HEADERS)
	$(CXX) $(CFLAGS)  words.cpp -c

input.o : input.cpp $(HEADERS)
	$(CXX) $(CFLAGS)  input.cpp -c

colonies.o : colonies.cpp $(HEADERS)
	$(CXX) $(CFLAGS)  colonies.cpp -c


pristine:
	rm *.o
	rm main
	touch *