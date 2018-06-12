#include<stdio.h>

void merge(int a[],int b[],int l, int r)
{
	int temp[r-l+1],temp1[r-l+1],mid=(l+r)/2;
	int i=l,j=mid+1,k=0;
	
	if(l<r)
	{
		merge(a,b,l,mid);
		merge(a,b,mid+1,r);
		while(i<=mid && j<=r)
		{
			if(a[i]<=a[j])
				temp1[k]=b[i],temp[k++]=a[i++];
			else
				temp1[k]=b[j],temp[k++]=a[j++];
		}
		while(i<=mid)
			temp1[k]=b[i],temp[k++]=a[i++];
		while(j<=r)
			temp1[k]=b[j],temp[k++]=a[j++];
		for(i=0;i<k;i++)
			b[i+l]=temp1[i],a[i+l]=temp[i];
	}
}

int main()
{
	int n,i,c=1;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
		scanf("%d %d",&a[i],&b[i]);
	merge(a,b,0,n-1);
	for(i=0;i<n;i++)
	{
		if(c>=a[i] && c<=b[i])
			printf("%d ",c),c++;
		else
			printf("0 ");	
	}
	printf("\n");	
}
