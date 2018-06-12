#include<stdio.h>
#include <stdlib.h>

int m[100][100];
int n,p[100];

int s(int a, int b)
{
	int sum=0;
	int i;
	for(i=a; i<=b; i++)
		sum+=p[i];
	return sum%100;
}

void dp()
{
	int l,i,k;
	for(l=2; l<=n; l++)
	{
		for(i=0; i<n-l+1; i++)
		{
			int j=i+l-1;
			m[i][j]=99999999;
			for(k=i; k<j; k++)
			{
				int q = m[i][k]+m[k+1][j]+ s(i,k)*s(k+1,j);
				if(q<m[i][j])
					m[i][j]=q;
			}
		}
	}
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=0; i<n; i++)
		scanf("%d",&p[i]);
	for (i = 0; i <=n; ++i)
		m[i][i]=0;
	dp();
	printf("%d\n",m[0][n-1] );
}
