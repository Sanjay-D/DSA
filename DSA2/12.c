#include<stdio.h>
int bin(int a[], int N, int n)
{
	int i,j;
	i=first(a,0,N-1,n,N);
	if(i==-1)
		return 0;
	j=last(a,0,N-1,n,N);
	return j-i+1;
}
int first(int a[],int i, int j, int n,int N)
{
	if(j>=i)
	{
		int mid=(i+j)/2;
		if(a[mid]==n && (mid==0 || a[mid-1]<n))
			return mid;
		else if(a[mid]<n)
			return first(a,mid+1,j,n,N);
		else 
			return first(a,i,mid-1,n,N);
	}
	return -1;
}

int last(int a[],int i, int j, int n,int N)
{
	if(j>=i)
	{
		int mid=(i+j)/2;
		if(a[mid]==n && (mid==N-1 || a[mid+1]>n))
			return mid;
		else if(a[mid]>n)
			return last(a,i,mid-1,n,N);
		else 
			return last(a,mid+1,j,n,N);
	}
	return -1;
}

int main()
{
	int N,n,i;
	scanf("%d %d",&N,&n);
	int a[N];
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);

	printf("%d \n",bin(a,N,n));
}
