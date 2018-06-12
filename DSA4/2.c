#include<stdio.h>

void merge(int a[],int l, int r)
{
	int i=l,temp[r-l+1];
	int mid=(l+r)/2;
	int j=mid+1,k=0;
	if(r>l)
	{
		merge(a,l,mid);
		merge(a,mid+1,r);
		
		while(i<=mid && j<=r)
		{
			if(a[i]<=a[j])
				temp[k++]=a[i++];
			else
				temp[k++]=a[j++];
		}
		while(i<=mid)
			temp[k++]=a[i++];
		while(j<=r)
			temp[k++]=a[j++];
		for(i=0;i<k;i++)
			a[i+l]=temp[i];
	}
}

int main()
{
	int i,j=1,n,sum;
	scanf("%d %d",&n,&sum);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int l=0,r=n-1;
	merge(a,l,r);
	while(l<r)
	{
		if(a[l]+a[r]==sum)
		{
			printf("Yes\n");
			return 0;
		}
		else if(a[l]+a[r]<sum)
			l++;
		else
			r--;
	}
	printf("No\n");
}
