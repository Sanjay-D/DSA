#include<stdio.h>
int c;
int dist(int a, int b)
{
	return (a>b)?(a-b):(b-a);
}
void dfs(int a[],int size,int curr,int time, int tot)
{
	if(time<0)
		return;
	if(time==0)
	{
		if(tot>c)
			c=tot;
		return;
	}
	else
	{
		if(tot>c)
			c=tot;
		int i;
		for(i=curr+1;i<size;i++)
		{
			dfs(a,size,i,time-dist(a[curr],a[i]),tot+1);
		}
	}
}
int main()
{
	c=1;
	int n,i,j,k;
	scanf("%d %d",&n,&k);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	dfs(a,n,0,k,1);
	printf("%d\n",c);
}
