#include<stdio.h>
#include<malloc.h>
struct node
{
	char data;
	struct node **child;
};

int main()
{
	struct node *a;
	a = (struct node *) malloc(sizeof(struct node));
	a->data = 'A';
	a->child = (struct node **) malloc(sizeof(struct node *)*3);

	struct node *b,*c,*d;
	b = (struct node *) malloc(sizeof(struct node));
	c = (struct node *) malloc(sizeof(struct node));
	d = (struct node *) malloc(sizeof(struct node));

	b->data='B';	
	c->data='C';
	d->data='D';

	a->child[0] = b;
	a->child[1] = c;
	a->child[2] = d;

	//children of b
	b->child = (struct node **) malloc(sizeof(struct node *)*3);
	struct node *e,*f,*g;
	e = (struct node *) malloc(sizeof(struct node));
	f = (struct node *) malloc(sizeof(struct node));
	g = (struct node *) malloc(sizeof(struct node));

	e->data='E';
	f->data='F';
	g->data='G';

	b->child[0] = e;
	b->child[1] = f;
	b->child[2] = g;

	//children of c
	c->child = (struct node **) malloc(sizeof(struct node *)*3);
	struct node *h,*i,*j;
	h = (struct node *) malloc(sizeof(struct node));
	i = (struct node *) malloc(sizeof(struct node));
	j = (struct node *) malloc(sizeof(struct node));

	h->data='H';
	i->data='I';
	j->data='J';

	c->child[0] = h;
	c->child[1] = i;
	c->child[2] = j;

	//children of d
	d->child = (struct node **) malloc(sizeof(struct node *)*3);
	struct node *k,*l,*m;
	k = (struct node *) malloc(sizeof(struct node));
	l = (struct node *) malloc(sizeof(struct node));
	m = (struct node *) malloc(sizeof(struct node));

	k->data='K';
	l->data='L';
	m->data='M';

	d->child[0] = k;
	d->child[1] = l;
	d->child[2] = m;

	
}