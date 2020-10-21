#include<stdio.h>
void sort(int arr[], int num)
{
	int index = num-1;
	for(int i=0; i<num; i++)
	{
		index = i;
		for(int j=i; j<num; j++)
		{
			if(arr[index] > arr[j])
			{
				index = j;
			}
		}
		{
			int temp;
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
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
	sort(arr, num);
	printf("Your sorted array is: ");
	for(int i=0; i<num; i++)
		printf("%d ",arr[i]);
}
