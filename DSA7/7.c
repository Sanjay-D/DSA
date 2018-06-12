#include<stdio.h>
#include<stdlib.h>
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

int countn(struct node* h)
{
	if(h==NULL)
		return 0;
	return(1+countn(h->l)+countn(h->r));
}


int isC(struct node *h,int i, int n)
{
	if(h==NULL)
		return 1;
	if(i>=n)
		return 0;
		
	return(isC(h->l,2*i+1,n) && isC(h->r,2*i+2,n));
}

int isH(struct node* h)
{
	if(h->l==NULL && h->r==NULL)
		return 1;
	if(h->r==NULL)
	{
		return(h->a >= h->l->a);
	}
	else
	{
		if(h->a >= h->l->a && h->a >= h->r->a)
			return (isH(h->l) && isH(h->r));
		else
			return 0;
	}
}

int isheap(struct node* h)
{
	int count=countn(h);
	int i=0;
	if(isC(h,i,count) && isH(h))
		return 1;
	else
		return 0; 
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
	i=isheap(first);
	if(i)
		printf("Easy \n");
	else
		printf("Hard\n");
	
}
