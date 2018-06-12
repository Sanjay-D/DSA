#include<bits/stdc++.h>
#define MAX 1000000
#define lim 1000
typedef long long ll;
using namespace std;
ll seive[1000010];
ll ans[1000010];
void precomp()
{
    for(int i=1;i<=MAX;i++)
        seive[i]=i;
    for(int i=2;i<=MAX;i++)
        {
            if(seive[i]==i)
                for(int j=2*i;j<=MAX;j+=i)
                    seive[j]-=seive[j]/i;
        }
    for(int i=2;i<=MAX;i++)
        {
            if(seive[i]==i)
                seive[i]=i-1;
        }
	for(int i=1;i<=MAX;i++)
	    {
	        for(int j=i;j<=MAX;j+=i)
	            ans[j]+=i*seive[i];
	    }
}
int main()
{
    precomp();
    ll t=1;
   // scanf("%lld",&t);
    while(t--)
    {
        ll n=5,sum;
       // scanf("%lld",&n);
        sum=(1+ans[n])*n/2;
        printf("%lld\n",sum);
    }
} 
