#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main() {
    pid_t pid;
    int signal_num;

    // Get the process id and signal number from user
    printf("Enter the process id: ");
    scanf("%d", &pid);
    printf("Enter the signal number: ");
    scanf("%d", &signal_num);

    // Send the signal to the process
    if(kill(pid, signal_num) == -1) {
        perror("Error sending signal");
        exit(EXIT_FAILURE);
    }

    printf("Signal %d sent to process %d", signal_num, pid);

    return 0;
}
