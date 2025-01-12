#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void sortArr(int *arr, int count)
{
  for (int i = 0; i < count - 1; i++)
  {
    for (int j = 0; j < count - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
void printTriplet(int *arr, int count)
{
  printf("[");
  int flag = 0;
  for (int i = 0; i < count; i++)
  {
    if (i > 0 && arr[i] == arr[i - 1])
    {
      continue;
    }
    for (int j = i + 1; j < count; j++)
    {
      if (j > i + 1 && arr[j] == arr[j - 1])
        continue;
      for (int k = j + 1; k < count; k++)
      {
        if (k > j + 1 && arr[k] == arr[k - 1])
          continue;
        if (((arr[i] + arr[j] + arr[k]) == 0) && flag == 0)
        {
          printf("[%d %d %d]", arr[i], arr[j], arr[k]);
          flag = 1;
        }
        else if ((arr[i] + arr[j] + arr[k] == 0) && flag == 1)
        {
          printf(",[%d %d %d]", arr[i], arr[j], arr[k]);
        }
      }
    }
  }
  printf("]");
}

int main()
{
  char str[3001];
  fgets(str, 3001, stdin);
  int *arr = (int *)malloc(105 * sizeof(int));

  int i = 0;
  int sign = 1;
  int count = 0;

  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == '[' || str[i] == ']' || str[i] == ' ')
    {
      i++;
    }

    if (isdigit(str[i]) || (str[i] == '-' && isdigit(str[i + 1])))
    {
      int num = 0, sign = 1;

      if (str[i] == '-')
      {
        sign = -1;
        i++;
      }

      while (isdigit(str[i]))
      {
        num = num * 10 + (str[i] - '0');
        i++;
      }

      num *= sign;
      arr[count++] = num;
    }
  }

  // for (int i = 0; i < count; i++)
  // {
  // printf("%d ", arr[i]);
  // }

  sortArr(arr, count);
  printTriplet(arr, count);

  // for (int i = 0; i < count; i++)
  // {
  // printf("%d ", arr[i]);
  // }

  return 0;
}