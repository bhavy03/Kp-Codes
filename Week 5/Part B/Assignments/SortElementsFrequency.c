#include <stdio.h>
struct freq
{
    int value;
    int freq;
};
int findIndex(struct freq allFreq[100], int key, int structSize)
{
    for (int j = 0; j < structSize; j++)
    {
        if (allFreq[j].value == key)
        {
            return j;
        }
    }
    return -1;
}
void swap(struct freq *a, struct freq *b)
{
    struct freq temp = *a;
    *a = *b;
    *b = temp;
}
void sortArray(struct freq allFreq[], int structSize)
{
    for (int i = 0; i < structSize; i++)
    {
        for (int j = 0; j < structSize - i - 1; j++)
        {
            if (allFreq[j].freq < allFreq[j + 1].freq)
            {
                // swap(&(allFreq[j]), &(allFreq[j + 1]));
                struct freq temp = allFreq[j];
                allFreq[j] = allFreq[j + 1];
                allFreq[j + 1] = temp;
            }
        }
    }
}

int findFrequency(int *arr, int n, struct freq allFreq[100])
{
    int structSize = 0;
    for (int i = 0; i < n; i++)
    {
        int index = findIndex(allFreq, arr[i], structSize);
        if (index == -1)
        {
            allFreq[structSize].value = arr[i];
            allFreq[structSize].freq = 1;
            structSize++;
        }
        else
        {
            allFreq[index].freq++;
        }
    }
    // for (int i = 0; i < structSize; i++)
    // {
    //     printf("%d %d\n", allFreq[i].value, allFreq[i].freq);
    // }
    // printf("\n");
    return structSize;
}
int main()
{
    int arr[20];
    int i = 0;
    int num = 0;
    while ((scanf("%d", &num)) == 1)
    {
        arr[i++] = num;
        if (getchar() == '\n')
        {
            break;
        }
    }
    struct freq allFreq[100];
    int n = i;
    int size = findFrequency(arr, n, allFreq);
    sortArray(allFreq, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < allFreq[i].freq; j++)
        {
            printf("%d ", allFreq[i].value);
        }
    }
    return 0;
}
