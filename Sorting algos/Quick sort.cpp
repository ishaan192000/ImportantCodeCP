#include<stdio.h>
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
qsort(int arr[], int start, int end)
{
	if(start < end)
	{
		int pivot = arr[start];
		int i = start;
		int j = end+1;
		while(i <j)
		{
			do{i++;}while(arr[i] < pivot && i <= end);
			do{j--;}while(arr[j] > pivot);
			if(i <j)
				swap(&arr[i], &arr[j]);
		}
		swap(&arr[j], &arr[start]);
		qsort(arr, start, j-1);
		qsort(arr, j+1, end);
	}
}
int main()
{
	int num;
	printf("Enter number of terms:");
	scanf("%d",&num);
	int arr[num];
	for(int i=0; i<num; i++)
		scanf("%d",&arr[i]);
	int start = 0;
	int end = num-1;
	qsort(arr, start, end);
	printf("Your sorted array is:");
	for(int i=0; i<num; i++)
		printf("%d ",arr[i]);
}
