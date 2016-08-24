#include<stdio.h>
#include<malloc.h>

struct node 
{
	int data;
	struct node *left,*right;
};

struct node *get_node(int data);
struct node *insert(int data,struct node *root);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
struct node *delete(int data,struct node *root);
struct node *del_case_a(int data,struct node *root);
struct node *del_case_b(int data,struct node *root);
struct node *del_case_c(int dtat,struct node *root);


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
	//struct node *temp = root;
	if(root == NULL)
	{
		//temp = get_node(data);
		return get_node(data);
	}
	else if(data < root->data)
	{
		root->left = insert(data,root->left);
	}
	else if(data > root->data)
	{
		root->right = insert(data,root->right);
	}
	else
	{
		printf("\nUnable to insert duplicate element\n");
		return root;
	}
	return root;
}

struct node *delete(int data,struct node *root)
{
	return NULL;
}

void preorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void postorder(struct node *root)
{
	if(root == NULL)
	{
		return;	
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}



























