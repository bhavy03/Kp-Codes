#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("enter no of rows and columns\n");
  int rows,cols;
  scanf("%d", &rows);
  scanf("%d", &cols);
  int **arr = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++){
    arr[i] = (int *)malloc(cols * sizeof(int));
  }
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
  for(int i = 1;i<101;i++){
    if(mapArr[i] != 0){
      printf("%d -> %d times\n",i,mapArr[i]);
    }
  }
  return 0;
}