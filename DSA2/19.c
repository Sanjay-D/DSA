#include<stdio.h>
#include<math.h>
int main()
{
	int b[37];
	char a[37];
	int i;
	char c;
	int t,p=32;
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
	    i=0;
		int num=0;
		while(((scanf("%d",&t)==p) || p==32) && t!=10)
		{
			if(p==0 && t==0)
				printf("0");
			num+=t*pow(10,i);
			i++;
			p=t;
		}
		if(p==0 && t==0)
			continue;
		p=t;
		else if(t==32)
			continue;
		else if(t==10)
			break;
		
		for(i=0;i<37;i++)
		{
			if(b[i]==num)
			{
				printf("%c",a[i]);
				break;
			}
		}
	}
	printf("\n");	
}
