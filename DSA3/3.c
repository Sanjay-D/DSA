#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[15]={0};
int n,m,s=0,ans;

int check(int sum)
{
	int i,s=0,c=0;
	for(i=0; i<n; i++)
	{
		if(a[i]>sum)
			return 0;
		if(a[i]+s>sum)
		{
			c++;
			s=a[i];
		}
		else
			s+=a[i];
	}
	return (c+1<=m);
}

void bs(int l, int h)
{
	while(l<=h)
	{
		int m=(l+h)/2;
		int c = check(m);	
		if(c)
		{	h=m-1;	ans=m;}
		else
			l=m+1;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	bs(0,s);
	printf("%d\n",ans);
}
