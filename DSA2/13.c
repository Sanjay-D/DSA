#include<stdio.h>

int maxi(int a, int b)
{
	if(a>b)
		return a;
	else 
		return b;
}
int mini(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void differ(int a[],int b[],int c[],int p, int q, int r)
{
	int diff=100000;
	int ri=0,rj=0,rk=0;
	int i=0,j=0,k=0;
	while(i<p && j<q && k<r)
	{
		int max=maxi(a[i],maxi(b[j],c[k]));
		int min=mini(a[i],mini(b[j],c[k]));
		if(max-min<diff)
		{
			ri=i;
			rj=j;
			rk=k;
			diff=max-min;
		}
		if(diff==0)
			break;
		if(a[i]==min)
			i++;
		else if(b[j]==min)
			j++;
		else
			k++;
	}
	printf("%d of A, %d of B, %d of C",a[ri],b[rj],c[rk]);
}

int main()
{
	int p,q,r,i;
	scanf("%d %d %d",&p,&q,&r);
	int a[p],b[q],c[r];
	for(i=0;i<p;i++)
		scanf("%d",&a[i]);
	for(i=0;i<q;i++)
		scanf("%d",&b[i]);
	for(i=0;i<r;i++)
		scanf("%d",&c[i]);
	differ(a,b,c,p,q,r);
}
