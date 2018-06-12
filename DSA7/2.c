#include<stdio.h>

int p[10]={0},q[10]={0},curr=0,ans=0,size=0;

void swap(int *p, int *q)
{
	int a=*p;
	*p=*q;
	*q=a;
}

void sort(int n)
{
	int i,j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
			if(p[j]>p[j+1])
			{
				swap(p+j, p+j+1);
				swap(q+j, q+j+1);
			}
}

void min_heapify(int *a, int n, int m)
{
	int min;
	if(2*m<=n && q[a[2*m]]<q[a[m]])
		min=2*m;
	else
		min=m;
	if(2*m+1<=n && q[a[2*m+1]]<q[a[min]])
		min=2*m+1;
	if(min!=m)
	{
		swap(a+min,a+m);
		min_heapify(a,n,min);
	}
}

void insert(int *a, int val, int n)
{
	if(n==1)
	{
		if(p[val]>curr)
			curr=p[val];
	}

	a[n]=val;
	while(n>1 && q[a[n/2]]>q[a[n]])
	{
		swap(a+n/2,a+n);
		n=n/2;
	}
}

void get_top(int *a, int n)
{
	curr+=q[a[1]];
	ans+=curr-p[a[1]];
	a[1]=a[size];
	size--;
	min_heapify(a,size,1);
}

int main()
{
	int n,h[1000]={0};
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++)	
		scanf("%d %d",&p[i],&q[i]);
	sort(n);
	for(i=0; i<n; i++)
	{
		if(i==0)
		{
			insert(h,i,++size);
			continue;
		}
		while(size && curr<p[i])
			get_top(h,size);
		//printf("%d\n",ans );
		insert(h,i,++size);		
	}
	while(size)
		get_top(h,size);
	printf("%d\n",ans );
	return 0;
}
