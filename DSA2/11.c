#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (i = n-1; i > 0; i--)
    {
        if (a[i] < a[i-1])
        {
            int j = i-1;
            while (j>=0 && a[i] < a[j])
                j--;
            printf("Elements: %d and %d\n",a[i],a[j+1]);
            printf("Respective positions: %d and %d\n",i,j+1);
            break;
        }
    }
}
