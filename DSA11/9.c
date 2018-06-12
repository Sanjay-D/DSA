#include<stdio.h>
#include<string.h>
int min(int a, int b, int c)
{
	if(a<=b)
	{
		if(a<=c)
			return a;
		return c;
	}
	else
	{
		if(b<=c)
			return b;
		return c;
	}
}

int cost(char a[],char b[], int n, int m)
{
	int i,j;
	int d[n+1][m+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0)
				d[i][j]=j;
			else if(j==0)
				d[i][j]=i;
			else if(a[i]==b[j])
				d[i][j]=d[i-1][j-1];
			else
				d[i][j]=min(d[i-1][j-1]+1,d[i][j-1]+1,d[i-1][j]+1);
		}
	}
	return d[n][m];
}

int main()
{
	int n,m;
	char a[20],b[20];
	scanf("%s",a);
	scanf("%s",b);
	n=strlen(a);
	m=strlen(b);
	printf("%d\n",cost(a,b,n,m));
}
