#include <stdio.h>
void sequences(int *arr, int *ans, int index, int n, int k, int idx)
{

  if (idx == k)
  {
    for (int i = 0; i < k; i++)
      printf("val %d ", ans[i]);
    printf("\n");
    return;
  }

  printf("%d %d\n", index, idx);
  if (index == n)
  {
    return;
  }

  // include
  ans[idx] = arr[index];
  sequences(arr, ans, index + 1, n, k, idx + 1);

  // exclude
  sequences(arr, ans, index + 1, n, k, idx);
}
int main()
{
  int k, n;
  scanf("%d %d", &k, &n);
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = i + 1;
  }
  int ans[k];
  sequences(arr, ans, 0, n, k, 0);
  // for (int i = 0; i < n; i++) {
  //   printf("%d", arr[i]);
  // }
  return 0;
}
