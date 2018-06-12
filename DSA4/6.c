#include<stdio.h>
#include<string.h>

int main()
{
	int i,j;
	char c[100];
	scanf("%[^\n]",c);
	for(i=strlen(c)-1;i>=0;i--)
	{
		if(i==0 || c[i]==' ')
		{
			if(i==0)
				j=0;
			else
				j=i+1;
			for(;j<strlen(c) && c[j]!=' ';j++)
				printf("%c",c[j]);
			printf(" ");
		}
	}
}
