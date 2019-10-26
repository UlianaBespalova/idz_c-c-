.PHONY: all clean install uninstall

CXX = g++
INCLUDES= -I./3rdparty/cppunit/include
CXXFLAGS=-ggdb3 $(INCLUDES) -std=c++11 -Wall
LINKFLAGS= -lcppunit
SRC_STUDY_LIB = data.c

all: tests_cppunit program
	echo "done"

tests_cppunit:
	g++ -ggdb3 -I./3rdparty/cppunit/include -std=c++11 -Wall tests_cppunit.cpp data.o -o tests_cppunit -lcppunit


clean:
	rm -rf *.o build/prog build/tests_cppunit

install:
	sudo cp ./build/prog /usr/local/bin

uninstall:
	sudo rm /usr/local/bin/prog




