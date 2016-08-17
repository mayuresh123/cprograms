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
				break;
			case 2:
				break;
			case 3:
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
