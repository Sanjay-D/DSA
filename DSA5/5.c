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

int partition(int a[],int l,int r,int x)
{
	int i,j;
	for(i=l;i<r;i++)
		if(a[i]==x)
			break;
	int t=a[i];
	a[i]=a[r];
	a[r]=t;
	
	i=l;
	for(j=l;j<r;j++)
	{
		if(a[j]<=x)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;
		}
	}
	t=a[i];
	a[i]=a[r];
	a[r]=t;
	return i;
}

int kth(int a[],int l, int r,int k)
{
	if(k>0 && k<=r-l+1)
	{
		int n=r-l+1;
		int i,med[(n+4)/5];
		for(i=0;i<n/5;i++)
		{
			merge(a,l+i*5,l+i*5+4);
			med[i]=a[l+i*5+2];
		}
		if(i*5<n)
		{
			merge(a,l+i*5,l+i*5-1+n%5);
			med[i]=a[l+i*5+(n%5)/2];
			i++;
		}
		int mom=(i==1)?med[i-1]:kth(med,0,i-1,i/2);
		int pos=partition(a,l,r,mom);
		if(pos-l==k-1)
			return a[pos];
		if(pos-l>k-1)
			return kth(a,l,pos-1,k);
		return kth(a,pos+1,r,k-pos-1+l);
	}
}

int main()
{
	int i,n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(n%2==1)
	{
		printf("%d\n",kth(a,0,n-1,1+n/2));
	}
	else
	{
		int b=kth(a,0,n-1,n/2);
		int c=kth(a,0,n-1,1+n/2);
		printf("%f\n",((float)(c+b))/2);
	}
}
