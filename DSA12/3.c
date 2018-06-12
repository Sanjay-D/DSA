#include<stdio.h>

int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	int cost[n][n];
	int done[n];
	for(i=0;i<n;i++)
		done[i]=-1;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	for(i=0;i<n;i++)
	{
		int min=10000,index;
		for(j=0;j<n;j++)
		{
			if(done[j]!=-1)
				continue;
			int s=0;
			for(k=i+1;k<n;k++)
			{
				int min2=10000;
				for(l=0;l<n;l++)
				{
					if(done[l]!=-1 || l==j)
						continue;
					if(min2>cost[k][l])
						min2=cost[k][l];
				}
				s+=min2;
			}
			if(min>s+cost[i][j])
			{
				min=s+cost[i][j];
				index=j;
			}
		}
		done[index]=i;
	}
//	for(i=0;i<n;i++)
	//	printf("%d\n",done[i]);
	int count=0;
	for(i=0;i<n;i++)
		count+=cost[done[i]][i];
	printf("%d\n",count);
}
