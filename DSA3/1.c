#include<stdio.h>
#include<math.h>
int cost(int h[],int c[],int n,int x)
{
	int count=0;
	int i;
	for(i=0;i<n;i++)
	{
		count+=abs(h[i]-x)*c[i];
	}
	return count;
}

int bin(int h[],int c[],int n)
{
	int maxh=0;
	int i,ans=100000000;
	for(i=0;i<n;i++)
		if(h[i]>maxh)
			maxh=h[i];
	int high=maxh+1;
	int low=0;
	while(high>low)
	{
		int mid=(high+low)/2;
		int bm=(mid>0)?cost(h,c,n,mid-1):1000000000;
		int m=cost(h,c,n,mid);
		int am=cost(h,c,n,mid+1);
		
		if(ans==m)
			break;
		ans=(ans<=m)?ans:m;
		if(bm<=m)
			high=mid;
		else if(am<=m)
			low=mid+1;
	}
	return ans;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int h[n],c[n];
	for(i=0;i<n;i++)
		scanf("%d",&h[i]);
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	printf("%d \n",bin(h,c,n));
}
