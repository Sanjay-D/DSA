#include<stdio.h>
void calc(int n,int p,int c)
{
	int size=ceil((double)(log(n)/log(2)));
	if(floor((double)(log(n)/log(2)))==size)
		size++;

	int a[size],b[size];
	int t=n;
	int i;
	a[0]=c%p;
	if(size>1)
		a[1]=(c*c)%p;
	for(i=2;i<size;i++)
		a[i]=(a[i-1]*a[i-1])%p;

	i=0;
	while(t>0)
	{
		b[i]=t%2;
		i++;
		t/=2;	
	}
	
	int pr=1;
	for(i=0;i<size;i++)
	{
		if(b[i]==1)
		{
			pr*=a[i];
		}
	}
	printf("%d\n",pr%p);
	
}
int main()
{
	int n,c,p;
	scanf("%d %d %d",&c,&n,&p);
	calc(n,p,c);
}
