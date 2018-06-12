#include<stdio.h>
#include<stdlib.h>
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
	int i,a[5]={4,2,3,7,10};
	int cost=0;
	struct mheap *heap=cbheap(a,5);
	while(heap->size!=1)
	{
		int a=ex(heap);
		int b=ex(heap);
		
		cost+=a+b;
		ins(heap,a+b);	
	}	
	printf("%d \n",cost);
}
