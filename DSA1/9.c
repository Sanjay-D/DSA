#include<stdio.h>
int main()
{
	int p,n,m;

	int i,j,k;
	scanf("%d %d",&m,&p);
		int a[m][p];
	for(i=0;i<m;i++)
		for(j=0;j<p;j++)
			scanf("%d",&a[i][j]);
	scanf("%d %d",&p,&n);
	int b[p][n];
	for(i=0;i<p;i++)
		for(j=0;j<n;j++)
			scanf("%d",&b[i][j]);
	int c[m][n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			int pr=0;
			for(k=0;k<p;k++)
			{
				pr+=a[i][k]*b[k][j];
			}
			c[i][j]=pr;
		}
	}
	int s=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			s+=c[i][j];
	}
	printf("%d \n",s);
}
