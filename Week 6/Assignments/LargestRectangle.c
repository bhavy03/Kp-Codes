// this is brute force approach
long largestRectangle(int h_count, int *h)
{
    long area = 0;
    // arrSort(h,h_count);
    for (int i = 0; i < h_count; i++)
    {
        int min = h[i];
        for (int j = i; j < h_count; j++)
        {
            if (h[j] < min)
            {
                min = h[j];
            }
            long temp_area = (j - i + 1) * min;
            if (area < temp_area)
                area = temp_area;
        }
    }
    return area;
}

// this is optimized approach
typedef struct Stack
{
    int *arr;
    int top;
} Stack;
void push(Stack *s, int index)
{
    s->top++;
    s->arr[s->top] = index;
}
int *findNse(int n, int *h)
{
    int *temp = (int *)malloc(n * sizeof(int));
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->arr = (int *)malloc((n + 2) * sizeof(int));
    s->arr[0] = -1;
    s->top = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (s->arr[s->top] != -1 && h[i] <= h[s->arr[s->top]])
        {
            s->top--;
        }
        if (s->arr[s->top] == -1)
            temp[i] = n;
        else
            temp[i] = s->arr[s->top];
        push(s, i);
    }
    return temp;
}

int *findPse(int n, int *h)
{
    int *temp = (int *)malloc(n * sizeof(int));
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->arr = (int *)malloc((n + 2) * sizeof(int));
    s->arr[0] = -1;
    s->top = 0;
    for (int i = 0; i < n; i++)
    {
        while (s->arr[s->top] != -1 && h[i] <= h[s->arr[s->top]])
        {
            s->top--;
        }
        if (s->arr[s->top] == -1)
            temp[i] = -1;
        else
            temp[i] = s->arr[s->top];
        push(s, i);
    }

    free(s->arr);
    free(s);
    return temp;
}

long largestRectangle(int h_count, int *h)
{

    int *nse = findNse(h_count, h);
    int *pse = findPse(h_count, h);
    int maxArea = 0;

    //     for(int i=0; i<h_count; i++){
    //         printf("%d ", nse[i]);
    //     }printf("\n");

    //     for(int i=0; i<h_count; i++){
    //         printf("%d ", pse[i]);
    //     }printf("\n");
    for (int i = 0; i < h_count; i++)
    {
        int width = nse[i] - pse[i] - 1;
        int height = h[i];
        int area = height * width;

        maxArea = (area > maxArea) ? area : maxArea;
    }

    return maxArea;
}
