#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    node *left, *right;
}node;
node *insert(node *root, int val)
{
    if(root != NULL)
    {
        if(root->data >= val)
        {
            if(root->left == NULL)
            {
                node *newn;
                newn = (node *)malloc(sizeof(node));
                newn->data = val;
                root->left = newn;
                newn->left = NULL;
                newn->right = NULL;
            }else
                insert(root->left, val);           
        }
        else
        {
            if(root->right == NULL)
            {
                node *newn;
                newn = (node *)malloc(sizeof(node));
                newn->data = val;
                root->right = newn;
                newn->left = NULL;
                newn->right = NULL;
            }
            else
            {
                insert(root->right, val);
            }
            
        }
    }
    else
    {
        root = (node *)malloc(sizeof(node));
        root->data = val;
        root->left = NULL;
        root->right = NULL;
    }
    return root;
}
node *create()
{
    node *root;
    root = NULL;
    int temp;
    printf("Keep Entering data and to exit enter -1: \n");
    while(1)
    {
        scanf("%d",&temp);
        if(temp != -1)
            root = insert(root, temp);
        else 
            break;
    }
    return root;
}
void display(node *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("%d\n",root->data);
        display(root->right);
    }
}
int height(node *root)
{
    if(root != NULL)
    {
        int x = 0, y = 0;
        x = height(root->left);
        y = height(root->right);
        if(x > y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}
int main()
{
    node *root;
    printf("Heyaaa...................\n");
    root = create();
    display(root);
    int ht = height(root);
    printf("Height : %d",ht);
}