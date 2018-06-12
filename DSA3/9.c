#include<stdio.h>
#include<string.h>

void merge(char a[][30],int l,int r)
{
	int mid=(l+r)/2;
	int i=l;
	int j=mid+1;
	int k=0;
	if(r>l)
	{
		char temp[r-l+1][30];
		merge(a,l,mid);
		merge(a,mid+1,r);
		while(i<=mid && j<=r)
		{
			if(strlen(a[i])<strlen(a[j]))
				strcpy(temp[k++],a[i++]);
			else if(strlen(a[i])>strlen(a[j]))
				strcpy(temp[k++],a[j++]);
			else
			{
				if(strcmp(a[i],a[j])<=0)
					strcpy(temp[k++],a[i++]);
				else
					strcpy(temp[k++],a[j++]);
			}
		}
		while(i<=mid)
		{
			strcpy(temp[k++],a[i++]);
		}
		while(j<=r)
		{
			strcpy(temp[k++],a[j++]);
		}
		k=0;
		for(i=l;i<=r;i++)
		{
			strcpy(a[i],temp[k++]);
		}
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	char a[n][30];
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
	merge(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%s\n",a[i]);
}
