#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int arr1[2],arr2[2],  ret, s;
	int num1, num2, res, n1, n2, r;
	ret = pipe(arr1);
	ret = pipe(arr2);
	
	if(ret < 0)
	{
		perror("pipe() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0)
	{
		close(arr1[0]);
		close(arr2[1]);
		printf("enter 2 numbers");
		scanf("%d%d", &num1, &num2);
		write(arr1[1], &num1, sizeof(num1));
		write(arr1[1], &num2, sizeof(num2));

		read(arr2[0], &res, sizeof(res));
		printf("result: %d\n", res);

		close(arr2[0]);
		close(arr1[1]);

	}

	else
	{
		close(arr1[1]);
		close(arr2[0]);
		read(arr1[0], &n1, sizeof(n1));
		read(arr1[0], &n2, sizeof(n2));

		r = n1 + n2;

		write(arr2[1], &r, sizeof(r));

		close(arr2[1]);
		close(arr1[0]);

		waitpid(-1, &s, 0);
	}
	close(arr1[1]);
	close(arr1[0]);
	close(arr2[1]);
	close(arr2[0]);
	return 0;
}
