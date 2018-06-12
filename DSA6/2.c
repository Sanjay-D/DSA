#include<stdio.h>
#define ll long long
ll fac(ll a)
{
	if(a==0)
		return 1;
	int i;
	ll j=1;
	for(i=a;i>=2;i--)
		j*=a;
	return j;
}

int main()
{
	char a[100],b[100],c[100];
	int d[100];

	int i,j,n,l,r,k=-1;
	scanf("%s",a);
	scanf("%d %d",&l,&r);
	for(i=l-1;i<r;i++)
		b[i-l+1]=a[i];
	b[i-l+1]='\0';
	n=i-l+1;
	
	for(i=0;i<99;i++)
		d[i]=1;

	for(i=0;i<n;i++)
	{
		int f=-1;
		for(j=0;j<=k;j++)
		{
			if(b[i]==c[j])
			{
				f=j;
				break;
			}
		}
		if(f!=-1)
			d[f]++;
		else
		{
			c[++k]=b[i];
		}
	}
	
	ll f=0;
	int z=0;
	for(i=0;i<=k;i++)
	{
		if(d[i]%2==1)
			z++;
		d[i]/=2;
		f+=d[i];
	}
	if(z==0)
		z++;
	f=fac(f);
	for(i=0;i<=k;i++)
	{
		f/=fac(d[i]);
	}
	printf("%lld \n",f*z);
}
