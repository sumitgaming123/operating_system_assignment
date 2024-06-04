#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// p2 -- reader
int main() {
	int fd, cnt, nt;
	int num1, num2, sum;
	fd = open("/tmp/server_fifo", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for data...\n");
	cnt = read(fd,&num1 , sizeof(int));
	cnt = read(fd,&num2 , sizeof(int));
	printf("read from fifo: %d bytes \n", cnt);

	sum = num1 + num2;

        fd = open("/tmp/client_fifo", O_WRONLY);
	if(fd < 0)
	{
		perror("open() failed");
		_exit(2);
	}

	 sum = num1 + num2;

	printf("sum \n");
	nt = write(fd, &sum, sizeof(int));



	close(fd);
	close(fd);
	return 0;
}
