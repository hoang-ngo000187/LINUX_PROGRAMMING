#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define MSG_SIZE 20

char *msg1 = "hello, world #1";
char *msg2 = "hello, world #2";
char *msg3 = "hello, world #3";
char *msg4 = "hello, world #4";

char pipe_buff[MSG_SIZE];
int fds[2], i;

void sig_handler1(int num)
{
	printf("I am signal handler1: %d\n", num);
	write(fds[1], msg4, MSG_SIZE);
}

int main ()
{
	if(signal(SIGINT, sig_handler1) == SIG_ERR)
	{
		fprintf(stderr, "Cannot handle SIGINT\n");
		exit(EXIT_FAILURE);
	}

	if(pipe(fds) < 0)
	{
		printf("pipe() unsuccessfully\n");
		exit(1);
	}

	read(fds[0], pipe_buff, MSG_SIZE);
	printf("msg[%d]: %s\n", 1, pipe_buff);

	return 0;
}


