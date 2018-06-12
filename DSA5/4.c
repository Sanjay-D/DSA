#include<stdio.h>

int main()
{
	int k,i,j,n,m,r;
	scanf("%d %d %d",&n,&m,&r);
	int a[n][m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	printf("\n");
	for(k=0;k<n/2;k++)
	{
		int x=(2*(n+m-2-4*k));
		int r1=r%x;
		int t[x];
		
		int c=0;
		for(i=k,j=k;i<n-k;i++)
			t[(r1+c)%x]=a[i][j],c++;
		for(j=k+1,i=n-k-1;j<m-k;j++)
			t[(r1+c)%x]=a[i][j],c++;
		for(i=n-k-2,j=m-k-1;i>=k;i--)
			t[(r1+c)%x]=a[i][j],c++;
		for(i=k,j=m-k-2;j>k;j--)
			t[(r1+c)%x]=a[i][j],c++;
		
		c=0;
		for(i=k,j=k;i<n-k;i++)
			a[i][j]=t[c],c++;
		for(j=k+1,i=n-k-1;j<m-k;j++)
			a[i][j]=t[c],c++;
		for(i=n-k-2,j=m-k-1;i>=k;i--)
			a[i][j]=t[c],c++;
		for(i=k,j=m-k-2;j>k;j--)
			a[i][j]=t[c],c++;
	}
	
	for(i=0;i<n;i++,printf("\n"))
		for(j=0;j<m;j++)
			printf("%d ",a[i][j]);
}
