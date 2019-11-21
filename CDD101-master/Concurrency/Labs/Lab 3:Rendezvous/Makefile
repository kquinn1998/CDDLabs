#Kevin Quinn C00216607
#19/11/19


CC=g++
CFLAGS= -std=c++17 -pthread

%.o: %.cpp
		$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o Semaphore.o
		$(CC) -o mutex main.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)
	
DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o
