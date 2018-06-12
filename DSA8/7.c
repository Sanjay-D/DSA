#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int dfs(int **a,int vis[],int truth[],int n, int i)
{
	vis[i]=1;
	if(vis[a[i][0]]==0)
	{
		if(truth[i])
			truth[a[i][0]]=a[i][1];
		else
			truth[a[i][0]]=!a[i][1];
		return dfs(a,vis,truth,n,a[i][0]);
	}
	else
	{
		int t;
		if(truth[i])
			t=a[i][1];
		else
			t=!a[i][1];
		if(t==truth[a[i][0]])
			return 0;
		else
			return 1;
	}
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int **a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(2*sizeof(int));
	for(i=0;i<n;i++)
	{
		int t;
		char s[10];
		scanf("%d %s",&t,s);
		a[i][0]=t-1;
		if(s[0]=='t')
			a[i][1]=1;
		else
			a[i][1]=0;
	}

	int vis[n],truth[n];
	for(i=0;i<n;i++)
		vis[i]=0;
	for(i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			int j;
			truth[i]=1;
			int temp[n];
			for(j=0;j<n;j++)
				temp[j]=vis[j];
			if(dfs(a,vis,truth,n,i))
			{
				for(j=0;j<n;j++)
					vis[j]=temp[j];
				truth[i]=0;
				if(dfs(a,vis,truth,n,i))
				{
					printf("PARA\n");
					return 0;
				}
			}
		}
	}
	printf("NOT PARA\n");
}
