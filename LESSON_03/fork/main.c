#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) /* Cap phat stack frame cho ham main */
{
	pid_t child_pid;		/* Luu trong Stack frame cua main() */
	int counter = 2;		/* Luu trong frame cua main() */
	
	printf("Gia tri khoi tao cua counter: %d\n", counter);

	child_pid = fork();
	if (child_pid >= 0)
	{
		if (0 == child_pid)
		{
			printf("\nIm the child process, counter: %d\n", ++counter);
			printf("My PID is: %d, my parent PID is: %d\n: ", getpid(), getppid());
		}
		else
		{
			printf("\nIm the parent process, counter: %d\n", counter);
                        printf("My PID is: %d\n", getpid());
			while(1);
		}
	}
	else
	{
		printf("fork() unsuccessfully\n");
	}
	return 0;
}

