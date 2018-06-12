#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int min(int a, int b){
    return a<b ? a : b ;
}

int cmp(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int ans(int choco[], int n) {

    qsort(choco,n,sizeof(int),cmp);

    int sum = INT_MAX;

    int base,i;
    for(base = 0; base < 3; base++) 
	{
        int current_sum = 0;
        for(i = 0; i < n; i++) 
		{
            int delta = choco[i] - choco[0] + base;
            current_sum += (int)delta / 5 + delta % 5 / 2 + delta % 5 % 2 / 1;
        }
        sum = min(current_sum,sum);
    }

    return sum;
}

int main(){

    int n,i;
    scanf("%d",&n);

    int choco[n];
    for(i=0; i<n; i++){
        scanf("%d",&choco[i]);
    }

    printf("%d\n",ans(choco,n));

    return 0;
}
