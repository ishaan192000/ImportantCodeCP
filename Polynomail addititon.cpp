#include<stdio.h>
int maxo(int x, int y)
{
	if(x>y)
		return x;
	else
		return y;
}
int main()
{
	int deg_a, deg_b;
	printf("Enter degree of your polynomial:");
	scanf("%d",&deg_a);
	int poly1[deg_a+1];
	
	printf("Enter your polynomial:\n");
	for(int i=deg_a; i>=0; i--)
	{
		printf("Enter coeffecient of X^%d : ",i);
		scanf("%d",&poly1[i]);
	}
	
	printf("Enter degree of your polynomial:");
	scanf("%d",&deg_b);
	int poly2[deg_b];
	
	for(int i=deg_b; i>=0; i--)
	{
		printf("Enter coeffecient of X^%d : ",i);
		scanf("%d",&poly2[i]);
	}
	
	int max = maxo(deg_a, deg_b);
	int poly3[max];
	int k=0, i=0 ,j=0;
	while(i <= deg_a && j<= deg_b)
		poly3[k++] = poly1[i++] + poly2[j++];
	while(i <= deg_a)
		poly3[k++] = poly1[i++];
	while(j <= deg_b)
		poly3[k++] = poly2[j++];
	int count = 0;
	for(int i=0; i <= max; i++)
	{
		if(poly3[i] != 0)
			printf("Coeffecient of X^%d : %d\n", i, poly3[i]);
		else
			count++;
	}
	if(count == max+1)
		printf("Your polynomial is : 0\n");
	
}
