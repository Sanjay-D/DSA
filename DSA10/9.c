#include<stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int maxi=0,count=0;
	for(i=0;i<n;i++)
	{
		if(a[maxi]==a[i])
		{
			count++;
			continue;
		}
		count--;
		if(count==0)
		{
			count=1;
			maxi=i;
		}
	}
	count=0;
	for(i=0;i<n;i++)
	{
		if(a[maxi]==a[i])
			count++;
	}
	if(count>n/2)
		printf("Majority element: %d\n",a[maxi]);
	else
		printf("No majority element\n");
}
