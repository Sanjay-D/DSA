#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	scanf("%[^\n]%*c",a);
	b[0]='\0';
	int i;
	int c[100]={0};
	for(i=0;i<strlen(a);i++)
	{
		int j,f=0;
		for(j=0;j<strlen(b);j++)
		{
			if(b[j]==a[i])
			{
				c[j]++;
				f=1;
				break;
			}
		}
		if(f==0)
		{
			int t=strlen(b);
			b[t]=a[i];
			b[t+1]='\0';
			c[t]++;
		}
	}
	for(i=0;i<strlen(b);i++)
	{
		printf("%c  %d\n",b[i],c[i]);
	}
}
