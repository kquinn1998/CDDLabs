#Kevin Quinn C00216607
#19/11/19


CC=g++
CFLAGS= -std=c++17 -pthread -g -Wall -Wextra

%.o: %.cpp
		$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o Semaphore.o SafeBuffer.o
		$(CC) -o run main.o Semaphore.o SafeBuffer.o $(CFLAGS) $(DEBUGFLAGS)
	
DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o
DOC:
	doxygen
