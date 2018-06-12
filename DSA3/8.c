#include<stdio.h>
void merge(int a[],int l,int r)
{
	int mid=(l+r)/2;
	int i=l;
	int j=mid+1;
	int k=0;
	if(r>l)
	{
		int temp[r-l+1];
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
		{
			temp[k++]=a[i++];
		}
		while(j<=r)
		{
			temp[k++]=a[j++];
		}
		k=0;
		for(i=l;i<=r;i++)
		{
			a[i]=temp[k++];
		}
	}
}
int main()
{
	int n,i,j,m;
	scanf("%d %d",&m,&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
		b[i]=-1;
	for(i=m;i<n;i++)
	{
		int temp[m],k=0;
		for(j=i-m;j<i;j++)
			temp[k++]=a[j];
		merge(temp,0,k-1);
		if(m%2==1)
		{
			if(3*temp[m/2]>=a[i])
				b[i]=0;
			else
				b[i]=1;
		}
		else
		{
			int avg=(temp[m/2]+temp[(m/2)-1]);
			if(3*avg>=a[i])
				b[i]=0;
			else
				b[i]=1;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	printf("\n");
}
