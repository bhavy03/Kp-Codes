#include <stdio.h>
// for interplace rotation we first take the transpose of matrix and then reverse the rows
// why we do transpose it because the first row of rotated is similar to reverse of the first column of not rotated
int main()
{
    int rows, cols;
    printf("enter no of rows and columns\n");
    scanf("%d", &rows);
    printf("enter no of rows and columns\n");
    scanf("%d", &cols);
    printf("Enter the matrix\n");
    int arr[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    printf("The rotated matrix is\n");
    int start = 0, end = cols - 1;
    while (start < end)
    {
        for (int i = 0; i < rows; i++)
        {
            int temp = arr[i][start];
            arr[i][start] = arr[i][end];
            arr[i][end] = temp;
        }
        start++;
        end--;
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    // for(int i = 0;i<rows;i++){
    // int j = 0;
    // int k = rows-1;
    // while(j<k){
    // int temp = arr[i][j];
    // arr[i][j] = arr[i][k];
    // arr[i][k] = temp;
    // j++;
    // k--;
    // }
    // }
}

// this approach uses extra matrix and with time complexity as O(N2) and space complexity as O(N2)
// int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
// int newArr[3][3];
// for(int i=0;i<3;i++){
// for(int j=0;j<3;j++){
// newArr[j][3-1-i] = arr[i][j];
// }
// }
// for(int i=0;i<3;i++){
// for(int j=0;j<3;j++){
// printf("%d ",newArr[i][j]);
// }
// printf("\n");
// }