#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


int main()
{
	struct stat infor;

	int fd;
	fd = open("hello.txt", O_RDWR | O_CREAT, 0667);
	
	if(-1 == fd)
	{
		printf("open () hello.txt failed\n");
	}
	else
	{
		if(-1 == fstat(fd, &infor))
		{
			printf("fail to get information of file!\n");
		}
		else
		{
			// Type of file:
			printf("Type of file: ");
			switch (infor.st_mode & S_IFMT)
			{
				case S_IFBLK:
					printf("block device\n");
					break;
				case S_IFCHR:
					printf("character device\n");  
				       	break;
				case S_IFDIR:  
				       	printf("directory\n");         
				       	break;
				case S_IFIFO:  
				       	printf("FIFO/pipe\n");         
				       	break;
				case S_IFLNK:  
				       	printf("symlink\n");           
				       	break;
				case S_IFREG:  
				       	printf("regular file\n");      
				       	break;
				case S_IFSOCK: 
				       	printf("socket\n");            
				       	break;
				default:      
				       	printf("unknown?\n");               
				       	break;
			}

			// I - node number:
			printf("I-node number: %ld\n", (long) infor.st_ino);
			// Size of file:	
			printf("File size: %lld bytes\n", (long long) infor.st_size);
			//Last status change:
			printf("Last status change: %s\n", ctime(&infor.st_ctim.tv_sec));
			// Last file access:
			printf("Last file access: %s\n", ctime(&infor.st_atim.tv_sec));
			// Last file modification:
			printf("Last file modification: %s\n", ctime(&infor.st_mtim.tv_sec));

		}
	}
	

	return 0;
}
