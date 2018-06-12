#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
	return (a>b)?a:b;
}

void longest(char a[],char b[],int m, int n)
{
	int l[m+1][n+1];
	int i,j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				l[i][j]=0;
			else if(a[i-1]==b[j-1])
			{
				l[i][j]=1+l[i-1][j-1];
			}
			else
			{
				l[i][j]=max(l[i-1][j],l[i][j-1]);
			}
		}
	}
	
	char c[l[m][n]+1];
	c[l[m][n]]='\0';
	i=m,j=n;
	int index=l[m][n];
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			c[index-1]=a[i-1];
			i--;
			j--;
			index--;
		}
		else if(l[i-1][j]>l[i][j-1])
			i--;
		else
			j--;
	}
	printf("%d\n",l[m][n]);
	printf("%s\n",c);
}

int main()
{
	int m,n,i;
	char a[20],b[20];
	scanf("%s",a);
	scanf("%s",b);
	m=strlen(a);
	n=strlen(b);
	longest(a,b,m,n);
	
}
