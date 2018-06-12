#include<stdio.h>
#include<string.h>

int count(char a[])
{
	int n=strlen(a);
	int len,k,i,j,max=0;
	
	for(len=1;len<=n;len++)
	{
		for(i=0;i<=n-len;i++)
		{
			int x=0,c=0;
			char temp[101];
			int j=i+len-1;
			for(k=i;k<=j;k++)
				temp[x++]=a[k];
			temp[x]='\0';
			for(k=0;k<=n-x;k++)
			{
				int l;
				for(l=0;l<x;l++)
					if(a[k+l]!=temp[l])
						break;
				if(l==x)
					c++;
			}
			if(max<c*len)
				max=c*len;
		}
	}
	return max;
}

int main()
{
	char a[101];
	int i,j;
	scanf("%s",a);
	//for(i=0;i<99;i++)
	//	a[i]=(65+(i%26));
	printf("%d\n",count(a));
}
