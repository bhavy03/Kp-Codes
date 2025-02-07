// this is brute force
// #include<stdio.h>
// int main(){
//     int arr[20];
//     int i = 0;
//     int num = 0;
//     while ((scanf("%d", &num)) == 1)
//     {
//         arr[i++] = num;
//         if (getchar() == '\n')
//         {
//             break;
//         }
//     }
//     int n = i;
//     int count = 0;
//     for(int i = 0;i<n-1;i++){
//         for(int j = i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 count++;
//             }
//         }
//     }
//     printf("%d",count);
// }

#include <stdio.h>
int count = 0;
void merge(int *arr, int low, int mid, int high)
{
    int temp[high - low + 1];
    int left = low;
    int right = mid + 1;
    int index = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[index++] = arr[left];
            left++;
        }
        else
        {
            temp[index++] = arr[right];
            count = count + (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        temp[index++] = arr[left];
        left++;
    }
    while (right <= high)
    {
        temp[index++] = arr[right];
        right++;
    }
    for (int i = 0; i < (high - low + 1); i++)
    {
        arr[low + i] = temp[i];
    }
}
void mergeSort(int *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main()
{
    int arr[20];

    int i = 0;
    int num = 0;
    while ((scanf("%d", &num)) == 1)
    {
        arr[i++] = num;
        if (getchar() == '\n')
        {
            break;
        }
    }
    int n = i;
    int low = 0;
    int high = n - 1;
    mergeSort(arr, low, high);
    printf("%d\n", count);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}