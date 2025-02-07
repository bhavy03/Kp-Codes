#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char exp[10 ^ 5];
    scanf("%[^\n]%*c", exp);
    int arr[256] = {0};
    for (int i = 0; exp[i] != '\0'; i++)
    {
        int index = (int)(exp[i]);
        arr[index]++;
    }
    printf("{");
    int flag = 0;
    for (int i = 0; i < 256; i++)
    {
        if (arr[i] != 0)
        {
            if (flag == 0)
            {
                printf("%c:%d", (i), arr[i]);
                flag = 1;
            }
            else
            {
                printf(", %c:%d", (i), arr[i]);
            }
        }
    }
    printf("}");
    return 0;
}
