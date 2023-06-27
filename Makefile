CC=g++

OBJS=*.o

ALL_FILES = $(wildcard *.cpp)

# remove main from object files
OBJ_FILES = $(filter-out main.cpp, $(ALL_FILES))

all: build main

build: *.cpp *.h
	$(CC) -c $(OBJ_FILES)

%.o: %.cpp %.h
	$(CC) -c -o $@ $<

main: $(ALL_FILES)
	$(CC) $(OBJS) main.cpp -o main