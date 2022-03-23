#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

int main(int argc, char **argv)
{
	

	//file name, flags
	//systemcall, returnwaarde indien negatief NOK, positief OK
	int fd = open("largefile", O_RDONLY); 
	
	//exit statis verschillend van 0, NOK
	if(fd<0){
		perror(argv[0]);
		return 1;
	}
	
	int i;
	char buffer[8192];
	
	//chift left met 1  = * 2
	for(i=1; i<= 8192; i<<=1){
		
		//lseek zorg ervoor dat er altijd terug aan het begin van het bestand begonnen word
		
		double start = clock();
		
		if(lseek(fd,0, SEEK_SET) < 0)
		{
			perror(argv[0]);
			return 1;
		}
		
		
		int n;
	       
		while( ( n=read(fd, buffer, i)) > 0);
	
	
		if(n<0)
		{
			perror(argv[0]);
			return 1;
		
		}
		printf("BUF_SIZ=%5d Time=%10.2f\n", i, (clock() - start) / CLOCKS_PER_SEC);
	}
	
	if(close(fd) < 0)
	{
		perror(argv[0]);
		return 1;
	}



}
