#include<stdio.h>
int main()
{
	char b[100],s[20],t[20];
	scanf("%[^\n]%*c",s);
	int i,c=0;
	scanf("%[^\n]%*c",b);
	for(i=0;i<strlen(b);i++)
	{
		int j=0;
		while(b[i]!=' ' && b[i]!='\0')
		{
			t[j]=b[i];
			i++;
			j++;
		}
		t[j]='\0';
		if(strcmp(t,s)==0)
			c++;
	}
	printf("%d\n",c);
}
