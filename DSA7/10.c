#include<stdio.h>

int min(int key[],int done[],int n)
{
	int min=1000000,mi,i;
	for(i=0;i<n;i++)
	{
		if(done[i]==0 && key[i]<min)
		{
			min=key[i];
			mi=i;
		}
	}
	return mi;
}

int main()
{
	int i,j,n,m;
	scanf("%d %d",&n,&m);
	int graph[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			graph[i][j]=0;
	for(i=0;i<m;i++)
	{
		int x,y,r;
		scanf("%d %d %d",&x,&y,&r);
		graph[x-1][y-1]=r;
		graph[y-1][x-1]=r;
	}
//	printf("a\n");
	int parent[n],key[n],done[n];
	for(i=0;i<n;i++)
	{
		key[i]=10000000;
		done[i]=0;
	}
	//printf("b\n");
	key[0]=0;
	parent[0]=-1;
	for(i=0;i<n-1;i++)
	{
		int u=min(key,done,n);
		done[u]=1;
	//	printf("c\n");
		for(j=0;j<n;j++)
		{
			if(graph[u][j] && done[j]==0 && graph[u][j]<key[j])
			{
				parent[j]=u;
				key[j]=graph[u][j];
			}
		}
	}
	//printf("d\n");
	j=0;
	
	for(i=1;i<n;i++)
		j+=graph[i][parent[i]];
	printf("%d\n",j);
}
