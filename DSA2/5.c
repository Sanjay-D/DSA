#include<stdio.h>
#include<stdlib.h>
struct node
{
	int r,c,v;
	struct node* n; 	
}*sparse,*temp,*trans,*s1,*s2;

int main()
{
	sparse=NULL;
	trans=NULL;
	s1=NULL;
	s2=NULL;
	int a[6][6],b[6][6];
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			if(a[i][j]!=0)
			{
				temp=(struct node*)malloc(sizeof(struct node));
				temp->r=i;
				temp->c=j;
				temp->v=a[i][j];
				temp->n=NULL;
				if(sparse!=NULL)
				{
					s1->n=temp;
					s1=temp;
				}	
				else
				{
					sparse=temp;
					s1=sparse;
				}
			}
			if(a[j][i]!=0)
			{
				temp=(struct node*)malloc(sizeof(struct node));
				temp->r=i;
				temp->c=j;
				temp->v=a[j][i];
				temp->n=NULL;
				if(trans!=NULL)
				{
					s2->n=temp;
					s2=temp;
				}	
				else
				{
					trans=temp;
					s2=trans;
				}
			}	
		}	
	}
	printf("\nSparse matrix is \n");
	temp=sparse;
	while(temp!=NULL)
	{
		printf("%d %d %d \n",temp->r,temp->c,temp->v);
		temp=temp->n;	
	}
	printf("\nTranspose matrix is \n");
	temp=trans;
	while(temp!=NULL)
	{
		printf("%d %d %d \n",temp->r,temp->c,temp->v);
		temp=temp->n;	
	}	
}
