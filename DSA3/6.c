#include<stdio.h>

void merge(int a[],int l,int r)
{
	int mid=(l+r)/2;
	int i=l;
	int j=mid+1;
	int k=0;
	if(r>l)
	{
		int temp[r-l+1];
		merge(a,l,mid);
		merge(a,mid+1,r);
		while(i<=mid && j<=r)
		{
			if(a[i]<=a[j])
				temp[k++]=a[i++];
			else
				temp[k++]=a[j++];
		}
		while(i<=mid)
		{
			temp[k++]=a[i++];
		}
		while(j<=r)
		{
			temp[k++]=a[j++];
		}
		k=0;
		for(i=l;i<=r;i++)
		{
			a[i]=temp[k++];
		}
	}
}

int first(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high-low)/2;  /* (low + high)/2; */
        if ((mid == 0 || x > arr[mid-1]) && arr[mid] == x)
            return mid;
        if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        return first(arr, low, (mid -1), x, n);
    }
    return -1;
}
 
// Sort A1[0..m-1] according to the order defined by A2[0..n-1].
void sortAccording(int A1[], int A2[], int m, int n)
{
    // The temp array is used to store a copy of A1[] and visited[]
    // is used mark the visited elements in temp[].
    int temp[m], visited[m];
    int i;
    for (i=0; i<m; i++)
    {
        temp[i] = A1[i];
        visited[i] = 0;
    }
 
    // Sort elements in temp
    //sort(temp, temp + m);
 	merge(temp,0,m-1);
 
    int ind = 0;  // for index of output which is sorted A1[]
 
    // Consider all elements of A2[], find them in temp[]
    // and copy to A1[] in order.
    for (i=0; i<n; i++)
    {
        // Find index of the first occurrence of A2[i] in temp
        int f = first(temp, 0, m-1, A2[i], m);
 
        // If not present, no need to proceed
        if (f == -1) continue;
 		int j;
        // Copy all occurrences of A2[i] to A1[]
        for (j = f; (j<m && temp[j]==A2[i]); j++)
        {
            A1[ind++] = temp[j];
            visited[j] = 1;
        }
    }
 
    // Now copy all items of temp[] which are not present in A2[]
    for (i=0; i<m; i++)
        if (visited[i] == 0)
            A1[ind++] = temp[i];
}
 
// Utility function to print an array

 
// Driver program to test above function.
int main()
{
    int m,n,i;
    scanf("%d %d",&m,&n);
    int a[m],b[n];
    for(i=0;i<m;i++)
    	scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    	scanf("%d",&b[i]);
    	
    sortAccording(a, b, m, n);
   	for(i=0;i<m;i++)
   		printf("%d ",a[i]);
    return 0;
}
