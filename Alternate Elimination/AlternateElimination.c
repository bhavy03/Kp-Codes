#include <stdio.h>

void change(int *arr1, int n) {
  
  if (n == 1) {
  printf("%d ", arr1[0]) ;
      return;
  }
  int arr2[n / 2];
  int index = 0;
  for (int i = 1; i < n; i += 2) {
    arr2[index++] = arr1[i];
  }

  // index--;
  

  for (int i = 0; i < index / 2; i++) {
    int temp = arr2[i];
    arr2[i] = arr2[index - i - 1];
    arr2[index - i - 1] = temp;
  }

  // for (int i = 0; i < index; i++) {
  //   printf("%d %d  ", i, arr2[i]);
  // }
  // printf("\n");

  change(arr2, index);
}
int main() {
  int n;
  scanf("%d", &n);
  int arr1[n];
  for (int i = 0; i < n; i++) {
    arr1[i] = i + 1;
  }
  change(arr1, n);
  return 0;
}
