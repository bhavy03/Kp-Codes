#include <stdio.h>

// void print(int n)
// {
//     if (n == 1)
//     {
//         return;
//     }
//     n--;

//     printf("%d\n", n);

//     print(n);

//     printf("%d\n", n);
// }

// void print(int i ,int n){
//     if(i>n){
//         return;
//     }
//     printf("%d",i);
//     print(i+1,n);
// }
int main()
{
    int n = 5;
    int i = 1;
    // print(n + 1);
    print(i, n);
    return 0;
}