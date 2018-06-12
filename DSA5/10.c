#include<stdio.h>
 
#define endl "\n"
#define int long long

const int N=1e5+5;

int m, k;
int cache[100][100];

int nCr(int n, int r)
{
    if(r==0 || r==n)
        return 1;
    if(cache[n][r])
        return cache[n][r];
    cache[n][r] = nCr(n-1, r-1) + nCr(n-1, r);
    return cache[n][r];
}

int f(int x)
{
    int ans=0,i;
    int rem1s=k;
    for(i=60;i>=0;i--)
    {
        if(x&(1LL<<i))
        {
            int rempos=i;
            if(rempos<=0)
                continue;
            ans+=nCr(rempos, rem1s);
            rem1s--;
            if(rem1s<0)
                break;
        }
    }
    int ct=0;
    while(x>0)
    {
        ct+=x%2;
        x/=2;
    }
    if(ct==k)
        ans++;
    return ans;
}

int check(int x)
{
    int satisfy=f(2*x) - f(x);
    return (satisfy>=m);
}

int binsearch(int lo, int hi)
{
    while(lo<hi)
    {
        int mid=(lo+hi)>>1;
        if(check(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}

int main()
{
    scanf("%lld %lld",&m,&k);
    int ans=binsearch(1, 1e18);
    printf("%lld\n",ans);
    return 0;
}
