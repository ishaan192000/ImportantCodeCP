#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct{
	int exp;
	int coef;
}polynomial;
int main()
{
	polynomial poly1[max], poly2[max];
	printf("Enter your polynomial as : exponent & Coeffecient of X^exponenet:\n");
	printf("Enter -1 -1 to exit entering polynomial\n");
	int temp, temp2, i;
	for(i=0; i<max; i++)
	{
		scanf("%d %d",&temp ,&temp2);
		if(temp != -1 && temp2 !=-1)
		{
			temp = poly1[i].exp;
			temp2 = poly1[i].coef;	
		}
		else
		break;
	}
	int term_a = i-1;
	printf("Enter your polynomial as : exponent & Coeffecient of X^exponenet:\n");
	printf("Enter -1 -1 to exit entering polynomial\n");
	for(i=0; i<max; i++)
	{
		scanf("%d %d",&temp ,&temp2);
		if(temp != -1 && temp2 !=-1)
		{
			temp = poly2[i].exp;
			temp2 = poly2[i].coef;		
		}
		else
		break;
	}
	int term_b = i-1;
	int j=0, k=0;
	i=0;
	polynomial poly3[max];
	int count = 0;
	while(i < term_a || j < term_b)
	{
		if(poly1[i].exp > poly2[j].exp)
		{
			poly3[k].exp = poly1[i].exp;
			poly3[k].coef = poly1[i].coef;
			k++;
			i++;
		}	
		else if(poly1[i].exp < poly2[j].exp)
		{
			poly3[k].exp = poly2[j].exp;
			poly3[k].coef = poly2[j].coef;
			k++;
			j++;
		}
		else
		{
			int x =  poly1[i].coef + poly2[j].coef;
			i++;
			j++;
			if(x != 0)
			{
				poly3[k].exp = poly1[i].exp;
				poly3[k].coef = x;
				k++;
			}
			else
				continue;
		}
		count++;
	}
	printf("Polynomial Is:\n");
	for(i=0; i<count; i++)
		printf("X^%d : %d\n", poly3[i].exp, poly3[i].coef);
}
