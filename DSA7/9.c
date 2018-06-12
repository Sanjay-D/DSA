#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node* prev;
	struct node* next;
}* first;
struct node* bst(int size)
{
	if(size<=0)
		return NULL;
	struct node* left=bst(size/2);
	struct node* root=first;
	root->prev=left;
	first=first->next;
	root->next=bst(size-(size/2)-1);
	return root;
}

void inorder(struct node* x)
{
	if(x!=NULL)
	{
		printf("%d ",x->a);
		inorder(x->prev);
		
		inorder(x->next);
		
	}
}


int main()
{
	struct node* temp,*temp1;
	first=(struct node*)malloc(sizeof(struct node));
	first->next=NULL;
	first->prev=NULL;
	first->a=1;
	temp1=first;
	int i;
	for(i=1;i<7;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->a=i+1;
		temp->prev=temp1;
		temp1->next=temp;
		temp->next=NULL;
		temp1=temp;
	}
	//temp=first;
	first=bst(7);
	inorder(first);
	printf("\n");
}
