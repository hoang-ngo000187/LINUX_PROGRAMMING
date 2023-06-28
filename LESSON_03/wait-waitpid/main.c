#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) /*Cap phat stack frame cho ham main*/
{
	pid_t child_pid; /*Luu trong stack frame cua ham main*/
	int status, rv;

	child_pid = fork();
	if(child_pid >= 0)
	{
		if(0 == child_pid) /*Process con*/
		{
			printf("I am the child process, my PID: %d\n", getpid());
			while(1);
		}
		else if(child_pid >0) /*Process cha*/
		{
			rv = wait(&status);
			if(rv == -1)
			{
				printf("Wait() unsuccessfully\n");
			}
			printf("I am the parent process, PID child process: %d\n", rv);
		}
	}
	else
	{
		printf("fork() unsuccessfully\n");
	}
	return 0;
}
