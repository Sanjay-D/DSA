#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node *l,*r;
}*first;

void print(struct node *h)
{
	printf("%d ",h->a);
	struct node *t=h->r;
	while(t!=h)
	{
		printf("%d ",t->a);
		t=t->r;
	}
}

struct  node* conc(struct node *l,struct node *r)
{
	if(l==NULL)
		return r;
	if(r==NULL)
		return l;
	
	struct node *llast=l->l;
	struct node *rlast=r->l;
	
	llast->r=r;
	r->l=llast;
	
	l->l=rlast;
	rlast->r=l;
	
	return l;
	
}

struct node* conv(struct node* head)
{
	if(head==NULL)
		return NULL;
		
	struct node* l=conv(head->l);
	struct node* r=conv(head->r);
	
	head->l=head;
	head->r=head;
	
	return conc(conc(l,head),r);
	
}

struct node* add(int a)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->a=a;
	temp->l=NULL;
	temp->r=NULL;
	
	return temp;	
} 

int main()
{
	int i,n;
	first=(struct node*)malloc(sizeof(struct node));
	first->a=3;
	first->l=add(5);
	first->l->l=add(4);
	first->l->r=add(2);
	first->r=add(1);
	
	first=conv(first);
	print(first);
	printf("\n");
}
