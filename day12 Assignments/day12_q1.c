#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd, cnt, nt;
	int num1, num2, sum;
	fd = open("/tmp/server_fifo", O_WRONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("enter 2 numbers: ");
	scanf("%d%d", &num1, &num2);

	cnt = write(fd, &num1, sizeof(int));
	cnt = write(fd, &num2, sizeof(int));


        fd = open("/tmp/client_fifo", O_RDONLY);
	if(fd < 0)
	{
		perror("open failed");
	        _exit(2);
		}

	nt = read(fd,&sum, sizeof(int));
	printf("sum = %d", sum);


	close(fd);
	close(fd);
	return 0;
}
