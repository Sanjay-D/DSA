#include<stdio.h>
#include<stdlib.h>
int n,c;

void lpath(int u,int **a,int path[],int vis[],int index,int len)
{
	vis[u]=1;
	path[index]=u;
	index++;
	
	int i;
	for(i=0;i<n && c==0;i++)
	{
		if(a[u][i]!=0)
		{
			if(vis[i]==0)
			{
				len+=a[u][i];
				lpath(i,a,path,vis,index,len);
				len-=a[u][i];
			}
			else
			{
				len+=a[u][i];
				if(len<=0)
					c=1;
				len-=a[u][i];
			}
		}
	}

	vis[u]=0;
	
	
}

int main()
{
	int i,j,index=0;
	c=0;
	scanf("%d",&n);
	char t;
	int **a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	int path[n],vis[n];
	scanf("%c",&t);
	//printf("%c",t);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%c",&t);
			if(t=='N')
				a[i][j]=0,scanf("%c",&t);
			else if(t=='-')
			{
				a[i][j]=0;
				do
				{
					scanf("%c",&t);
					if(t<=57 && t>=48)
						a[i][j]=a[i][j]*10+(t-48);
				}while(t<=57 && t>=48);
				a[i][j]*=-1;	
			}
			else if(t<=57 && t>=48)
			{
				a[i][j]=t-48;
				do
				{
					scanf("%c",&t);
					if(t<=57 && t>=48)
						a[i][j]=a[i][j]*10+(t-48);
				}while(t<=57 && t>=48);
			}
		}
	/*for(i=0;i<n;i++,printf("\n"))
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);*/
	for(i=0;i<n;i++)
		vis[i]=0;
	lpath(0,a,path,vis,index,0);
	if(c)
		printf("1\n");
	else
		printf("0\n");
}
