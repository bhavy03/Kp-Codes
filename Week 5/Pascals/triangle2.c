#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);
  int ans = 1;
  printf("%d", ans);
  for (int i = 1; i < n; i++) {
    ans = ans * (n - i);
    ans = ans / (i);
    printf(",%d", ans);
  }
  return 0;
}
