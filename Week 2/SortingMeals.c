#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int num = 0;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        // scanf("%d", &num);
        // arr[i] = num;
    }
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) == 0)
        {
            count0++;
        }
        else if (*(arr + i) == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    for (int i = 0; i < count0; i++)
    {
        *(arr + i) = 0;
    }
    for (int i = count0; i < count0 + count1; i++)
    {
        *(arr + i) = 1;
    }
    for (int i = count0 + count1; i < n; i++)
    {
        *(arr + i) = 2;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", *(arr + i));
    }
    return 0;
}