#include<stdio.h>
#include<math.h>
int c=0,top=0;
void factor(int a[],int n)
{
	int i=2;
	int t=n;
	while(n%i==0)
	{
		a[top]++;
		n/=i;
	}
	if(a[top]!=0)
		top++;
	for(i=3;i<=sqrt(n);i+=2)
	{
		while(n%i==0)
		{
			a[top]++;
			n/=i;
		}
		if(a[top]!=0)
			top++;
	}
	if(n>2)
	{
		a[top]++;
		top++;
	}
}

void calc(int a[])
{
	while(a[0]!=0)
	{
		int t=a[0];
		int i;
		for(i=0;i<top && a[i]==t;i++)
		{
			int j,temp=1;
			for(j=0;j<top;j++)
			{
				temp*=a[j]+1;
			}
			c+=temp;
			a[i]--;
		}
	}
}

void merge(int a[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		int k=0,i=l,j=mid+1,t[r-l+1];
		merge(a,l,mid);
		merge(a,mid+1,r);
		while(i<=mid && j<=r)
		{
			if(a[i]>=a[j])
			{
				t[k++]=a[i++];
			}
			else
				t[k++]=a[j++];
		}
		while(i<=mid)
			t[k++]=a[i++];
		while(j<=r)
			t[k++]=a[j++];
		for(i=l;i<=r;i++)
		{
			a[i]=t[i-l];
		}
	}
}

int main()
{
	int k,n,u,v;
	scanf("%d %d",&u,&v);
	for(k=u;k<=v;k++)
	{
		int a[10000]={0};
		top=0;
		factor(a,k);
		//printf("Hell\n");
		int i;
		merge(a,0,top-1);
		/*for(i=0;i<top;i++)
			printf("%d ",a[i]);
		printf("\n");*/
		calc(a);
	}
	printf("%d\n",c);
}
