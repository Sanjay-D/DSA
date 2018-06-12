#include<stdio.h>

void mergea(int a[],int l, int r)
{
	int temp[r-l+1];
	int k=0,mid=(l+r)/2,i=l,j=mid+1;
	if(l<r)
	{
		mergea(a,l,mid);
		mergea(a,mid+1,r);
		
		while(i<=mid && j<=r)
		{
			if(a[i]<=a[j])
			{
				temp[k++]=a[i++];
			}
			else
			{
				temp[k++]=a[j++];
			}
		}
		while(i<=mid)
		{
			temp[k++]=a[i++];
		}
		while(j<=r)
		{
			temp[k++]=a[j++];
		}
		for(i=0;i<k;i++)
		{
			a[i+l]=temp[i];
		}
	}
}

void merged(int a[],int l, int r)
{
	int temp[r-l+1];
	int k=0,mid=(l+r)/2,i=l,j=mid+1;
	if(l<r)
	{
		merged(a,l,mid);
		merged(a,mid+1,r);
		
		while(i<=mid && j<=r)
		{
			if(a[i]>=a[j])
			{
				temp[k++]=a[i++];
			}
			else
			{
				temp[k++]=a[j++];
			}
		}
		while(i<=mid)
		{
			temp[k++]=a[i++];
		}
		while(j<=r)
		{
			temp[k++]=a[j++];
		}
		for(i=0;i<k;i++)
		{
			a[i+l]=temp[i];
		}
	}
}

int main()
{
	int i,j,n;
	scanf("%d",&n);
	int e[n-(n/2)],o[n/2];
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			scanf("%d",&e[i/2]);	
		}	
		else
		{
			scanf("%d",&o[i/2]);
		}
	}
	mergea(e,0,n-(n/2)-1);
	merged(o,0,(n/2)-1);
	for(i=0;i<n-(n/2);i++)
		printf("%d ",e[i]);
	for(i=0;i<n/2;i++)
		printf("%d ",o[i]);
	printf("\n");
}
