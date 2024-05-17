//	Q2. From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create
//		new child (D). All these processes should run concurrently for 5 seconds and cleaned up properly upon termination.

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	int ret1,ret2,ret3,s1,s2,s3;
	ret1 = fork();
	if(ret1 == 0){
		ret2 = fork();
		if(ret2 == 0){
			ret3 = fork();
			if(ret3 == 0)
			{
				printf("child 3: %d\n", ret3);
				printf("child pid=%d\n", getpid());
				printf("child parent pid=%d\n", getppid());
				_exit(0);
			}
			printf("child 2:%d\n", ret2);
			printf("child pid=%d\n", getpid());
			printf("child parent pid=%d\n", getppid());
			waitpid(ret3, &s3, 0);
			_exit(0);
		}

		printf("child 1:%d\n", ret1);
		printf("child pid=%d\n", getpid());
		printf("child parent pid=%d\n", getppid());
		waitpid(ret2, &s2, 0);
		_exit(0);
	}

		printf("Parent...\n");
		printf("parent: fork() returned: %d\n", ret1);
		printf("parent: pid=%d\n", getpid());
		printf("parent: parent pid=%d\n", getppid());
		waitpid(ret1, &s1, 0);

}


