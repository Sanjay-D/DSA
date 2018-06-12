#include<stdio.h>
#include<string.h>
int isPal(char s[],int freq[], int f[][20])
{
	int i,l=strlen(s);
	for(i=0;i<l;i++)
	{
		int temp=s[i]-'a';
		f[temp][freq[temp]]=i;
		freq[temp]++;
	}
	int odd=0;
	for(i=0;i<26;i++)
	{
		if(freq[i]%2==1)
			odd++;
	}
	if((l%2==1 && odd==1) || (l%2==0 && odd==0))
		return 1;
	return 0;
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",s);
	int freq[26]={0};
	int f[26][20];
	for(i=0;i<26;i++)
		for(j=0;j<20;j++)
			f[i][j]=-1;
	if(isPal(s,freq,f)==0)
	{
		printf("-1\n");
		return 0;
	}
	
	/*for(i=0;i<26;i++,printf("\n"))
		for(j=0;j<20;j++)
			printf("%d ",f[i][j]);*/
			
	int half[n+1],index=0,oddi=-1;
	
	for(i=0;i<26;i++)
	{
		if(freq[i]>0)
		{
			if(freq[i]%2==1)
				oddi=i;
			for(j=0;j<freq[i]/2;j++)
			{
				half[index]=f[i][j];
				index++;
			}
		}
	}
	
	if(oddi!=-1)
		half[index++]=f[oddi][freq[oddi]/2];
	for(i=25;i>=0;i--)
	{
		if(freq[i]>0)
		{
			if(i==oddi)
			{
				for(j=1+freq[i]/2;j<freq[i];j++)
					half[index++]=f[i][j];
			}
			else
			{
				for(j=freq[i]/2;j<freq[i];j++)
					half[index++]=f[i][j];
			}
		}
	}
	for(i=0;i<index;i++)
		printf("%d ",half[i]+1);
	printf("\n");
}
