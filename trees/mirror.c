#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct node
{
	int data;
	struct node *left,*right;
}NODE;

NODE *get_new_node(int data);
void display_mirror(NODE *tree1,NODE *tree2,NODE *root);
bool check_subtree(NODE *tree1,NODE *tree2);
NODE *insert(int data,NODE *tree);
void FreeMemory(NODE *tree);
void Inorder(NODE *tree1);

int main()
{
	NODE *tree1,*tree2;
	int data,choice;
	do
	{
		printf("\n\
				*****MENU*****\n\
				0.Display Inorder Tree1\n\
				1.Tree1\n\
				2.Tree2\n\
				3.Check Sub-tree\n\
				4.Display mirror\n\
				5.Exit\n\
			Enter your choice :  ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				Inorder(tree1);
				break;
			case 1:
				{
					data = 0;
					tree1 = NULL;
					do
					{
						printf("\nEnter the node to insert (0 to exit): ");
						scanf("%d",&data);
						if(data!=0)
							tree1 = insert(data,tree1);
					}while(data!=0);
				}
				break;
			case 2:
				{
					data = 0;
					tree2 = NULL;
					do
					{
						printf("\nEnter the node to insert (0 to exit): ");
						scanf("%d",&data);
						if(data!=0)
							tree2 = insert(data,tree2);
					}while(data!=0);
				}
				break;
			case 3:
				{
					bool isSubTree = check_subtree(tree1,tree2);
					if(isSubTree)
						printf("\nSubTree\n");
					else
						printf("\nNot a SubTree\n");
				}
				break;
			case 4:
				display_mirror(tree1->left,tree1->right,tree1);	
				Inorder(tree1);
				break;
			case 5:
				break;
			default:
				printf("\nInvalid choice\n");
		}
	}while(choice!=5);
	return 0;
}

NODE *get_new_node(int data)
{
	NODE *node = (NODE *)malloc(sizeof(NODE));
	node->data = data;
	return node;
}

NODE *insert(int data,NODE *root)
{
	//struct node *temp = root;
	if(root == NULL)
	{
		//temp = get_node(data);
		return get_new_node(data);
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

void Inorder(NODE *root)
{
	if(root == NULL)
	{
		return;
	}
	Inorder(root->left);
	printf("%d ",root->data);
	Inorder(root->right);
}

void display_mirror(NODE *tree1,NODE *tree2,NODE *root)
{
	if(root == NULL)
	{
		return;
	}
	root->left = tree2;
	root->right = tree1;
	tree2==NULL?display_mirror(NULL,NULL,tree2):(display_mirror(tree2->left!=NULL?tree2->left:NULL,tree2->right!=NULL?tree2->right:NULL,tree2));
	tree1==NULL?display_mirror(NULL,NULL,tree1):(display_mirror(tree1->left!=NULL?tree1->left:NULL,tree1->right!=NULL?tree1->right:NULL,tree1));
}

bool compare(NODE *tree1,NODE *tree2)
{
	if(tree2 == NULL)
	{
		return true;
	}
	if(tree1->data == tree2->data)
	{
		if(tree1->left!=NULL && tree1->right!=NULL)
		{
			return (compare(tree1->left,tree2->left) && compare(tree1->right,tree2->right));
		}
		else if(tree1->left == NULL)
		{
			return compare(tree1->right,tree2->right);
		}
		else if(tree1->right == NULL)
		{
			return compare(tree1->left,tree2->left);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool check_subtree(NODE *tree1,NODE *tree2)
{
	if(tree2 == NULL)
		return true;
	while(tree1!=NULL)
	{
		if(compare(tree1,tree2))
		{
			return true;
		}
		else
		{
			if(tree1->left!=NULL)
			{
				check_subtree(tree1->left,tree2);
			}
			else if(tree1->right!=NULL)
			{
				check_subtree(tree1->right,tree2);
			}	
		}
	}
	return false;
}
