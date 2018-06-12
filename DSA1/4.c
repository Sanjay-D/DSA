#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	scanf("%[^\n]c",a);
	int i;
	char b[100],t[100];
	for(i=0;i<strlen(a);i++)
	{
		int j=i;
		while(a[i]!=' ' && a[i]!='\0')
			i++;
		int c=i-1;
		for(;j<i;j++)
		{
			b[j]=a[c];
			c--;
		}
		b[j]=' ';
	}
	b[strlen(a)]='\0';
	for(i=0;i<strlen(b);i++)
	{
		if(b[i]!=' ')
			b[i]=(b[i]-93)%26+96;
	}
	printf("%s\n",b);
}
