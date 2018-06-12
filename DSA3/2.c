#include <stdio.h>
#include<stdlib.h>
int merges(int a[],int temp[],int l, int r)
{
	int count=0;
	int mid=(l+r)/2;
	if(r>l)
	{
		count+=merges(a,temp,l,mid);
		count+=merges(a,temp,mid+1,r);
		count+=merge(a,temp,l,mid+1,r);
	}
	return count;
}

int merge(int a[],int temp[],int l,int mid,int r)
{
	int count=0;
	int i=l;
	int j=mid;
	int k=l;
	
	while(i<=mid-1 && j<=r)
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			int t=i;
			for(;t<mid;t++)
				printf("(%d,%d) ",a[t],a[j]);
			temp[k++]=a[j++];
			count+=(mid-i);
			
		}
	}
	while(i<=mid-1)
	{
		temp[k++]=a[i++];
	}
	while(j<=r)
	{
		temp[k++]=a[j++];
	}
	for(i=0;i<=r;i++)
	{
		a[i]=temp[i];
	}
	return count;
}

int main()
{
  int n;
  scanf("%d",&n);
  int a[n],temp[n];
  int i;
  for(i=0;i<n;i++)
  	scanf("%d",&a[i]);
  printf("%d\n",merges(a,temp,0,n-1));	
}
