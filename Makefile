CC=g++

SRC=binomial
FLAGS=-std=c++17

SRC_FILES=$(SRC)/*.cpp
H_FILES=$(SRC)/*.h

OBJS=$(SRC)/*.o

# remove main from object files
OBJ_FILES = $(filter-out main.cpp, $(ALL_FILES))

all: build main

# move is potentially trivial, but it keeps the project organized
build: $(SRC_FILES) $(H_FILES)
	$(CC) $(FLAGS) -c $(SRC_FILES)
	mv *.o $(SRC)/

main: $(SRC)/*.o
	$(CC) $(OBJS) $(FLAGS) main.cpp -o main