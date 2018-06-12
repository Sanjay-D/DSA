#include<stdio.h>

int main()
{
	char a[][6]={"","one","two","three","four","five","six","seven","eight","nine"};
	char b[][8]={"","","twenty","thirty","forty","fifty","sixty","seventy","eightty","ninety"};
	char c[][10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	int n;
	scanf("%d",&n);
	if(n==0)
	{
		printf("Zero\n");
		return 0;
	}
	int t=n/1000;
	if(t!=0)
		printf("%s thousand ",a[t]);
	n%=1000;
	t=n/100;
	if(t!=0)
		printf("%s hundred and ",a[t]);
	n%=100;
	t=n/10;
	if(t!=0 && t!=1)
	{
		printf("%s ",b[t]);
		n%=10;
		printf("%s \n",a[n]);
	}
	else if(t==1)
	{
		n%=10;
		printf("%s \n",c[n]);
	}
	else if(t==0)
	{
		n%=10;
		printf("%s \n",a[n]);
	}
	
}
