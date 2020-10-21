#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct matrix{
	int row, col, val;
};
void display(matrix mat4[])
{
	int k = 1;
	for(int i=0; i<mat4[0].row; i++)
	{
		for(int j=0; j<mat4[0].col; j++)
		{
			if(mat4[k].row == i && mat4[k].col == j && k<= mat4[0].val)
				printf("%d ",mat4[k++].val);
			else
				break;
		}
		printf("\n");
	}
}
void create(matrix mat1[])
{
	int temp;
	int k = 1;
	printf("Enter your rows and columns : ");
	scanf("%d %d",&mat1[0].row ,&mat1[0].col);
	for(int i=0; i<mat1[0].row; i++)
	{
		for(int j=0; j<mat1[0].col; j++)
		{
			scanf("%d",&temp);
			if(temp != 0)
			{
				mat1[k].row = i;
				mat1[k].col = j;
				mat1[k++].val = temp;
			}
		}
	}
	mat1[0].val = k-1;
	printf("\n<<<<< _______________________________________________ >>>>>> \n");
	printf("\nYour entered matrix : \n");
	display(mat1);	
	printf("\n<<<<< _______________________________________________ >>>>>> \n");
}
void transpose(matrix mat1[], matrix mat2[])
{
	int rowterm[mat1[0].col];
	for(int i=0; i<mat1[0].col; i++)
		rowterm[i] = 0;
	int start[mat1[0].col];
	for(int i=1; i<=mat1[0].val; i++)
		rowterm[mat1[i].col]++;
	start[0] = 1;
	for(int i=1; i<mat1[0].col; i++)
		start[i] = start[i-1] + rowterm[i-1];
	int index;
	mat2[0].col = mat1[0].row;
	mat2[0].row = mat1[0].col;
	mat2[0].val = mat1[0].val;
	for(int i=1; i<=mat1[0].val; i++)
	{
		index = start[mat1[i].col];
		mat2[index].col = mat1[i].row;
		mat2[index].row = mat1[i].col;
		mat2[index].val = mat1[i].val;
		start[mat1[i].col]++;
	}
	printf("\n<<<<< _______________________________________________ >>>>>> \n");
	printf("Transpose of your matrix be : \n");
	display(mat2);	
	printf("\n<<<<< _______________________________________________ >>>>>> \n");

}
void mutliply(matrix mat1[], matrix mat2[], matrix mat3[])
{
	
}
int main()
{
	matrix mat1[max], mat2[max], mat3[max];	
	create(mat1);
	create(mat2);
	transpose(mat2, mat3);
	mutliply(mat1, mat2, mat4);
}