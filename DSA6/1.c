#include<stdio.h>
int stack[10000000];
int top=-1;
int max_area(int a[],int n)
{
	int max=0;
	int i=0;
	while(i<n)
	{
		if(top==-1 || a[stack[top]]<=a[i])
			stack[++top]=i++;
		else
		{
			int t=stack[top--];
			int ans=a[t]*((top==-1)?i:i-stack[top]-1);
			if(max<ans)
				max=ans;
		}
	}
	while(top!=-1)
	{
		int t=stack[top--];
		int ans=a[t]*((top==-1)?i:i-stack[top]-1);
		if(max<ans)
			max=ans;
	}
	return max;
}

int main()
{
	int i,n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",max_area(a,n));
}
