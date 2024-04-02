OBJ = main.o functions.o
CC = gcc
CFLAGS = -g -lpthread
kp:$(OBJ)
	$(CC) $(CFLAGS) -o kp $(OBJ)
main.o:general.h main.c
functions.o:general.h functions.c

clean:
	rm kp $(OBJ) left.out right.out

cf:
	rm left.out right.out



