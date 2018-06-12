#include<stdio.h>

int bubble(int a[],int n)
{
	int i,j,c=0;
	for(i=0;i<n-1;i++)
	{
		int f=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j+1]<a[j])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				c++;
				f=1;
			}
		}
		if(f==0)
			break;
	}
	return c;
}

int selection(int a[],int n)
{
	int i,j,c=0;
	for(i=0;i<n-1;i++)
	{
		int small=a[i];
		int pos=i;
		for(j=i+1;j<n;j++)
		{
			if(small>a[j])
				small=a[j],pos=j;
		}
		int temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
		if(pos!=i)
			c++;
	}
	return c;
}

int insertion(int a[],int n)
{
	int i,j,c=0;
	for(i=0;i<n;i++)
	{
		int temp=a[i];
		for(j=i-1;j>=0 && a[j]>temp;j--)
		{
			a[j+1]=a[j];
			c++;
		}
		a[j+1]=temp;
	}
	return c;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n],b[n],c[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
		c[i]=a[i];
	}
	int nob=bubble(b,n);
	int nos=selection(a,n);
	int noi=insertion(c,n);
	for(i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\n%d \n",noi);
}
