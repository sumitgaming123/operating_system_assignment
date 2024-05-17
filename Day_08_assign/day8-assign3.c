// parent --> child1 --> child2 --> child3

#include<unistd.h>
#include<stdio.h>

int main(){
	int i, s1, s2, s3;
	int ret1, ret2, ret3;
	ret1 = fork();
	if(ret1 == 0){
		ret2 = fork();
		if(ret2 == 0){
			ret3 = fork();
			if(ret3 == 0){
				for(i=1; i<=5; i++) {
					printf("child: %d\n", i);
					sleep(1);
				}

				for(i=1; i<=5; i++) {
					printf("child: %d\n", i);
					sleep(1);
					waitpid(ret3,&s3,0);
					_exit(0);
				}

				for(i=1; i<=5; i++) {
					printf("child: %d\n", i);
					sleep(1);
					waitpid(ret2,&s2,0);
					_exit(0);
				}
				for(i=1; i<=10; i++) {
					printf("parent: %d\n", i);
					sleep(1);
					waitpid(ret1,&s1,0);
					_exit(0);

				}
			}

		}
	}
	return 0;
}
