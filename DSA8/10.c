#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[100005]={0},level[10000]={0},gr[10000][100],ind[10000]={0},vis[10000]={0},x,y,c=20;
int q[100000]={0},front=0,back=0;

void enque(int r)
{
	q[back++]=r;
}

void deque()
{
	front++;
}

int top()
{
	return q[front];
}

int empty()
{
	if(front==back)
		return 1;
	else
		return 0;
}

void sieve()
{
	int i,j;
	for(i=0; i<=100000; i++)
		a[i]=1;
	for(i=2; i*i<100000; i++)
	{	
		if(a[i])
		{
			for(j=i*i; j<=100000; j+=i)
				a[j]=0;
		}
	}
}

int check_diff(int r, int s)
{
	int diff=0;
	while(r && s)
	{
		if(r%10 != s%10)
			diff++;
		r=r/10;
		s=s/10;
	}
	if(diff==1)
		return 1;
	else
		return 0;
}

void graph()
{
	int i,j;
	for(i=1000; i<=9999; i++)
	{
		if(!a[i])
			continue;
		for(j=1000; j<=9999; j++)
		{
			if(i==j)
				continue;
			else
				if(a[j] && check_diff(j,i))
					gr[i][ind[i]++]=j;
		}
	}
}

void bfs()
{
	while(!empty())
	{
		int p = top();
		deque();
		int i;
		for(i=0; i<ind[p]; i++)
		{
			if(!vis[gr[p][i]])
			{
				level[gr[p][i]]=level[p]+1;
				enque(gr[p][i]);
				vis[gr[p][i]]=1;
			}
		}
	}
}

int main()
{
	scanf("%d %d",&x,&y);
	sieve();
	graph();
	enque(x);
	level[x]=0;
	vis[x]=1;
	bfs();
	printf("%d\n",level[y] );
	return 0;
}
