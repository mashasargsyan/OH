#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    pid_t pid = fork();

    if (pid > 1) {
        printf("Child process created with PID: %d\n", pid);
        printf("Parent is sleeping\n");
        sleep(30); 
    } 
    else if (pid == 0) {
        
        printf("Child exiting immediately\n");
          
    } 
    else {
        perror("fork failed");
    }

    return 0;
}
