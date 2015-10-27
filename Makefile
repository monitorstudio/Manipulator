CC=clang
CXX=clang++
CFLAGS=-Wall -Wextra -pedantic -Ofast
CXXFLAGS=-Wall -Wextra -pedantic -Ofast

all: main Manipulator Motor
	$(CXX) $(CXXFLAGS) -o main main.o Manipulator.o Motor.o -llua

main: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Manipulator: Manipulator.cpp Manipulator.h
	$(CXX) $(CXXFLAGS) -c Manipulator.cpp

Motor: Motor.cpp Motor.h
	$(CXX) $(CXXFLAGS) -c Motor.cpp

.PHONY clean:
	rm *.o main
