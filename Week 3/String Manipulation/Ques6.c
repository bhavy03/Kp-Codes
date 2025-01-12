#include <stdio.h>
int main()
{
    char input1[200];
    printf("Enter the String 1\n");
    scanf("%[^\n]%*c", input1);
    int arr1[26] = {0};

    char input2[200];
    printf("Enter the String 2\n");
    scanf("%[^\n]%*c", input2);
    int arr2[26] = {0};

    for (int i = 0; input1[i] != '\0'; i++)
    {
        // printf("%d\n", input1[i] - 'a');
        int index = 0;
        index = input1[i] - 'a';
        // printf("%d\n", index);
        arr1[index] = arr1[index] + 1;
        // arr1[index++]++;
    }

    for (int i = 0; input2[i] != '\0'; i++)
    {
        // printf("%d\n", input2[i] - 'a');
        int index = 0;
        index = input2[i] - 'a';
        // printf("%d\n", index);
        arr2[index] = arr2[index] + 1;
    }
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        // printf("%d", arr1[i]);
        if (arr1[i] != arr2[i])
        {
            flag = 0;
            break;
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}