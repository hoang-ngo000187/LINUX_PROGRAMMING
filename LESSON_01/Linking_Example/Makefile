

CC := gcc
INC_FLAGS := -I include
C_FLAGS := -c -o

all:
	$(CC) $(C_FLAGS) hello.o hello.c $(INC_FLAGS)
	$(CC) $(C_FLAGS) main.o main.c $(INC_FLAGS)
	$(CC) $(C_FLAGS) hello_A.o hello_A.c $(INC_FLAGS)
clean:
	rm -rf *.o
	rm -rf hello
