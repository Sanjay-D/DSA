#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,c=0;
	scanf("%d",&n);
	int t=n;
	while(t)
	{
		c++;
		t/=10;
	}
	int tot=0;
	tot+=3*(pow(3,c-1)-1)/2;
	while(n)
	{
		if(n/10==0)
		{
			if(n>=1 && n<7)
				tot++;
			else if(n>=7)
				tot+=2;
			break;
		}
		else
		{
		t=n/pow(10,c-1);
		if(t>1 && t<=7)
			tot+=pow(3,c-1);
		else if(t>7)
			tot+=2*pow(3,c-1);
		n%=(int)pow(10,c-1);
		c--;
		}
	}
	printf("%d \n",tot);
}
