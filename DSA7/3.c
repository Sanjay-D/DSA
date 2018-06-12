#include<stdio.h>
struct mheap
{
	int size;
	int cap;
	int *h;
};

void heapy(struct mheap* heap,int i)
{
	int s=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<heap->size && heap->h[l] < heap->h[s])
		s=l;
	if(r<heap->size && heap->h[r] < heap->h[s])
		s=r;
	if(s!=i)
	{
		int t=heap->h[s];
		heap->h[s]=heap->h[i];
		heap->h[i]=t;
		heapy(heap,s);
	}
}

void ins(struct mheap *heap,int x)
{
	(heap->size)++;
	int i=heap->size -1;
	while (i && (x < heap->h[(i - 1)/2]))
    {
        heap->h[i] = heap->h[(i - 1)/2];
        i = (i - 1)/2;
    }
    heap->h[i] = x;
}
int ex(struct mheap* heap)
{
    int temp = heap->h[0];
    heap->h[0] = heap->h[heap->size - 1];
    --(heap->size);
    heapy(heap, 0);
    return temp;
}
struct mheap* cbheap(int a[],int n)
{
	struct mheap* heap = (struct mheap*)malloc(sizeof(struct mheap));
    heap->size = 0;  // current size is 0
    heap->cap = n;
    heap->h = (int *)malloc(n*sizeof(int));
    
    int i;
    for(i=0;i<n;i++)
    	heap->h[i]=a[i];
    heap->size=n;
    n=heap->size-1;
    for(i=(n-1)/2;i>=0;i--)
    	heapy(heap,i);
    return heap;
}
int main()
{
	int i,j,n,k;
	scanf("%d %d",&n,&k);
	int a[n][k];
	for(i=0;i<n;i++)
		for(j=0;j<k;j++)
			scanf("%d",&a[i][j]);
	//printf("a\n");
	int p[n],t[n];
	for(i=0;i<n;i++)
		p[i]=0,t[i]=a[i][0];
	//printf("b\n");
	struct mheap *heap=(t,n);
	
	
	printf("\n");
}
