#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	int val;
	struct no* next;
}node;

node* h[10];

void insert(int n)
{
	node* p = (node*)malloc(sizeof(node));
	p->val=n;
	p->next=NULL;
	int h1 = n%10;
	if(h[h1]==NULL || h[h1]->val==99999)
		h[h1]=p;
	else
	{
		h1 = 7-(n%7);
		if(h[h1]==NULL || h[h1]->val==99999)
			h[h1]=p;
		else
		{
			node* q = h[h1];
			while(1)
			{
				if(q->next==NULL)
					break;
				q=q->next;
			}
			q->next=p;
		}
	}
}

void delete(int n)
{
	int h1 = n%10;
	if(h[h1]->val==n)
	{
		h[h1]->val=99999;
		return;
	}
	h1 = 7-(n%7);
	node* p=h[h1];
	while(p)
	{
		if(p->val==n)
		{
			p->val=99999;
			return;
		}
		p=p->next;
	}
}

int search(int n)
{
	int h1=n%10;
	if(h[h1] && h[h1]->val==n)
		return 1;
	h1 = 7-(n%7);
	node* p = h[h1];
	while(p)
	{
		if(p->val==n)
			return 1;
		p=p->next;
	}
	return 0;
}

int main()
{
	int i;
	for(i=0; i<10 ;i++)
		h[i]=NULL;
	insert(43);
	insert(76);
	insert(3);
	insert(25);
	insert(65);
	/*for(int i=0; i<10; i++)
		while(h[i])
		{
			printf("%d %d\n",i, h[i]->val);
			h[i]=h[i]->next;
		}	*/
	printf("search 3: %d\n",search(3));
	return 0;
}
