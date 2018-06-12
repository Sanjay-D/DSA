#include<stdio.h>
#include<stdlib.h>
int c=0,n;
void paths(int u,int d, int l, int **a,int vis[],int path[],int index)
{
	vis[u]=1;
	path[index]=u;
	index++;
	
	if(u==d && index-1==l)
		c++;
	else if(index-1<=l)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(a[u][i]==1 && vis[i]==0)
				paths(i,d,l,a,vis,path,index);
		}
	}
	//index--;
	vis[u]=0;
		
}

int main()
{
	int s,d,i,j,l;
	scanf("%d %d",&n,&l);
	int **a=(int**)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	scanf("%d %d",&s,&d);
	int vis[n],path[n],index=0;
	for(i=0;i<n;i++)
		vis[i]=0;
	paths(s,d,l,a,vis,path,index);
	printf("\n%d \n",c);
}
