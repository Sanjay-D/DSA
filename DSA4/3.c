#include<stdio.h>

void merge(int a[],int b[],int l, int r)
{
	int temp[r-l+1],temp1[r-l+1];
	int k=0,mid=(l+r)/2,i=l,j=mid+1;
	if(l<r)
	{
		merge(a,b,l,mid);
		merge(a,b,mid+1,r);
		
		while(i<=mid && j<=r)
		{
			if(a[i]<=a[j])
			{
				temp[k]=a[i];
				temp1[k++]=b[i++];
			}
			else
			{
				temp[k]=a[j];
				temp1[k++]=b[j++];
			}
		}
		while(i<=mid)
		{
			temp[k]=a[i];
			temp1[k++]=b[i++];
		}
		while(j<=r)
		{
			temp[k]=a[j];
			temp1[k++]=b[j++];
		}
		for(i=0;i<k;i++)
		{
			a[i+l]=temp[i];
			b[i+l]=temp1[i];
		}
	}
}

int main()
{
	int n,i,j,c=0;
	scanf("%d",&n);
	int a[n],b[n],vis[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=i;
		vis[i]=0;
	}
	merge(a,b,0,n-1);
	
	for(i=0;i<n;i++)
	{
		if(vis[i] || b[i]==i)
			continue;
		int cycle=0;
		j=i;
		while(vis[j]!=1)
		{
			vis[j]=1;
			cycle++;
			j=b[j];
		}
		c+=cycle-1;
	}
	printf("%d \n",c);
}
