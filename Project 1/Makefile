EXEC = run
CC = g++
CFLAGS = -c -Wall

# $(EXEC) has the value of shell variable EXEC, which is run.
# run depends on the files main.o somefile.o
$(EXEC)	: heap.o util.o main.o
# run is created by the command g++ -o run heap.o utils.o
	$(CC) -o $(EXEC) heap.o util.o main.o

# heap.o depends on the files heap.cpp and heap.h
# heap.o is created by the command g++ -c -Wall heap.cpp
heap.o	: heap.cpp heap.h
	$(CC) $(CFLAGS) heap.cpp

util.o : util.cpp util.h
	$(CC) $(CFLAGS) util.cpp

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

clean	:
	rm *.o
