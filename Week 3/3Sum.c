#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  char str[3001];
  fgets(str, 3001, stdin);
  int *arr = (int *)malloc(105 * sizeof(int));

  int i = 0;
  int sign = 1;
  int count = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '[' || str[i] == ']' || str[i] == ' ') {
      i++;
    }

    if (isdigit(str[i]) || (str[i] == '-' && isdigit(str[i + 1]))) {
      int num = 0, sign = 1;

      if (str[i] == '-') {
        sign = -1;
        i++;
      }

      while (isdigit(str[i])) {
        num = num * 10 + (str[i] - '0');
        i++;
      }

      num *= sign;
      arr[count++] = num;
    }
  }

  // for (int i = 0; i < count; i++) {
  //   printf("%d ", arr[i]);
  // }
  for (int i = 0; i < count; i++) {
    for (int j = i + 1; j < count; j++) {
      for (int k = j + 1; k < count; k++) {
        int sum = 0;
        sum = arr[i] + arr[j] + arr[k];
        if (sum == 0 && arr[i] != arr[j] && arr[i] != arr[k] &&
            arr[j] != arr[k]) {
          printf("%d %d %d\n", arr[i], arr[j], arr[k]);
        }
      }
    }
  }
  return 0;
}