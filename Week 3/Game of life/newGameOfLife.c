#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  char input[100];
  scanf("%[^\n]%*c", input);

  int noRow = 1;
  int noCol = 0;
  int maxCols = 0;

  for (int i = 0; input[i] != 0; i++) {
    while (input[i] == '[') {
      i++;
    }
    if (isdigit(input[i])) {
      noCol++;
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

  int rows = noRow;
  int cols = noCol;

  int **arr = (int **)malloc(sizeof(int *) * rows);
    int **newArr = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(sizeof(int) * cols);
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
      int sum = 0;
      if (i - 1 >= 0 && j - 1 >= 0) {
        sum += arr[i - 1][j - 1];
      }
      if (i - 1 >= 0) {
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

