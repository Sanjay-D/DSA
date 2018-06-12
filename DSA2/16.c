#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int i,j,k,c=1;
	scanf("%d",&n);
	int **a = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
     	a[i] = (int *)malloc(n * sizeof(int));
    for(i=0;i<(n+1)/2;i++)
    {
    	for(j=i;j<n-i;j++)
    	{
    		a[i][j]=c;
    		c++;
		}
		for(j=i+1;j<n-i;j++)
		{
			a[j][n-i-1]=c;
			c++;
		}
		for(j=n-2-i;j>=i;j--)
		{
			a[n-i-1][j]=c;
			c++;
		}
		for(j=n-2-i;j>=i+1;j--)
		{
			a[j][i]=c;
			c++;
		}
	}
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
}
