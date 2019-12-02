#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_SIZE	20

int main(void){
	int fd;
	int i;
	char* in = (char*)malloc(sizeof(char) * MAX_SIZE);
	char* out = (char*)malloc(sizeof(char) * MAX_SIZE);
	
	if( (fd=open("/dev/mydevicefile", O_RDWR))<0 ){
		perror("open error");
		return -1;
	}
	strcpy(out, "string2222222222222222222222222");
	for(i=0; i<6; i++){
		write(fd, out, MAX_SIZE);
	}
	strcpy(out, "string3333333333333333333333333");
	write(fd, out, MAX_SIZE);
	write(fd, out, MAX_SIZE);

	for(i=0; i<5; i++){
		read(fd, in, MAX_SIZE);	printf("%s \n", in);
	}
	
	free(in);
	free(out);

	close(fd);
	return 0;
}
