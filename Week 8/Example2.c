#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid != 0)
    {
        wait(NULL);
    }
    pid = fork();
    if (pid != 0)
    {
        wait(NULL);
    }
    pid = fork();
    if (pid != 0)
    {
        wait(NULL);
    }
    if (pid == 0)
    {
        printf("hello world in child %d with parent %d\n", getpid(), getppid());
    }
    else
    {
        printf("hello world in parent %d with parent %d\n", getpid(), getppid());
    }
    return 0;
}
