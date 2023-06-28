#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t child_pid;
	int status;
	int counter = 0;
	child_pid = fork();

	if(child_pid >= 0)
	{
		if(0 == child_pid) /* Process con */
		{
			printf("Child process termination\n");
			while (1);

		}
		else /* Process cha  */
		{
			wait(&status);
			printf("Hello world\n")
		//	while(1);
		}
	}
	else
	{
		printf("fork () unsuccessfully\n");
	}
	return 0;
}

