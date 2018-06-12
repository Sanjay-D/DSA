#include<stdio.h>

int max(int a, int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int min(int a, int b)
{
	if(a<=b)
		return a;
	else 
		return b;
}

int median(int a[],int n)
{
	if(n%2==1)
		return a[n/2];
	else
		return (a[(n/2)-1]+a[n/2]);
}

int getMedian(int a[],int b[], int n)
{
	if(n==1)
		return (a[0]+a[1])/2;
	if(n==2)
		return (max(a[0],b[0])+min(a[1],b[1]))/2;
		
	int m1=median(a,n);
	int m2=median(b,n);
	
	if(m1==m2)
		return m1;
	else if(m1>m2)
	{
		if(n%2==0)
			return getMedian(a,b+n/2-1,n-n/2+1);
		return getMedian(a,b+n/2,n-n/2);
	}
	else
	{
		if(n%2==0)
			return getMedian(a+n/2-1,b,n-n/2+1);
		return getMedian(a+n/2,b,n-n/2);
	}
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	printf("%d\n",getMedian(a,b,n));
}
