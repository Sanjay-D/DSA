#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
	return (a>b)?a:b;
}
int pal(char a[],char b[],int k,int n)
{
	int d[n+1][n+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				d[i][j]=0;
			else if(a[i-1]==b[j-1])
				d[i][j]=1+d[i-1][j-1];
			else
				d[i][j]=max(d[i][j-1],d[i-1][j]);
		}
	}
	if((n-d[n][n])>k)
		printf("No\n");
	else
		printf("Yes\n");
}
int main()
{
	int n,i;
	char a[20],b[20];
	scanf("%s",a);
	scanf("%d",&n);
	for(i=strlen(a)-1;i>=0;i--)
		b[strlen(a)-i-1]=a[i];
	b[strlen(a)]='\0';
	pal(a,b,n,strlen(a));
}
