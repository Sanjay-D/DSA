#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int **a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int* )malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
	for(i=0;i<m;i++)
	{
		int n1,n2;
		scanf("%d %d",&n1,&n2);
		a[n1-1][n2-1]=1;
		a[n2-1][n1-1]=1;
	}
	int c=0;
	int sp=0,vis[n],sta[n];
	for(i=0;i<n;i++)
		vis[i]=0,sta[i]=0;
	for(i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			c++;
			sta[sp]=i;
			sp++;
			
			while(sp>0)
			{
				int b=sta[--sp];
				//printf("%d\n",b);
				vis[b]=1;
				int j;
				for(j=0;j<n;j++)
				{
					if(vis[j]==0 && a[b][j]==1)
						sta[sp++]=j;
				}
			}
		}
		
	}
	printf("%d\n",c);
}
