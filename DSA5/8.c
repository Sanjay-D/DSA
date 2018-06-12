#include<stdio.h>
#include<string.h>
int ones(char s[],int n)
{
	int i,sum=0,c=0;
	for(i=0;i<n;i++)
		sum+=s[i];
	while(sum)
	{
		c+=sum&1;
		sum>>=1;
	}
	return c;
}

void sort(char s[][15],int b[],int n)
{
	int c[15]={0};
	int i;
	for(i=0;i<n;i++)
		c[b[i]]++;
	for(i=1;i<15;i++)
		c[i]+=c[i-1];
	char s1[n][15];
	for(i=n-1;i>=0;i--)
	{
		strcpy(s1[c[b[i]]-1],s[i]);
		c[b[i]]--;
	}
	for(i=0;i<n;i++)
		printf("%s\n",s1[i]);
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	char s[n][15];
	for(i=0;i<n;i++)
		scanf("%s",s[i]);
	int b[n];
	for(i=0;i<n;i++)
		b[i]=ones(s[i],strlen(s[i]));
		printf("\n");
	sort(s,b,n);
}
