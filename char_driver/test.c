#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	int fd, i;
	ssize_t ret;
	char my_buf[12]="hello world";

	fd = open("/dev/vDev1",O_RDWR | 0666);
	if(fd < 0) {
		printf("failed acquiring file descriptor return status %d\n",fd);

		return fd;
	}

	ret = write(fd,my_buf,12);
	ret = read(fd,my_buf,12);
	if(ret < 0)
		printf("read operation failed with return status %ld\n",ret);
	printf("%s\n",my_buf);
	getchar();
	close(fd);
	return 0;
}
