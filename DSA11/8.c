#include<stdio.h>

int gp(int a[],int n)
{
	if(n<2)
		return n;
	if(n==2)
		return (a[1]%a[0]==0)+1;
	int i,j;
	int llg=1;
	int d[n][n];
	for(i=0;i<n;i++)
	{
		if(a[n-1]%a[i]==0)
			d[i][n-1]=2;
		else
			d[i][n-1]=1;
	}
	for(j=n-2;j>=1;j--)
	{
		int i=j-1,k=j+1;
		while(i>=0 && k<=n-1)
		{
			if(a[i]*a[k]<a[j]*a[j])
				k++;
			else if(a[i]*a[k]>a[j]*a[j])
			{
				if(a[j]%a[i]==0)
					d[i][j]=2;
				else 
					d[i][j]=1;
				i--;
			}
			else
			{
				d[i][j]=d[j][k]+1;
				if(d[i][j]>llg)
					llg=d[i][j];
				i--;
				k++;
			}
		}
		while(i>=0)
		{
			if(a[j]%a[i]==0)
				d[i][j]=2;
			else
				d[i][j]=1;
			i--;
		}
	}

	return llg;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",gp(a,n));		
}
