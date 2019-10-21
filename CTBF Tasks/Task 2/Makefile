#Joseph Kehoe 13/9/2017
#First simple Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++17 -pthread

%.o: %.cpp
		$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main2.o Semaphore.o
		$(CC) -o mutex main2.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)
	
DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	rm *.o
