#include <stdio.h>
int nCr(int n, int r) {
  long long res = 1;
  for (int i = 0; i < r; i++) {
    res = res * (n - i);
    res = res / (i + 1);
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    ans = nCr(n - 1, n - i);
    if (flag == 0) {
      printf("%d", ans);
      flag = 1;
    }else{
      printf(",%d", ans);
    }
  }

  return 0;
}
