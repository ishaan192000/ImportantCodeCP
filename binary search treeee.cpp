#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    node *left, *right;
}node;
node * insert(node *root, int val)
{
    if(root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = val;
        root->right = NULL;
        root->left = NULL;
    }
    else
    {
        if(val <= root->data)
        {
            if(root->left == NULL){
                node *newn;
                newn = (node *)malloc(sizeof(node));
                newn->data = val;
                newn->left = NULL;
                newn->right = NULL;
                root->left = newn;
            }
            else
                insert(root->left, val);
        }
        else
        {
            if(root->right == NULL){    
                node *newn;
                newn = (node *)malloc(sizeof(node));
                newn->data = val;
                newn->left = NULL;
                newn->right = NULL;
                root->right = newn;
            }else   
                insert(root->right, val);
        }
    }
    return root;
}
node *create()
{
    node *root;
    root = NULL;
    int val;
    while(1)
    {
        scanf("%d",&val);
        if(val != -1)
            root = insert(root, val);
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
int main()
{
    node *root;
    root = create();  
    printf("Here is your binary tree, you have entered : \n");
    display(root);  
}