#include <stdio.h>
#include <stdlib.h>

int main(){
  int rows,cols;
  printf("enter no of rows\n");
  scanf("%d", &rows);
  printf("enter no of cols\n");
  scanf("%d", &cols);
  int **arr = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++){
    arr[i] = (int *)malloc(cols * sizeof(int));
  }
  printf("Enter the matrix\n");
  int mapArr[101] = {0};
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int index = arr[i][j];
       mapArr[index]++;
    }
  }
  printf("Frequency of each number\n");
  for(int i = 1;i<101;i++){
    if(mapArr[i] != 0){
      printf("%d -> %d times\n",i,mapArr[i]);
    }
  }
  return 0;
}