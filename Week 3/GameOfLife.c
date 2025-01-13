#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  char input[100];
  scanf("%[^\n]%*c", input);

  int noRow = 1;
  int noCol = 0;
  int maxCols = 0;
  // int currentCols = 0;
  for (int i = 0; input[i] != 0; i++) {
    while (input[i] == '[') {
      i++;
    }
    if (isdigit(input[i])) {
      noCol++;
      // printf("%d\n", noCol);
    }
    if (input[i] == ' ') {
      continue;
    }
    if (input[i] == ']' && input[i + 1] == ',') {
      if (noCol > maxCols) {
        maxCols = noCol;
      }
      noCol = 0;
    }
    if (input[i] == ' ') {
      continue;
    }
    if (input[i] == ',') {
      noRow++;
    }
  }
  // printf("%d %d", row, col);

  int rows = noRow;
  int cols = noCol;
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

  // printf("[");
  // // int flag = 0;
  // for (int i = 0; i < rows; i++) {
  //   if (i == 0) {
  //     printf("[");
  //     for (int j = 0; j < cols; j++) {
  //       printf("%d ", newArr[i][j]);
  //       printf(" ");
  //     }
  //     printf("]");
  //   }
  //   if (i > 0 && i < rows) {
  //     printf(",[");
  //     for (int j = 0; j < cols; j++) {
  //       printf("%d", newArr[i][j]);
  //       printf(" ");
  //     }
  //     printf("]");
  //   }
  // }
  // printf("]");
  printf("[");
  for (int i = 0; i < rows; i++) {
    int flag = 0;
    printf("[");
    for (int j = 0; j < cols; j++) {
      if (flag == 0) {
        printf("%d", newArr[i][j]);
        flag = 1;
      } else {
        printf(" %d", newArr[i][j]);
      }
    }
    if (i != rows - 1) {
      printf("],");
    } else
      printf("]");
  }
  printf("]");
  return 0;
}
