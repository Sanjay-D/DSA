#include<stdio.h>

void merge(int a[],int l, int r)
{
	int temp[r-l+1],mid=(l+r)/2;
	int i=l,j=mid+1,k=0;
	
	if(l<r)
	{
		merge(a,l,mid);
		merge(a,mid+1,r);
		while(i<=mid && j<=r)
		{
			if(a[i]>=a[j])
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
	int n,i,j;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge(a,0,n-1);
	i=0;
	while(i<n)
	{
		int c=1;
		while(i<n-1 && a[i]==a[i+1])
			c++,i++;
		if(c%2==1)
		{
			printf("Vishal\n");
			return 0;
		}
		i++;
	}
	printf("Tanmay\n");
}
