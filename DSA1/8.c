#include<stdio.h>
#include<string.h>
int main()
{
	char g[]="goodbye";
	char s[100];
	scanf("%s",s);
	int i,c=0;
	for(i=0;i<strlen(s);i++)
	{
		if(c==7)
			break;
		else if(s[i]==g[c])
			c++;
	}
	if(c==7)
		printf("Yes\n");
	else 
		printf("No\n");
}
