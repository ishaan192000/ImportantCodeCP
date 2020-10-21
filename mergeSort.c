#include<stdio.h>

void merge(int start, int mid, int end, int *arr)
{
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];
    k = 0;
    for (i = start; i <= end; i++)
        arr[i] = temp[k++];
}

void mergeSort(int start, int end, int *arr)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(start, mid, arr);
        mergeSort(mid + 1, end, arr);
        merge(start, mid, end, arr);
    }
}

int main()
{
	int l, i;
	printf("Enter size of list\n");
	scanf("%d",&l);
	int arr[l];
	
	for(i = 0; i < l; i++)
		scanf("%d", &arr[i]);
	
	mergeSort(0, l-1, arr);
	
	printf("Sorted array: \n");
	for(i = 0; i < l; i++)
		printf("%d\n", arr[i]);
	
	return 0;
}
