#include <stdio.h>
#include<stdlib.h>
int main() {
  int rows,cols;
  printf("Enter the number of rows\n");
  scanf("%d",&rows);
  printf("Enter the number of columns\n");
  scanf("%d",&cols);
  // int arr[rows][cols];
  int **arr = (int**)malloc(rows*sizeof(int*));
  for(int i=0;i<rows;i++){
    arr[i] = (int*)malloc(cols*sizeof(int*));
  }
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  printf("Here are the different ways of accessing a 2D array\n");
  for(int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
  for(int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      printf("%d ",*(*(arr+i)+j));
    }
    printf("\n");
  }
  return 0;  
}