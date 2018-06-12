#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b){
    return a>b ? a : b ;
}

int maxWeight(int wt[], int color[],int w, int n, int m)
{
	int dp[m][w+1];

	int i,j;
    memset(dp,0,sizeof(dp));

	i=0;
	while(color[i]==1)
	{
		dp[0][wt[i]]=1;
		i++;
	}

	int current_color = 2;

	for(i=1; i<n; i++)
	{
		j=0;
		while(j<=w)
		{
			if(color[i]==current_color)
			{
				if(wt[i]<=j)
					dp[current_color][j] = max(dp[current_color][j],dp[current_color-1][j-wt[i]]);
				j++;
			}
			else
			{
				current_color = color[i];
			}
		}
	}

	int maxm = 0;
	for(i=0; i<=w; i++ )
	{
		if(dp[m-1][i])
		{
			maxm = i;
		}
	}

	return (maxm==0) ? -1 : (w-maxm);
}


int main()
{
	int t,i,j;
	scanf("%d",&t);

	int ans[t];

	for(i=0; i<t; i++)
	{
	    int n,c,w;
        scanf("%d %d %d",&n,&c,&w);
		int wt[n];
		int color[n];
		for(j=0; j<n; j++)
			scanf("%d",&wt[j]);
		for(j=0; j<n; j++)
			scanf("%d",&color[j]);
		printf("%d\n",maxWeight(wt,color,w,n,c));
	}
}
