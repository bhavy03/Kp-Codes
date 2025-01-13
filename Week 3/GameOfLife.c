#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  char input[100];
  scanf("%[^\n]%*c", input);
  int rows = 4;
  int cols = 3;
  int **arr = (int **)malloc(sizeof(int) * rows);
  for (int i = 0; i < rows; i++) {
    arr[i] = (int *)malloc(sizeof(int) * cols);
  }

  int **newArr = (int **)malloc(sizeof(int) * rows);
  for (int i = 0; i < rows; i++) {
    newArr[i] = (int *)malloc(sizeof(int) * cols);
  }
  
  int row = 0;
  int col = 0;
  for (int i = 0; input[i] != 0; i++) {
    while (input[i] == '[' || input[i] == ']' || input[i] == ',' ||
           input[i] == ' ') {
      i++;
    }
    if (isdigit(input[i])) {
      arr[row][col] = input[i] - '0';
      col++;
      if (col == cols) {
        col = 0;
        row++;
      }
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  // printf("%d",arr[0-2][0-2]);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int sum = 0;
      // sum = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] +
      //       arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j - 1] + arr[i + 1][j]
      //       + arr[i + 1][j + 1];
      // for every element sum is adding if and only if this happens assuming
      // the element as the middle element
      if (i - 1 >= 0 && j - 1 >= 0) {
        sum += arr[i - 1][j - 1];
      }
      if (i - 1 > 0) {
        sum += arr[i - 1][j];
      }
      if (i - 1 >= 0 && j + 1 < cols) {
        sum += arr[i - 1][j + 1];
      }
      if (j - 1 >= 0) {
        sum += arr[i][j - 1];
      }
      if (j + 1 < cols) {
        sum += arr[i][j + 1];
      }
      if (i + 1 < rows && j - 1 >= 0) {
        sum += arr[i + 1][j - 1];
      }
      if (i + 1 < rows) {
        sum += arr[i + 1][j];
      }
      if (i + 1 < rows && j + 1 < cols) {
        sum += arr[i + 1][j + 1];
      }

      if (arr[i][j] == 0) {
        if (sum == 3) {
          newArr[i][j] = 1;
        }
      }
      if (arr[i][j] == 1) {
        if (sum < 2 || sum > 3) {
          newArr[i][j] = 0;
        }
        if (sum == 2 || sum == 3) {
          newArr[i][j] = 1;
        }
      }
    }
  }
  printf("\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", newArr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
