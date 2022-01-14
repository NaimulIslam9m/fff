COM = gcc
CFLAGS = -Wall -fcommon

all: main_program

main_program: main.o copy.o cut.o delete.o explore.o help.o rename.o
	$(COM) main.o copy.o cut.o delete.o explore.o help.o rename.o -o fff

%.o: %.c
	$(COM) -c $^

clean:
	rm *.o *.out