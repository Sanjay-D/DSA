#include<stdio.h>

void merge(int a[],int b[],int l,int r)
{
	int mid=(l+r)/2;
	int i=l;
	int j=mid+1;
	int k=0;
	if(r>l)
	{
		int temp[r-l+1];
		int temp1[r-l+1];
		merge(a,b,l,mid);
		merge(a,b,mid+1,r);
		while(i<=mid && j<=r)
		{
			if(a[i]<a[j])
				temp[k]=a[i],temp1[k++]=b[i++];
			else if(a[j]<a[i])
				temp[k]=a[j],temp1[k++]=b[j++];
			else
			{
				if(b[i]<=b[j])
					temp[k]=a[i],temp1[k++]=b[i++];
				else
					temp[k]=a[j],temp1[k++]=b[j++];
					
			}
		}
		while(i<=mid)
		{
			temp[k]=a[i];
			temp1[k++]=b[i++];
			
		}
		while(j<=r)
		{
			temp[k]=a[j];
			temp1[k++]=b[j++];
			
		}
		k=0;
		for(i=l;i<=r;i++)
		{
			a[i]=temp[k];
			b[i]=temp1[k++];
		}
	}
}

int split(int a[],int b[],int l[],int u[],int count[],int N,int k,int size)
{
	int i,j;
	while(N<size)
	{
	merge(a,b,N,size-1);

	for(i=N;a[i]==a[i+1] && i<size-1;i++);
	i++;
	int small;
	if(i<size)
		small=a[i];
	else
		small=1000000000;

	int f=0;
	for(j=N;j<i;j++)
	{
		if(small>b[j])
		{
			f=1;
			small=b[j];	
		}
	}

	if(f)
	{
		l[k]=a[N];
		u[k]=small;
		count[k]=i-N;
	}
	else
	{
		l[k]=a[N];
		u[k]=small-1;
		count[k]=i-N;
	}	
	for(j=N;j<i;j++)
	{
		if(u[k]+1>b[j])
			N++;
		else
			a[j]=u[k]+1;
	}
	k++;
	}
	return k;
}

int main()
{
	int m,n,i;
	scanf("%d %d",&m,&n);
	int a[m], b[m];
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	
	
	int j,k=0,N=0;
	int l[2*m],u[2*m],count[2*m];
	for(i=0;i<15;i++)
		count[i]=0;

	k=split(a,b,l,u,count,N,k,m);

	int cl[k],cu[k]; 
	cl[0]=0;
	cu[0]=(u[0]-l[0]+1)*count[0];
	for(i=1;i<k;i++)
	{
		cl[i]=cu[i-1];
		cu[i]=(u[i]-l[i]+1)*count[i]+cl[i];
	}
	for(i=0;i<k && cu[i]<=n;i++);
	int answer=l[i]+(n-cl[i])/count[i];
	printf("%d \n",answer);	
}
