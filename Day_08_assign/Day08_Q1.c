//	Q1. From one parent create 5 child processes. Each child should run for 5 seconds and print count along with its pid. Parent should wait for all
//		child processes to complete and clean all of them. Hint: use loop to fork() multiple child processes.



#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int ret, i, s;
	for(i=0; i<=5; i++){
		ret = fork();
		if(ret == 0){
			printf("child: %d\n",i);
			printf("child: pid=%d\n", getpid());
			printf("child: parent pid=%d\n", getppid());
			sleep(1);
			_exit(0);
		}
	}

	for(i=0; i<=5; i++)
		{
		printf("child exit: %d\n", WEXITSTATUS(s));
		sleep(1);
		}
	return 0;
	}
                                                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                     

