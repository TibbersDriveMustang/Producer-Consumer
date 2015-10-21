# Define required macros here
# Team member: Hongyi Guo
SHELL = /bin/sh

File = program

OBJS = main.o producerFunctions.o consumerFunctions.o
CFLAG = -Wall -g
CC = g++
INCLUDES =
LIBS = -lm -lstdc++

Run:${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}
clean:
	-rm -f *.o *.core
main.o:
	${CC} -c ${File}/main.cpp
producerFunctions.o:
	${CC} -c ${File}/producerFunctions.cpp
consumerFunctions.o:
	${CC} -c ${File}/consumerFunctions.cpp