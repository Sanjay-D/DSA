#include<stdio.h>

int merge(int a[],int l, int r,int c)
{
	int mid=(l+r)/2;
	int i=l,j=mid+1,k=0,temp[r-l+1];
	int t=c;
	if(r>l)
	{
		c+=merge(a,l,mid,t);
		c+=merge(a,mid+1,r,t);
		
		while(i<=mid && j<=r)
		{
			if(a[i]<=a[j])
				temp[k++]=a[i++];
			else
				temp[k++]=a[j++];
			c++;
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
	return c;
}

int main()
{
	int i,a[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int c=merge(a,0,15,0);
	for(i=0;i<16;i++)
		printf("%d ",a[i]);
	printf("\n");
	printf("%d \n",c);
}
