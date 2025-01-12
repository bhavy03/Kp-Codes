#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char str[3001];
    fgets(str, 3001, stdin);
    int *arr = (int *)malloc(105 * sizeof(int));

    int i = 0;
    int sign = 1;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '[' || str[i] == ']' || str[i] == ' ')
        {
            i++;
        }

        if (isdigit(str[i]) || (str[i] == '-' && isdigit(str[i + 1])))
        {
            int num = 0, sign = 1;

            if (str[i] == '-')
            {
                sign = -1;
                i++;
            }

            while (isdigit(str[i]))
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }

            num *= sign;
            arr[count++] = num;
        }
    }

    int maxSum = 0;
    for (int i = 0; i < count; i++)
    {
        int sum = arr[i];
        for (int j = i + 1; j < count; j++)
        {
            sum = sum + arr[j];
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }
    printf("%d", maxSum);
    return 0;
}
