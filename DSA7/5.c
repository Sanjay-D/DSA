#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node* next;
}*first;

struct node* sortmerge(struct node* a,struct node* b)
{
	struct node *result=NULL;
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
		
	if(a->a <= b->a)
	{
		result=a;
		result->next=sortmerge(a->next,b);
	}
	else
	{
		result=b;
		result->next=sortmerge(a,b->next);
	}
	return result;
}

void split(struct node *h,struct node **a,struct node **b)
{
	struct node *fast;
	struct node *slow;
	if(h==NULL || h->next==NULL)
	{
		*a=h;
		*b=NULL;
	}
	else
	{
		slow=h;
		fast=h->next;
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast!=NULL)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}
		*a=h;
		*b=slow->next;
		slow->next=NULL;
	}
}
void merge(struct node **head)
{
	struct node* h=*head;
	struct node* a;
	struct node* b;
	
	if(h==NULL || h->next==NULL)
		return;
	split(h,&a,&b);
	merge(&a);
	merge(&b);
	*head=sortmerge(a,b);
}
void print(struct node *h)
{
	while(h!=NULL)
	{
		printf("%d ",h->a);
		h=h->next;
	}
}
int main()
{
	first=(struct node*)malloc(sizeof(struct node));
	int i;
	first->a=7;
	struct node* temp1=first;
	for(i=1;i<=7;i++)
	{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->a=7-i;
		temp1->next=temp;
		temp->next=NULL;
		temp1=temp;
	}
	temp1=first;
	print(temp1);
	printf("\n");
	temp1=first;
	merge(&first);

	print(first);
	printf("\n");
}
