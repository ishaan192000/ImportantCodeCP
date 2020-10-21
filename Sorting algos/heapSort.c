#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void adjust(int *arr, int i, int n)
{
    if(2 * i <= n)
    {
        if(2 * i + 1 <= n)
        {
            int index = *(arr + 2 * i) > *(arr + 2 * i + 1) ? 2 * i : 2 * i + 1;
            if(*(arr + i) < *(arr + index))
            {
                swap((arr + i), (arr + index));
                if(2 * index <= n)
                    adjust(arr, index, n);
            }
        }
        else
        {
            if(*(arr + i) < *(arr + 2 * i))
            {
                swap((arr + i), (arr + 2 * i));
                if(4 * i <= n)
                    adjust(arr, 2 * i, n);
            }
        }
    }
}

void heapSort(int *arr, int n)
{
    int i;
    for(i = n/2; i > 0; i--)
        adjust(arr, i, n);
    
    for(i = n; i>= 2; i--)
    {
        swap(&arr[1], &arr[i]);
        adjust(arr, 1, i - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int i, arr[n + 1];
    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);
    for(i = 1; i < n + 1; i++)
        printf("%d ",arr[i]);
}