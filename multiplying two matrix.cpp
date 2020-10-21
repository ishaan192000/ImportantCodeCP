#include<stdio.h>
#include<stdlib.h>
int main()
{
	int row, col;
	printf("Enter your row and col :");
	scanf("%d %d",&row, &col);
	int arr[row][col];
	printf("Enter your matrix :\n");
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			scanf("%d",&arr[i][j]);
	}
	printf("\n<<<<<<<<<<-------------------->>>>>>>>>>\n");	
	printf("So, here is your matrix : \n");
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	int row2, col2;
	printf("\n<<<<<<<<<<-------------------->>>>>>>>>>\n");
	printf("Enter row and col of second matrix : ");
	scanf("%d %d",&row2, &col2);
	int arr2[row2][col2];
	printf("Enter your second matrix : ");
	for(int i=0; i<row2; i++)
	{
		for(int j=0; j<col2; j++)
			scanf("%d",&arr2[i][j]);
	}
	printf("\n<<<<<<<<<<-------------------->>>>>>>>>>\n");
	printf("So, here is your second matrix : \n");
	for(int i=0; i<row2; i++)
	{
		for(int j=0; j<col2; j++)
			printf("%d ",arr2[i][j]);
		printf("\n");
	}
	printf("\n<<<<<<<<<<-------------------->>>>>>>>>>\n");
	if(col == row2)
	{
		int multi[row][col2];
		for(int i=0; i<row; i++)
			for(int j=0; j<col2; j++)
				multi[i][j] = 0;
	
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col2; j++)
			{
				for(int k=0; k<row2; k++)
				{
					multi[i][j] += (arr[i][k]*arr2[k][j]); 
				}
			}
		}
		printf("Here comes your multiplication matrix : \n");
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col2; j++)
				printf("%d ",multi[i][j]);
			printf("\n");
		}
		printf(" << ........Thanx for using our program ....... >> \n");
	}
	else
		printf("\n\n....Parameters are incorrect ....\n Multiplication not possible \n");
}

