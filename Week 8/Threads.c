#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();
    int n;
    if (pid == 0)
    {
        n = 1;
    }
    else
    {
        n = 5;
    }
    if (pid != 0)
    {
        wait(NULL);
    }
    for (int i = n; i < n + 5; i++)
    {
        printf("%d", i);
        fflush(stdout);
    }
    printf("\n");
    return 0;
}
// void *routine1(){
//     printf("Routine called 1\n");
//     sleep(3);
//     printf("Thread end 1\n");
// }
// void *routine2(){
//     printf("Routine called 2\n");
//     sleep(2);
//     printf("Thread end 2\n");
// }
// int main()
// {
//     pthread_t t1,t2;
//     pthread_create(&t1,NULL,&routine1,NULL);
//     pthread_create(&t2,NULL,&routine2,NULL);
//     pthread_join(t1,NULL);
//     pthread_join(t2,NULL);
//     return 0;
// }
