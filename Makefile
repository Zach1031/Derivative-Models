CC=g++
DEPS = Stoc

OBJS = *.o

%.o: %.cpp
	$(CC) -c -o $@ $<

a.out: $(OBJS)
	g++ $(OBJS) main.cpp 