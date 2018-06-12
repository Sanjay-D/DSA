#include<stdio.h>

void merge(int a[],int l, int r)
{
	int mid=(l+r)/2;
	int i=l,j=mid+1,k=0,temp[r-l+1];
	if(r>l)
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
		for(i=0;i<r-l+1;i++)
		{
			a[l+i]=temp[i];
		}
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n],i,c=0;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(1)
	{
		merge(a,0,n-1);
		if(a[m-1]==0)
			break;
		c++;
		for(i=0;i<m;i++)
			a[i]--;	
	}
	printf("%d \n",c);
}
