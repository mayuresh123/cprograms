#include<stdio.h>
#include<malloc.h>

#define MAX 10

struct node 
{
	int data;
	struct node *left,*right;
};

struct node *arr[MAX];
int top = -1;

struct node *get_node(int data);
struct node *insert(int data,struct node *root);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
struct node *delete(int data,struct node *root);
struct node *del_case_a(int data,struct node *root);
struct node *del_case_b(int data,struct node *root);
struct node *del_case_c(int dtat,struct node *root);

void push(struct node *element);
struct node *pop();
int isEmpty();
int isFull();

int main()
{
	int data,choice;
	struct node *root = NULL;
	do
	{
		printf("\n\
				***Menu****\n\
				1.Insert\n\
				2.Delete\n\
				3.Inorder\n\
				4.Preorder\n\
				5.Postorder\n\
				6.Exit\n\
			Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter data to insert : ");
				scanf("%d",&data);
				root = insert(data,root);
				break;
			case 2:
				printf("\nEnter data to delete : ");
				scanf("%d",&data);
				root = delete(data,root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
		}
	}while(choice!=6);
	return 0;
}

struct node *get_node(int data)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

struct node *insert(int data,struct node *root)
{
	struct node *temp = root;
	if(root == NULL)
	{
		return get_node(data);
	}
	while(root->left != NULL && data < root->data)
	{
		root = root->left;	
	}
	while(root->right != NULL && data > root->data)
	{
		root = root->right;
	}
	if(data < root->data)
		root->left = get_node(data);
	else if(data > root->data)
		root->right = get_node(data);
	else
		printf("\nUnable to add duplicate element\n");
	return temp;
}

struct node *delete(int data,struct node *root)
{
	return NULL;
}

void preorder(struct node *root)
{
	top = -1;
	struct node *element = root;
	push(element);
	printf("%d ",element->data);
	while(element->left !=NULL)
	{
		element = element->left;
		push(element);
		printf("%d ",element->data);
	}
	while(isEmpty())
	{
		struct node *elem = pop();
		if(elem->right != NULL)
		{
			elem = elem->right;
			push(elem);
			printf("%d ",elem->data);
			while(elem->left!=NULL)
			{
				elem = elem->left;
				push(elem);
				printf("%d ",elem->data);
			}
		}
	}
}

void inorder(struct node *root)
{
	top = -1;
	struct node *element = root;
	push(element);
	while(element->left != NULL)
	{
		element = element->left;
		push(element);
	}
	while(isEmpty())
	{
		struct node *elem = pop();
		printf("%d ",elem->data);
		if(elem->right!=NULL)
		{
			push(elem->right);
			elem = elem->right;
			while(elem->left!=NULL)
			{
				elem = elem->left;
				push(elem);
			}
		}
	}
}

void postorder(struct node *root)
{
}

void push(struct node *element)
{
	//printf("in push\n");
	if(isFull())
	{
		arr[++top] = element;
	}
	//printf("Element pushed : %d",arr[top]->data);
}

struct node *pop()
{
	if(isEmpty())
	{
		struct node *temp = arr[top];
		top--;
		return temp;
	}

}

int isFull()
{
	if(top > 9)
	{
		return 0;
	}
	return 1;
}

int isEmpty()
{
	if(top == -1)
	{
		return 0;
	}
	return 1;
}























