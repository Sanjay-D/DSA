#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node* link;
}*first,*temp,*temp2;

int main()
{
	int i,n,m;
	scanf("%d %d",&n,&m);
	first=(struct node*)malloc(sizeof(struct node));
	temp=first;
	first->a=1;
	//printf("1\n");
	for(i=0;i<n-1;i++)
	{
	//	printf("2\n");
		struct node *temp1=(struct node*)malloc(sizeof(struct node));
		temp1->a=i+2;
		temp->link=temp1;
		temp=temp1;
	}
	temp->link=first;
//printf("3\n");
	while(temp->link->a != temp->a)
	{
	//	printf("4\n");
		temp2=temp->link;
		temp->link=temp2->link;
		free(temp2);
		for(i=0;i<m-1;i++)
		{
			temp=temp->link;
		}
	}
	printf("%d \n",temp->a);
}
