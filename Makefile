CC=g++
DEPS = Stoc

FILES = *.cpp
OBJS = *.o


%.o: %.cpp
	$(CC) -c -o $@ $<

main: $(OBJS) $(FILES)
	g++ $(OBJS) main.cpp -o main