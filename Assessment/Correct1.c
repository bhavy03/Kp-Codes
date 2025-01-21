#include <stdio.h>
#include <stdlib.h>

void invert(int n, int arr[n][n], int r, int c) {
  if (arr[r][c] == 0) {
    arr[r][c] = 1;
  } else {
    arr[r][c] = 0;
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     printf("%d ", arr[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("invert called\n");
}
void flip(int n, int arr[n][n]) {
  int start = 1;
  int end = n;
  while (start < end) {
    for (int i = 1; i <= n; i++) {
      int temp = arr[start][i];
      arr[start][i] = arr[end][i];
      arr[end][i] = temp;
    }
    start++;
    end--;
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     printf("%d ", arr[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("flip called\n");
}
void rotate(int n, int arr[n][n]) {
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int temp = arr[i][j];
      arr[i][j] = arr[j][i];
      arr[j][i] = temp;
    }
  }
  flip(n, arr);
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     printf("%d ", arr[i][j]);
  //   }
  //   printf("\n");
  // }
}
int main() {
  int n;
  scanf("%d", &n);

  // int **arr = (int **)malloc((n) * sizeof(int *));
  // for(int i=0; i<n; i++){
  //   arr[i] = (int *)malloc((n) * sizeof(int));
  // }
  int arr[n][n];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      arr[i][j] = 0;
    }
  }

  int m;
  scanf("%d", &m);

  while (m > 0) {
    int k;
    scanf("%d", &k);
    if (k == 1) {
      int r, c;
      scanf("%d %d", &r, &c);
      if(r>n||c>n){
        printf("Invalid");
        return 0;
      }
      invert(n, arr, r, c);
    }
    if (k == 2) {
      flip(n, arr);
    }
    if (k == 3) {
      rotate(n, arr);
    }
    m--;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}
