#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
	int data;
	node *left, *right;
	node *parent;
}node;
node*create();
void function();
void in(node *);
void pre(node *);
void post(node *);
node* recursive();
node* nonrecursive();
void display(node *);
int traversal(node *);
node*sucessor(node *);
node* non(node *, int);
node* predecessor(node *);
node* insert(node *, int);
node* Search(node *, int);
node* search_elem(node *, int );
node* delete_node(node *, int );
// ------------------------------------------------------------------------------
int main()
{
	printf(" \t\t <<<< Welcome to Binary Search Tree >>>>\n ");
	function();
	printf(" \t\t <<<< Thanks for using binary search tree function >>>> \n");
}
void function()
{
	int ans, val;
	node *root = NULL;
	while(1)
	{
		printf("Enter your choice : \n");
		printf("1. Create \n");
		printf("2. Display\n");
		printf("3. Search\n");
		printf("4. Delete Node\n");
		printf("5. Exit\n");
		scanf("%d",&ans);
		if(ans == 5)
			break;
		switch(ans)
		{
			case 1: root = create(); break;
			case 2: display(root);break;
			case 3: printf("Enter value to be searched...\n");
					scanf("%d",&val);
					node *tempo;
					tempo = search_elem(root, val);
					printf("%d",tempo->data);
					printf("\n %u \n", &tempo);break;
			case 4: printf("Enter value to be deleted....");
					scanf("%d",&val);
					root = delete_node(root, val);break;
		}
	}
}
node *create()
{
	node *root;
	root = NULL;
	printf("Enter your choice : \n");
	printf("1. Recursive \n");
	printf("2. Non-Recursive \n");
	int ans;
	scanf("%d",&ans);
	switch(ans)
	{
		case 1: root = recursive();break;
		case 2: root = nonrecursive();break;
	}
	return root;
}
node * recursive()
{
	int val;
	node *root;
	root = NULL;
	printf("Keep Entering Value till -1 is entered \n");
	while(1)
	{
		scanf("%d",&val);
		if(val == -1)
			break;
		else
			root = insert(root, val);
	}
	return root;
}
node * insert(node *root, int val)
{
	if(root == NULL)
	{
		root = (node *)malloc(sizeof(node));
		root->data = val;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
	}
	else
	{
		if(val < root->data)
		{
			if(root->left != NULL)
				insert(root->left, val);
			else
			{
				node *newn;
				newn = (node *)malloc(sizeof(node));
				newn->data = val;
				newn->left = NULL;
				newn->right = NULL;
				root->left = newn;
				newn->parent = root;
			}
		}
		else if(val > root->data)
		{
			if(root->right != NULL)
				insert(root->right, val);
			else
			{
				node *newn;
				newn = (node *)malloc(sizeof(node));
				newn->data = val;
				newn->left = NULL;
				newn->right = NULL;
				root->right = newn;
				newn->parent = root;
			}
		}
		else
			printf("Unique Value Please ......\n");
	}
	return root;
}
node * nonrecursive()
{
	node *root = NULL;
	node *temp = NULL;
	printf("Keep Entering Data till -1 is input.....\n");
	int val;
	while(1)
	{
		scanf("%d",&val);
		if(val == -1)
			break;
		else
		{
			temp = root;
			while(1)
			{
				if(temp != NULL)
				{
					if(val < temp->data)
					{
						if(temp->left == NULL)
						{
							node *newn;
							newn = (node *)malloc(sizeof(node));
							newn->data = val;
							newn->left = NULL;
							newn->right = NULL;
							temp->left = newn;
							newn->parent = temp;
							break;
						}
						else
							temp = temp->left;
					}
					else if(val > temp->data)
					{
						if(temp->right == NULL)
						{
							node *newn;
							newn = (node *)malloc(sizeof(node));
							newn->data = val;
							newn->left = NULL;
							newn->right = NULL;
							temp->right = newn;
							newn->parent = temp;
							break;
						}	
						else
							temp = temp->right;
					}
					else
					{
						printf("\t\tUnique Number Please...... \n");
						break;
					}
				}
				else
				{
					root = (node *)malloc(sizeof(node));	
					root->data = val;
					root->left = NULL;
					root->right = NULL;
					root->parent = NULL;
					break;
				}
			}
		}
	}
	return root;
}
void display(node *root)
{
	printf("Enter your choice : \n");
	printf("1. In-order Treaversal\n");
	printf("2. Pre-Oreder Traversal\n");
	printf("3. Post-Order Traversal\n");	
	int ans;
	scanf("%d",&ans);
	switch(ans)
	{
		case 2: pre(root); break;
		case 3: post(root);break;
		default : in(root);break;
	}
}
void in(node *root)
{
	if(root != NULL)
	{
		in(root->left);
		printf("%d\n",root->data);
		in(root->right);
	}
}
void post(node *root)
{
	if(root != NULL)
	{
		post(root->left);
		post(root->right);
		printf("%d\n",root->data);
	}
}
void pre(node *root)
{
	if(root != NULL)
	{
		printf("%d\n",root->data);
		pre(root->left);
		pre(root->right);
	}
}
node * Search(node *root, int val)
{
	if(root != NULL)
	{
		if(root->data == val)
			return root;
		else if(val < root->data)
			return Search(root->left , val);
		else
			return Search(root->right , val);
	}
	else 
		return root;
}
node * search_elem(node *root, int val)
{
	printf("Enter your choice : \n");
	printf("1. Recursive search\n");
	printf("2. Non-recursive search\n");
	int ans;
	node *temp;
	scanf("%d",&ans);
	switch(ans)
	{
		case 2: temp = non(root, val); break;
		default : temp = Search(root, val); break;
	}
	return temp;
}
node* non(node *root, int val)
{	
	node *temp;
	temp = root;
	while(1)
	{
		if(temp != NULL)
		{
			if(val < temp->data)
				temp = temp->left;
			else if(val > temp->data)
				temp =temp->right;
			else
				return temp;
		}
	}
	node *tor = NULL;
	return tor;
}
node * delete_node(node *root , int val)
{
	node *temp;
	temp = Search(root, val);
	if(temp->left == NULL && temp->right == NULL)
	{
		node *ptr;
		ptr = temp->parent;
		if(ptr->left == temp)
			ptr->left = NULL;
		else
			ptr->right = NULL;
		free(temp);		
	}
	else if(temp->left == NULL || temp->right == NULL)
	{
		node * tempo;
		node *aux;
		tempo = temp->parent;
		if(temp->left == NULL)
			aux = temp->right;
		else
			aux = temp->left;
		if(tempo->left == temp)
			tempo->left = aux;
		else
			temp->right = aux;
		free(temp);
		aux->parent = tempo;
			
	}
	else
	{
		node *tempo;
		tempo = sucessor(temp);
		temp->data = tempo->data;
		delete(tempo);
	}
	return root;
}
int traversal(node *root)
{
	if(root != NULL)
	{
		if(root->right != NULL)
			return traversal(root->right);
		else
		{
			node *temp;
			temp = root->parent;
			if(root == temp->left)
				temp->left = NULL;
			else
				temp->right = NULL;
			free(root);
			return root->data;
		}
	}
}
node *sucessor(node *root)
{
	if(root->right != NULL)
	{
		node *temp;
		temp = root;
		while(temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}
	else
	{
		node *temp;
		temp = root->parent;
		while( temp != NULL && temp->right == root)
		{
			temp= temp->parent;
			root =root->parent;
		}
		return temp;
	}
}
