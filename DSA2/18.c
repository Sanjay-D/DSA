#include<stdio.h>

int main()
{
	int b[37];
	char a[37];
	int i;
	char c;
	int t=-1;
	for(i=0;i<10;i++)
	{
		a[i]=(char)(i+48);
		if(i==0)
		{
			b[i]=0; 
		}
		else if(i==1)
		{
			b[i]=11;
		}
		else if(i==7 || i==9)
		{
			b[i]=11111*i;
		}
		else
			b[i]=1111*i;
	}
	a[10]=' ';
	b[10]=0;
	int count=2;
	for(i=11;i<37;)
	{
		a[i]=(char)(i+86);	
		b[i]=count;
		i++;
		a[i]=(char)(i+86);
		b[i]=count*11;
		i++;
		a[i]=(char)(i+86);
		b[i]=count*111;
		i++;
		a[i]=(char)(i+86);
		if(i==29 || i==36)
		{
			b[i]=count*1111;
			i++;
		}
		count++;
	}

	while(1)
	{
		scanf("%c",&c);
		if(c=='\n')
			break;
		if(t==-1)
		{
			if(c=='0')
				printf("00");
			for(i=1;i<37;i++)
			{
				if(c==a[i])
				{
					printf("%d",b[i]);
					t=b[i]%10;
					break;
				}
			}	
		}
		else
		{
			for(i=0;i<37;i++)
			{
				if(c==a[i])
				{
					if(b[i]%10==t)
						printf(" ");
					if(c=='0')
						printf("00");
					else
						printf("%d",b[i]);
					t=b[i]%10;
					break;
				}
			}
		}
	}	
}
