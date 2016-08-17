#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};

struct node *get_node(int data);
struct node *insert(int data,int pos,struct node *root);
struct node *delete(int pos,struct node *root);
void display(struct node *root);

int main()
{
	int choice,data,pos;
	struct node *root = NULL;
	do
	{
		printf("\n\
				***Menu***\n\
				1.Insert\n\
				2.Delete\n\
				3.Display\n\
				4.Exit\n\
			Enter your choice: ");
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

	}while(choice != 4);

}

struct node *get_node(int data)
{
	struct node *newnode = NULL;
	newnode = (struct node *) malloc (sizeof(struct node));
	if(newnode)
	{
		newnode->data = data;
		newnode->next = NULL;
		return newnode;
	}
	printf("\nUnable to locate memeory\n");
	exit(-1);
}

struct node *insert(int data, int pos, struct node *root)
{
	int n = 1;
	struct node *newnode = NULL,*head = root;
	newnode = get_node(data);
	if(newnode == NULL)
	{
		printf("\nUnable to allocate memory\n");
		exit(-1);
	}

	if(root == NULL)
	{
		return newnode;
	}
	if(pos == 1)
	{
		newnode->next = root;
		return newnode;
	}
	for(n=1;n<pos-1 && head->next != NULL;n++, head=head->next);

	if(head->next == NULL)
	{
		head->next = newnode;
	}
	else
	{
		struct node *temp = head->next;
		head->next = newnode;
		newnode->next = temp;
	}


	return root;
}

struct node *delete(int pos,struct node *root)
{
	int data,i=1;
	struct node *head = root ,*temp = NULL,*prev = NULL;
	while(i!=pos && head != NULL)
	{
		i++;
		prev = head;
		head = head->next;
	}
	if(head == NULL)
	{
		printf("\nInvalid Position\n");
		exit(-1);
	}
	temp = head;
	prev->next = temp->next;
	printf("\nNode at pos %d with value %d is deleted.\n",pos,temp->data);
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
	printf("\b]\n");
}
