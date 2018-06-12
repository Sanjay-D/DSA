#include<stdio.h>

int main()
{
	int i,j,n;
	scanf("%d",&n);
	int a[n],c[n],b[2]={0};
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
			b[0]++;
		else
			b[1]++;
	}
	b[1]+=b[0];
	for(j=n-1;j>=0;j--)
	{
		c[b[a[j]%2]-1]=a[j];
		b[a[j]%2]--;
	}
	for(i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\n");
}
