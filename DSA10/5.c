#include<stdio.h>
#include<stdlib.h>

int safe(int **a,int n,int r, int c)
{
	int i,j;
	for(i=0;i<n;i++)
		if(a[r][i]==1 || a[i][c]==1)
			return 0;
	for(i=r,j=c;i>=0 && j>=0;i--,j--)
		if(a[i][j]==1)
			return 0;
	for(i=r,j=c;i<n && j>=0;i++,j--)
		if(a[i][j]==1)
			return 0;
			
	return 1;
}

int solve(int **a,int n, int col)
{
	if(col>=n)
		return 1;
	int i;
	for(i=0;i<n;i++)
	{
		if(safe(a,n,i,col))
		{
			a[i][col]=1;
			if(solve(a,n,col+1)==1)
				return 1;
			else 
				a[i][col]=0;
		}
	}
	return 0;
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int **a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
	if(solve(a,n,0)==0)
	{
		printf("Not possible\n");
		return 0;
	}
	for(i=0;i<n;i++,printf("\n"))
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
	
}
