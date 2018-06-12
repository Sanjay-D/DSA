#include<stdio.h>

int nine(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]!=9)
			return 0;
	return 1;
}

void palindrome(int a[],int n)
{
	if(nine(a,n))
	{
		int i;
		printf("1");
		for(i=0;i<n-1;i++)
			printf("0");
		printf("1\n");
	}
	else
	{
		int i,j,mid=n/2,flag=0;
		i=mid-1;
		if(n%2==0)
			j=mid;
		else
			j=mid+1;
		while(i>=0 && a[i]==a[j])
			i--,j++;
		if(i<0 || a[i]<a[j])
			flag=1;
		while(i>=0)
		{
			a[j]=a[i];
			i--,j++;	
		}	
		if(flag)
		{
			int carry=1;
			i=mid-1;
			if(n%2==1)
			{
				a[mid]+=carry;
				carry=a[mid]/10;
				a[mid]%=10;
				j=mid+1;
			}
			else
				j=mid;
				
			while(i>=0)
			{
				a[i]+=carry;
				carry=a[i]/10;
				a[i]%=10;
				a[j++]=a[i--];
			}
		}
		for(i=0;i<n;i++)
			printf("%d",a[i]);
	}
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int c=0,t=n;
	while(t)
	{
		c++;
		t/=10;	
	}	
	int a[c];
	for(i=c-1;i>=0;i--)
	{
		a[i]=n%10;
		n/=10;
	}
	palindrome(a,c);
	printf("\n");
}
