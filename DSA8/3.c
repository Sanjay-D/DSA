#include<stdio.h>
#include<stdlib.h>
int n,c;

void lpath(int u,int **a,int path[],int vis[],int index,int len)
{
	vis[u]=1;
	path[index]=u;
	index++;
	
	if(len>c)
		c=len;


	int i;
	for(i=0;i<n;i++)
	{
		if(a[u][i]!=0 && vis[i]==0)
		{
			len+=a[u][i];
			lpath(i,a,path,vis,index,len);
			len-=a[u][i];
		}
	}
//	index--;
	vis[u]=0;
	//len-=a[index-1][index];
	
}

int main()
{
	int i,j,index=0;
	c=0;
	scanf("%d",&n);
	//printf("%d\n",n);
	int **a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	int path[n],vis[n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			char t;
			scanf("%c",&t);
			scanf("%c",&t);
			//printf("%c\n",t);
			if(t=='N')
				a[i][j]=0;
			else
				a[i][j]=t-48;
		}

	for(i=0;i<n;i++)
		vis[i]=0;
	for(i=0;i<n;i++)
		lpath(i,a,path,vis,index,0);
	printf("%d\n",c);
}
