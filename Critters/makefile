
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJ = 

SRCS = main.cpp doodlebug.cpp ant.cpp critter.cpp

HEADERS = doodlebug.hpp ant.hpp critter.hpp

assignment-2: main.cpp doodlebug.cpp ant.cpp critter.cpp doodlebug.hpp ant.hpp critter.hpp
	g++ -std=c++0x main.cpp doodlebug.cpp ant.cpp critter.cpp -o assignment-2

#target: dependencies
	#rule to build
