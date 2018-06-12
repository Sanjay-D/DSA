#include<stdio.h>
#include<stdlib.h>
int n;
int a[5][5]=   {{0,1,1,1,0},
				{1,0,0,0,0},
				{1,0,0,0,0},
				{1,0,0,0,1},
				{0,0,0,1,0}};
int val[5]={0};
int isCycle(int u, int vis[],int p)
{
	vis[u]=1;
	int i;
	for(i=0;i<n;i++)
	{
		if(a[u][i]==1 && vis[i]==0)
		{
			if(isCycle(i,vis,u))
				return 1;
		}
		else if(a[u][i]==1 && i!=p)
			return 1;
	}
	return 0;
}

int main()
{
	int i,j;
	n=5;
	int vis[n],root[n],rootv[n],rooti=0;
	for(i=0;i<n;i++)
		vis[i]=0;
	if(isCycle(0,vis,-1))
	{
		printf("Not a tree\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			printf("Not a tree \n");
			return 0;
		}
		int c=0;
		for(j=0;j<n;j++)
		{
			if(a[i][j])
				c++;
			if(c>3)
			{
				printf("Not a binary tree \n");
				return 0;
			}
		}
		if(c==1 || c==2)
			root[rooti]=i,rootv[rooti++]=c;   //If separate value array is given initialise this with that 
	}
	printf("Binary tree \n");
	for(i=0;i<rooti;i++)
	{
		
		if(f)
		{
			printf("Binary search tree\n");
			return 0;
		}
	}

}
