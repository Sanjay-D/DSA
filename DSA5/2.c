#include<stdio.h>
#define MAX 1000000
#define lim 1000
typedef long long ll;
ll seive[1000010];
ll ans[1000010];
void precomp()
{
	int i,j;
    for(i=1;i<=MAX;i++)
        seive[i]=i;
    for(i=2;i<=MAX;i++)
        {
            if(seive[i]==i)
                for(j=2*i;j<=MAX;j+=i)
                    seive[j]-=seive[j]/i;
        }
    for(i=2;i<=MAX;i++)
        {
            if(seive[i]==i)
                seive[i]=i-1;
        }
	for(i=1;i<=MAX;i++)
	    {
	        for(j=i;j<=MAX;j+=i)
	            ans[j]+=i*seive[i];
	    }
}
int main()
{
    precomp();
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,sum;
       scanf("%lld",&n);
        sum=(1+ans[n])*n/2;
        printf("%lld\n",sum);
       // printf("A\n");
    }
} 
