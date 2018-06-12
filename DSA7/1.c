#include<stdio.h>

void swap(int *p, int *q)
{
	int a=*p;
	*p=*q;
	*q=a;
}

void min_heapify(int *a, int n, int m)
{
	int min;
	if(2*m<=n && a[2*m]<a[m])
		min=2*m;
	else
		min=m;
	if(2*m+1<=n && a[2*m+1]<a[min])
		min=2*m+1;
	if(min!=m)
	{
		swap(a+min,a+m);
		min_heapify(a,n,min);
	}
}

void insert_min(int *a, int val, int n)
{
	a[n]=val;
	while(n>1 && a[n/2]>a[n])
	{
		swap(a+n/2,a+n);
		n=n/2;
	}
}

void max_heapify(int *a, int n, int m)
{
	int max;
	if(2*m<=n && a[2*m]>a[m])
		max=2*m;
	else
		max=m;
	if(2*m+1<=n && a[2*m+1]>a[max])
		max=2*m+1;
	if(max!=m)
	{
		swap(a+max,a+m);
		max_heapify(a,n,max);
	}
}

void insert_max(int *a, int val, int n)
{
	a[n]=val;
	while(n>1 && a[n/2]<a[n])
	{
		swap(a+n/2,a+n);
		n=n/2;
	}
}

int main()
{
	int n,i,mah[100]={0},mih[100]={0};
	scanf("%d",&n);
	int p,q,r,t,sma=0,smi=0;
	for(i=1; i<=n; i++)
	{
		if(i==1)
		{
			scanf("%d",&p);
			printf("%d\n",p );
			continue;
		}
		if(i==2)
		{
			scanf("%d",&q);
			printf("%.1f\n",(p+q)/2.0 );
			continue;
		}
		if(i==3)
		{
			if(p<q)
				swap(&p,&q);
			insert_max(mah,q,++sma);
			insert_min(mih,p,++smi);
		}
		scanf("%d",&p);
		if(p<mah[1])
			insert_max(mah,p,++sma);			
		else
			insert_min(mih,p,++smi);

		while(sma-smi>1)
		{
			insert_min(mih,mah[1],++smi);
			mah[1]=mah[sma];
			sma--;
			max_heapify(mah,sma,1);				
		}
		while(smi-sma>1)
		{
			insert_max(mah,	mih[1],++sma);
			mih[1]=mih[smi];
			smi--;
			min_heapify(mih,smi,1);				
		}
		if(smi==sma)
			printf("%.1f\n",(mah[1]+mih[1])/2.0 );
		else if(smi>sma)
			printf("%d\n",mih[1] );
		else
			printf("%d\n",mah[1] );
	}
	return 0;
}
