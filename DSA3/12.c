#include<stdio.h>
#include<string.h>

int check(char s[],int start,int curr)
{
	int i;
	for(i=start;i<curr;i++)
		if(s[i]==s[curr])
			return 0;
	return 1;
}

void find(char s[],int index,int n)
{
	if(index>=n)
	{
		printf("%s\n",s);
		return;
	}
	int i;
	for(i=index;i<n;i++)
	{
		int c=check(s,index,i);
		if(c)
		{
			char t=s[i];
			s[i]=s[index];
			s[index]=t;
			
			find(s,index+1,n);
			
			t=s[i];
			s[i]=s[index];
			s[index]=t;
		}
	}
}

int main()
{
	char s[100];
	scanf("%s",s);
	find(s,0,strlen(s));
}
