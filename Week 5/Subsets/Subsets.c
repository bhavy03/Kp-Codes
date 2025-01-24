#include <stdio.h>
int isDigit(char c){
    return(c>='0'&& c<='9');
}
void subsets(int *arr, int *ans, int index, int idx, int n)
{
    if (index == n)
        return;

    ans[idx] = arr[index];
    printf(", [");
    
    for (int i = 0; i <= idx; i++)
    {
        if (i == idx)
        {
            printf("%d", ans[i]);
        }
        else
        {
            printf("%d, ", ans[i]);
        }
    }
    printf("]");

    subsets(arr, ans, index + 1, idx + 1, n);
    subsets(arr, ans, index + 1, idx, n);
}
int main()
{
    char exp[100];
    scanf("%[^\n]%*c", exp);
    int arr[16];
    int arrIndex = 0;
    int num = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        while(isDigit(exp[i])) {
            num = num * 10 + (exp[i] - '0');
            i++;
        }
        arr[arrIndex++] = num;
        if (exp[i] == ',') {
            num = 0;
            continue;
        }
        if(exp[i]=='\0'){
            break;
        }
    }
    int ans[16];
    int index = 0;
    int idx = 0;
    printf("[[]");
    // printf("printing");
    // for (int i = 0; i < arrIndex; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    subsets(arr, ans, index, idx, arrIndex);
    printf("]");
    return 0;
}
