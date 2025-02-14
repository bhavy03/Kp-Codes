#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork(); // Create a child process

    if (pid < 0)
    {
        // Error occurred during fork
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process code
        printf("This is the child process. PID: %d\n", getpid());
        exit(124);
    }
    int status;
    if (pid != 0)
    {
        wait(&status);
    }
    printf("In parent process the status is %d and pid is %d\n", WEXITSTATUS(status), getpid());
    return 0;
}
