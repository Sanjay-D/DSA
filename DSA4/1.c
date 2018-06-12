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

void merged(int a[],int b[],int l, int r)
{
	int temp[r-l+1],temp1[r-l+1];
	int mid=(l+r)/2;
	int i=l,j=mid+1,k=0;
	if(l<r)
	{
		merged(a,b,l,mid);
		merged(a,b,mid+1,r);
		
		while(i<=mid && j<=r)
		{
			if(a[i]>a[j])
			{
				temp[k]=a[i];
				temp1[k++]=b[i++];
			}
			else if(a[j]>a[i])
			{
				temp[k]=a[j];
				temp1[k++]=b[j++];
			}
			else
			{
				if(b[i]<=b[j])
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
	int n,i,j;
	scanf("%d",&n);
	int a[n],b[n],c[n],d[n],e[n];      //5 8 1 5 3 1 5 8 5 3 1
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		c[i]=i;
		d[i]=0;
		e[i]=1;
	}
	int k=0;
	merge(b,c,0,n-1);

	for(i=0;i<=n-1;i++)
	{
		d[k]=c[i];
		while(b[i]==b[i+1] && i<n-1)
		{
			e[k]++;
			i++;
		}
		k++;
	}
	merged(e,d,0,k-1);
	for(i=0;i<k;i++)
	{
		for(j=e[i];j>0;j--)
			printf("%d ",a[d[i]]);
	}
}
