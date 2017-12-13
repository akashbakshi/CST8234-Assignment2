CC = gcc
CC_FLAGS = -g -ansi -pedantic -Wall -w
FILES = main.c registration.c course.c parse.c globals.c
OUT_EXE = assignment2 

build: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES) 

clean:
	rm -f *.o core *.exe *~ *.out

rebuild: clean build
