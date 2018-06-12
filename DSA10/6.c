#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char a;
	struct node *left,*right;
};

struct node * tree(char in[],char post[],int start, int end,int *p)
{
	if(start>end)
		return NULL;
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->a=post[*p];
	(*p)--;
	if(start==end)
		return temp;
	
	int index,i;
	for(i=start;i<=end;i++)
	{
		if(in[i]==temp->a)
			index=i;
	}
	
	temp->right=tree(in,post,index+1,end,p);
	temp->left=tree(in,post,start,index-1,p);
	
	return temp;
}

void pre(struct node *h)
{
	if(h==NULL)
		return;
	printf("%c",h->a);
	pre(h->left);
	pre(h->right);
}

int main()
{
	int n,i,j;
	char a[20],b[20];
	scanf("%s",a);
	scanf("%s",b);
	n=strlen(a);
	int p=n-1;
	struct node *first=tree(a,b,0,n-1,&p);
	
	pre(first);
}
