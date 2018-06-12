#include<stdio.h>
#include<stdlib.h>
int min=100,max=-100;
struct node
{
	int a;
	struct node *l;
	struct node *r;
}*first,*ind;

void find(struct node* n,int x)
{
	if(n!=NULL)
	{
		if(n->a==x)
			ind=n;
		find(n->l,x);
		find(n->r,x);
	}
}
void inorder(struct node* n)
{
	if(n!=NULL)
	{
		inorder(n->l);
		printf("%d ",n->a);
		inorder(n->r);
	}
}

void minmax(struct node* n,int hd)
{
	if(n!=NULL)
	{
		if(hd<min)
			min=hd;
		if(hd>max)
			max=hd;
		minmax(n->l,hd-1);
		minmax(n->r,hd+1);
	}
}
void print(struct node* n,int hd,int lineno)
{
		if(n!=NULL)
	{
		if(hd==lineno)
			printf("%d ",n->a);
		print(n->l,hd-1,lineno);
		print(n->r,hd+1,lineno);
	}
}
int main()
{
	int i,n,m,l,r;
	char c;
	scanf("%d %d",&n,&m);
	first=(struct node*)malloc(sizeof(struct node));
	first->a=m;
	first->l=NULL;
	first->r=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %c",&l,&r,&c);
		ind=NULL;
		find(first,l);
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->l=NULL;
		temp->r=NULL;
		temp->a=r;
		if(c=='L')
			ind->l=temp;
		else
			ind->r=temp;
	}
	minmax(first,0);
	for(i=min;i<=max;i++,printf("\n"))
		print(first,0,i);
}
