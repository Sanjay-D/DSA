#include<stdio.h>
#include<stdlib.h>
int max(int a, int b)
{
	return (a>b)?a:b;
}
int find(int i, int j, int **a, int **d,int n)
{
	if(i<0 || i>=n || j<0 || j>=n)
		return 0;
	if(d[i][j]!=-1)
		return d[i][j];
	int t=0;
	if (j<n-1 && ((a[i][j] +1) == a[i][j+1]))
       return d[i][j] = 1 + find(i,j+1,a,d,n);      //might be a problem. try copying and using values of a temp array.
 
    if (j>0 && (a[i][j] +1 == a[i][j-1]))
       return d[i][j] = 1 + find(i,j-1,a,d,n);
 
    if (i>0 && (a[i][j] +1 == a[i-1][j]))
       return d[i][j] = 1 + find(i-1,j,a,d,n);
 
    if (i<n-1 && (a[i][j] +1 == a[i+1][j]))
       return d[i][j] = 1 + find(i+1,j,a,d,n);
 
    
    return d[i][j] = 1;
		
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int **a=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(n*sizeof(int));
	int **d=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		d[i]=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			d[i][j]=-1;
			scanf("%d",&a[i][j]);
		}
	}
	int res=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(d[i][j]==-1)
				find(i,j,a,d,n);
			res=max(res,d[i][j]);
		}
	}
	printf("%d\n",res);
	for(i=0;i<n;i++,printf("\n"))
		for(j=0;j<n;j++)
			printf("%d ",d[i][j]);
}
