#include<stdio.h>
void worst(int a[],int l,int r)
{
	int m=(l+r)/2;
	if(r>l)
	{
		int i,left[m-l+1],right[r-m];
		for(i=0;i<=m-l;i++)
			left[i]=a[i*2];
		for(i=0;i<r-m;i++)
			right[i]=a[i*2+1];
		worst(left,0,m-l);
		worst(right,0,r-m-1);
		
		for(i=0;i<=m-l;i++)
			a[i]=left[i];
		for(i=0;i<r-m;i++)
			a[i+m-l+1]=right[i];
	}
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	worst(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
