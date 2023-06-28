#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void func(int signum)
{
	printf("I am in func ()\n");
	wait(NULL);
}

int main()
{
	pid_t child_pid = fork();

	if (child_pid >=0)
	{
		if(child_pid == 0)
		{
			printf("I am Child, my PID: %d\n", getpid());
			while(1);
		}
		else
		{
			/* When a child is terminated, a corresponding SIGCHLD signal
			 * is dilivered to the parent  */
			signal(SIGCHLD, func);
			printf("Hello world\n");
			while(1);
		}
	}
	else
	{
		printf("fork () unsuccessfully\n");
	}
	return 0;
}
