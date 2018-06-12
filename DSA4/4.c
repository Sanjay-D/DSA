#include<stdio.h>

int main()
{
	int n,i,j,time=0,s=0;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	int max=0;
	for(i=0;i<n;i++)
	{
		if(max<b[i])
			max=b[i];
	}
	for(i=0;i<=max;i++)
	{
		int t=0;
		for(j=0;j<n;j++)
		{
			if(a[j]<=i && b[j]>=i)
				t++;
		}
		if(t>s)
		{
			s=t;
			time=i;
		}
	}
	printf("%d \n",time);
}
