#include<stdio.h>
int searches(int arr[], int num, int search)
{
	int mid;
	int index;
	int start = 0;
	int end = num;
	for(int i=0; i<num; i++)
	{
		mid = (start+end)/2;
		if(arr[mid] == search)
			return mid;
		else if(arr[mid] < search)
			start = mid;
		else
			end = mid;
//		printf("%d %d %d %d\n", start, end, mid , arr[mid]);
	}
	return -1;
}
int main()
{
	printf(":::This program searches the element:::\n\n");
	int num;
	printf("Enter number of elements to be entered:");
	scanf("%d",&num);
	int arr[num];
	printf("Enter your elements now!\n");
	for(int i=0; i<num; i++)
		scanf("%d",&arr[i]);
	int search;
	printf("Enter your element to be searched:");
	scanf("%d",&search);
	int index = searches(arr, num, search);
	if(index != -1)
		printf("Element is found in %d place in data",index+1);
	else
		printf("Element not found in data");
}
