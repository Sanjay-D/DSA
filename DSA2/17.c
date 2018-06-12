#include<stdio.h>
#include<stdlib.h>
int check(int **a, int n)
{
	int i,j,m=1000,pos;
	for(i=0;i<n;i++)
	{
		int s=0;
		for(j=0;j<n;j++)
		{
			s+=a[j][i];
		}
		if(s<m)
			m=s,pos=i;
	}
	if(m<0)
		return pos;
	else
		return -1;
}

int sum(int **a, int n)
{
	int s=0,i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			s+=a[i][j];
	return s;
}

int** modify(int **a, int n, int pos)
{
	int i,j;
	int **b=(int **)malloc((n-1)*sizeof(int*));
	for(i=0;i<n-1;i++)
		b[i]=(int*)malloc((n-1)*sizeof(int));
	int min=1000,pr;
	
	for(i=0;i<n;i++)
	{
		int s=0;
		for(j=0;j<n;j++)
		{
			if(j!=pos)
			{
				s+=a[i][j];
			}
		}
		if(s<min)
			min=s,pr=i;
	}

	int r=0;
	for(i=0;i<n;i++)
	{
		int c=0;
		if(i!=pr)
		{
			for(j=0;j<n;j++)
			{
				if(j!=pos)
				{
					b[r][c]=a[i][j];
					c++;
				}
			}
			r++;
		}
	}

	for(i=0;i<n;i++)
	{
		int *t=a[i];
		free(t);
	}
	
	return b;
}

int main()
{
	int N,i,j,pos;
	scanf("%d",&N);
	int **a=(int **)malloc(N*sizeof(int*));
	for(i=0;i<N;i++)
		a[i]=(int*)malloc(N*sizeof(int));		
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%d",&a[i][j]);
	int **t=a;
	while(1)
	{
		pos=check(t,N);
		if(pos==-1 || N==1)
			break;
		t= modify(a,N,pos);
		N--;
	}
	printf("%d \n",sum(t,N));
}
