CC=g++

SRC=src
FLAGS=-std=c++17

SRC_FILES=$(SRC)/*.cpp
H_FILES=$(SRC)/*.h
OBJS=$(SRC)/out/*.o

main: main.cpp $(OBJS) $(SRC_FILES) $(H_FILES)
	$(CC) $(OBJS) $(FLAGS) main.cpp -o main

# move is potentially trivial, but it keeps the project organized
$(SRC)/out/*.o: 
	$(CC) $(FLAGS) -c $(SRC_FILES)
	mv *.o $(SRC)/out