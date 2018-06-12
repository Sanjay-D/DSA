#include<stdio.h>

int arr[100001][31]={0};

int main(){

	int n,q,i,j,x,l,r,ans;
	int d=31;
	scanf("%d %d",&n,&q);

	for(i=1;i<=n;i++){
		scanf("%d",&x);
		for(j=0;j<d;j++){
			if(x&1)
				arr[i][j]=arr[i-1][j]+1;
			else 
				arr[i][j]=arr[i-1][j];
			x>>=1;
		}
	}

	while(q--){
		scanf("%d %d",&l,&r);
		ans=0;
		for(i=d-1;i>=0;i--){
			j=1<<i;
			x=arr[r][i]-arr[l-1][i];
			if(r-l+1-x > x)
				ans+=j;
		}
		printf("%d\n",ans);
	}

	return 0;
}
