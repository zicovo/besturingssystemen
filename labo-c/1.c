#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
	srand(time(0));	

	//file name, flags
	//systemcall, returnwaarde indien negatief NOK, positief OK
	int fd = open("largefile", O_WRONLY | O_CREAT); 
	
	//exit statis verschillend van 0, NOK
	if(fd<0){
		perror(argv[0]);
		return 1;
	}
	
	int i;

	for(i = 0; i < 10 * 1024 * 1024; i++)
	{
	
		char ch = rand() % 26 + 'a';

		if(write(fd, &ch, 1) < 0)
		{
		perror(argv[0]);
		return 1;
		}
	}
	


	if(close(fd) < 0)
	{
		perror(argv[0]);
		return 1;
	}



}
