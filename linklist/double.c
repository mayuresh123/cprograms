#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *get_node(int data);
struct node *insert(int data,int pos,struct node *root);
struct node *delete(int pos,struct node *root);
void display(struct node *root);

int main()
{
	int choice;
	int data,pos;
	struct node *root = NULL;
	do
	{
		printf("\n\
				***Menu***\n\
				1.Insert\n\
				2.Delete\n\
				3.Display\n\
				4.Exit\n\
			Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the data to insert : ");
				scanf("%d",&data);
				printf("\nEnter the position : ");
				scanf("%d",&pos);
				root = insert(data,pos,root);
				break;
			case 2:
				printf("\nEnter the position to delete : ");
				scanf("%d",&pos);
				root = delete(pos,root);
				break;
			case 3:
				display(root);
				break;
			case 4:
				printf("\nBye\n");
				break;
			default:
				printf("\nInvalid choice\n");
		}
	}while(choice!=4);
}

struct node *get_node(int data)
{
	struct node *newnode = (struct node *) malloc (sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nUnable to allocate memory\n");
		exit(-1);
	}
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

struct node *insert(int data,int pos,struct node *root)
{
	struct node *head=root,*temp=NULL,*newnode=NULL;
	int n=1;
	newnode = get_node(data);
	if(root == NULL)
	{
		return newnode;
	}
	if(pos == 1)
	{
		root->prev = newnode;
		newnode->next = root;
		return newnode;
	}	
	else
	{
		for(n=1;n<pos-1 && head->next!=NULL;head = head->next, n++);
		if(head->next == NULL)
		{
			newnode->prev = head;
			head->next = newnode;
		}
		else
		{
			temp = head->next;
			newnode->prev = head;
			head->next = newnode;
			newnode->next = temp;
		}
		return root;
	}
}

struct node *delete(int pos,struct node *root)
{
	struct node *temp,*head = root,*prev = NULL,*next = NULL;
	int n = 1;
	while(n!=pos && head!=NULL)
	{
		n++;
		head = head->next;
	}
	if(head == NULL)
	{
		printf("\nInvalid position\n");
		exit(-1);
	}
	temp = head;
	temp->prev->next = temp->next;
	free(temp);
	return root;
}

void display(struct node *root)
{
	printf("\n[");
	while(root)
	{
		printf(" %d,",root->data);
		root = root->next;
	}
	printf("\b ]\n");
}
