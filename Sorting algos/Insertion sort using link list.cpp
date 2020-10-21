//Insertion sort using link list
//Master
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    node *ptr;
}node;
void function();
node *create(int);
void sorting(node *);
void display(node *);
int main()
{
    printf("\t\t<<< Welcome to insertion sort program >>>\n");
    function();
    printf("\t\t<<< Thank  you for using our insertion function >>>\n");
}
void function()
{
    int num;
    printf("Enter number of terms you want to input:");
    scanf("%d",&num);
    node *start;
    start = create(num);
    printf("So your input data is : \n");
    display(start);
    printf("Now your data after sorting looks like : \n");
    sorting(start);
    display(start);
}
node * create(int num)
{
    node *start;
    node *temp, *curr;
    int val;
    start = (node *)malloc(sizeof(node));
    scanf("%d",&(start->data));
    num--;
    temp = start;
    while(num > 0)
    {
        curr = (node *)malloc(sizeof(node));
        scanf("%d",&val);
        if(val != -1)
        {
            curr->data = val;
            temp->ptr = curr;
            curr->ptr = NULL;
            temp = curr;
        }
        num--;
    }
    return start;
}
void display(node *start)
{
    node *temp;
    temp = start;
    while(temp != NULL)
    {
        printf(" %d \n", temp->data);
        temp = temp->ptr;
    }
}
void sorting(node *start)
{
    node *prev, *temp, *curr, *old;
    while(temp != NULL)
    {
        if(start->data > temp->data)
        {
            old = temp->ptr;
            temp->ptr = start;
            start = temp;
        }
        else if(curr->data < temp->data)
        {
            curr->ptr = temp;
            curr = temp;
        }
        else
        {
            old = temp->ptr;
            while(prev != curr)
            {
                            
            }
        }
        
    }
}
