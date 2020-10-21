#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char str[1000];
	printf("Enter your string for checking whether it is a poaindrome or not :");
	scanf("%s",str);
	int i,len = strlen(str);
	for(i=0; i<=len/2; i++)
	{
		if(*(str+i) != *(str+len-i-1))
		{
			printf("Not a Palindrome....\n");
			break;
		}
	}
	if(i >= len/2)
		printf("Palindrome...\n");
}
