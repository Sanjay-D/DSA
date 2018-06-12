#include<stdio.h>
#include<stdlib.h>

struct point 
{
	int x,y;
}p0;

int dist(struct point a,struct point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int ori(struct point a, struct point b, struct point c)
{
	int val=(c.y-b.y)*(b.x-a.x)-(b.y-a.y)*(c.x-b.x);
	if(val==0)
		return 0;
	if(val>0)
		return 2;
	else
		return 1;
}

int comp(struct point a,struct point b)
{
	int val=ori(p0,a,b);
	if(val==2)
		return 0;
	if(val==1 || val==0 && dist(p0,a)>dist(p0,b))
		return 1;
	else
		return 0;
}

void merge(struct point p[],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		int i=l,j=mid+1,k=0;
		struct point q[r-l+1];
		
		merge(p,l,mid);
		merge(p,mid+1,r);
		
		while(i<=mid && j<=r)
		{
			if(comp(p[i],p[j])==0)
				q[k++]=p[i++];
			else
				q[k++]=p[j++];
		}
		while(i<=mid)
			q[k++]=p[i++];
		while(j<=r)
			q[k++]=p[j++];
		for(i=l;i<=r;i++)
		{
			p[i]=q[i-l];
		}
	}
}

int main()
{
	int i,n,j;
	scanf("%d",&n);
	struct point p[n];
	for(i=0;i<n;i++)
		scanf("%d %d",&p[i].x,&p[i].y);
	struct point min=p[0];
	int m=0;
	for(i=1;i<n;i++)
	{
		if(min.y>p[i].y || min.y==p[i].y && min.x>p[i].x)	
			min=p[i],m=i;
	}
	p[m]=p[0];
	p[0]=min;
	p0=p[0];
	
	merge(p,1,n-1);
/*	printf("\n");
	for(i=0;i<n;i++)
		printf("%d %d \n",p[i].x,p[i].y);
	printf("\n");*/
	m=1;
	for(i=1;i<n;i++)
	{
		while(i<n-1 && ori(p0,p[i],p[i+1])==0)
			i++;
		p[m++]=p[i];
	}
	
	if(m<3)
	{
		printf("Not Possible\n");
		return 0;
	}
	struct point stack[m];
	int t=2;
	stack[0]=p[0];
	stack[1]=p[1];
	stack[2]=p[2];
	
	for(i=3;i<m;i++)
	{
		while(ori(stack[t-1],stack[t],p[i])!=2)
			t--;
		stack[++t]=p[i];
	}
	
	printf("%d\n",t+1);
	while(t>=0)
	{
		printf("%d %d\n",stack[t].x,stack[t].y);
		t--;
	}
}
