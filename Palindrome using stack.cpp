#include<stdio.h>
#include<string.h>
#define max 100
void push(char stack[], int *top, char data)
{
	if(*top < max-1)
		stack[++(*top)] = data;
}
char pop(char stack[], int *top)
{
	if(*top >= 0)
		return (stack[(*top)--]);
}
int palindrome(char str[], int len)
{
	char stack[max];
	int top = -1;
	int LEN;
	int i;
//	if(len%2 == 0)
	LEN = len/2;
//	else
//		LEN = (len -1)/2;
	for(i=0; i<LEN; i++)
		push(stack, &top, str[i]);
	if(len %2 != 0)
		i++;
	char temp;
	for(i; i<len; i++)
	{
		temp = pop(stack, &top);
		if(temp != str[i])
			return -1;
	}
	return 1;
}
int main()
{
	char str[100];
	printf("Enter your string:");
	scanf("%s",str);
	int len = strlen(str);
	int value = palindrome(str, len);
	if(value == 1)
		printf("Palindrome\n");
	else
		printf("Not a Palindrome\n");
}
