#include<stdio.h>
void sort(int arr[], int num)
{
	int i,j,k;
	int temp;
	for(i=1; i<num; i++)
	{
		if(arr[i] < arr[i-1])
		{
			temp = arr[i];
			for(j = i-1; j >= 0; j--)
			{
				if(arr[j-1] > temp)
				{
					arr[j+1] = arr[j];
				}
				else
				{
					arr[j+1] = arr[j];
					arr[j] = temp;
					break;
				}
			}
		}
	}
	
}
int main()
{
	int num;
	printf("Enter your number of terms:");
	scanf("%d",&num);
	int arr[num];
	for(int i=0; i<num; i++)
		scanf("%d",&arr[i]);
	sort(arr, num);
	for(int i=0; i<num; i++)
		printf("%d ",arr[i]);
}
