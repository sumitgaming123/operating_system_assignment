/*1. The child process send two numbers to the parent process via message queue. The parent process calculate the sum and return via same message queue.
  The child process print the result and exit. The parent process wait for completion of the child and then exit.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MQ_KEY 0x1234

typedef struct msg {
	long type;
	char data[32];
} msg_t;

int main() {
	int mqid, ret, s;

	// create message queue
	mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
	if (mqid < 0) {
		perror("msgget() failed");
		_exit(1);
	}

	ret = fork();
	if (ret == 0) {
		// child: send two numbers to the parent
		msg_t m1;
		m1.type = 1;

		int num1, num2;
		printf("Child: Enter two numbers: ");
		scanf("%d %d", &num1, &num2);

		snprintf(m1.data, sizeof(m1.data), "%d %d", num1, num2);
		ret = msgsnd(mqid, &m1, sizeof(m1.data), 0);
		if (ret < 0) {
			perror("msgsnd() failed");
			_exit(1);
		}
		printf("Child: Numbers sent to parent\n");

		// receive the sum from the parent
		ret = msgrcv(mqid, &m1, sizeof(m1.data), 2, 0);
		if (ret < 0) {
			perror("msgrcv() failed");
			_exit(1);
		}

		int sum;
		sscanf(m1.data, "%d", &sum);
		printf("Child: Sum received from parent: %d\n", sum);

		_exit(0);  // Child process exits
	} else {
		// parent: receive the two numbers
		msg_t m2;
		printf("Parent: Waiting for numbers from child...\n");
		ret = msgrcv(mqid, &m2, sizeof(m2.data), 1, 0);
		if (ret < 0) {
			perror("msgrcv() failed");
			_exit(1);
		}

		int num1, num2;
		sscanf(m2.data, "%d %d", &num1, &num2);

		// calculate the sum
		int sum = num1 + num2;

		// send the sum back to the child
		m2.type = 2;
		snprintf(m2.data, sizeof(m2.data), "%d", sum);
		ret = msgsnd(mqid, &m2, sizeof(m2.data), 0);
		if (ret < 0) {
			perror("msgsnd() failed");
			_exit(1);
		}
		printf("Parent: Sum sent to child\n");

		// wait for child and clean it up
		wait(&s);

		// destroy the message queue
		msgctl(mqid, IPC_RMID, NULL);

		printf("Parent: Exiting.\n");
	}
	return 0;
}
