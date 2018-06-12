#include<stdio.h>

int merge(int a[],int l, int r)
{
	if(l<r)
	{
		int mid=(l+r)/2,temp[r-l+1];
		int i=l,j=mid+1,k=0,count=0;
		
		count+=merge(a,l,mid);
		count+=merge(a,mid+1,r);
		
		while(i<=mid && j<=r)
		{
			if(a[i]<=a[j])
				temp[k++]=a[i++];
			else
			{
				temp[k++]=a[j++];
				count+=mid-i+1;
			}
		}
		while(i<=mid)
			temp[k++]=a[i++];
		while(j<=r)
			temp[k++]=a[j++];
		for(i=0;i<k;i++)
			a[l+i]=temp[i];
		return count;
	}
		return 0;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",merge(a,0,n-1));
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
