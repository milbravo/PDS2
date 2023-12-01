CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
TESTS   := tests
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main

EXECUTABLE2	:= mainTests

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE2)
	./$(BIN)/$(EXECUTABLE)

all: $(BIN)/$(EXECUTABLE2)


$(BIN)/$(EXECUTABLE2): $(TESTS)/*.cpp $(SRC)/modulos/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)


all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/$(EXECUTABLE).cpp $(SRC)/modulos/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
