#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int arr[2];
// step1: implement SIGINT handler
void sigint_handler(int sig) {
	close(arr[1]);
	close(arr[0]);
	_exit(0);
}

int main() {
	char ch = 'A';
	struct sigaction sa;
	int ret = pipe(arr);
    int	err = sigaction(SIGINT, &sa, NULL);
	if(err < 0) {
		perror("sigaction() failed");
		
	}
	int count = 0;
	while(1){
			write(arr[1] , &ch , 1);
			count++;
			printf("bytes written : %d\n" , count);

	}
	
	
	return 0;
}
