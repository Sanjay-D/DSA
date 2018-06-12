#include<stdio.h>
#include<stdlib.h>
int peak(int **a, int r,int c,int mid)
{
	int i;
	int max=0,maxi=0;
	for(i=0;i<r;i++)
	{
		if(max<a[i][mid])
		{
			max=a[i][mid];
			maxi=i;
		}
	}
	if(mid==0 || mid==c-1)
		return max;
	if(max>=a[maxi][mid-1] && max>=a[maxi][mid+1])
		return max;
	if(max<a[maxi][mid-1])
		return peak(a,r,c,mid/2);
	return peak(a,r,c,3*mid/2);
}

int main()
{
	int i,j,m,n;
	scanf("%d %d",&n,&m);
	int **a=(int**)malloc(n*sizeof(int*));
	for(i=0;i<m;i++)
		a[i]=(int*)malloc(m*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	printf("%d\n",peak(a,n,m,m/2));
	for(i=0;i<n;i++)
	{
		int*p=a[i];
		free(p);
	}
}
