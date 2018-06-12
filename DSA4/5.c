#include<stdio.h>
#include<math.h>
int fac(int n)
{
	int i,c=0;
	for(i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			if(n/i==i)
				c++;
			else
				c+=2;
		}
	}
	return c;
}

void merge(int a[],int l, int r)
{
	int temp[r-l+1];
	int k=0,mid=(l+r)/2,i=l,j=mid+1;
	if(l<r)
	{
		merge(a,l,mid);
		merge(a,mid+1,r);
		
		while(i<=mid && j<=r)
		{
			if(fac(a[i])>=fac(a[j]))
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
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
