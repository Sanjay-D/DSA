#include<stdio.h>
#include<math.h>
#define ll unsigned long long 
ll int k[1001];
ll int s[1001];
ll int sopf(ll int n) 
{
	ll int res=0;
	if(n%2==0)
		res+=2;
	while(n%2==0)
		n/=2;
	if(n>1)
	{
		ll int i;
		for(i=3;i<=sqrt(n);i+=2)
		{
			if(n%i==0)
				res+=i;
			while(n%i==0)
				n/=i;
		}
	}
	if(n>2)
		res+=n;
	return res;
}
void pre()
{
	k[0]=0;
	k[1]=0;
	k[2]=1;
	s[0]=0;
	s[1]=0;
	s[2]=2;
	ll int i,j;
	for(i=3;i<=1000;i++)
	{
		ll int temp=0;
		for(j=1;j<=i-1;j++)
		{
			temp+=s[j]*k[i-j];
		}
		s[i]=sopf(i);
		k[i]=(temp+s[i])/i;
	}
}
int main()
{
	ll int n,i,j;
	pre();
	scanf("%lld",&n);
	printf("%lld\n",k[n]);
}
