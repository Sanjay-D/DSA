#include<stdio.h>

int main()
{
	int cb[8][8];
	int i,j,f=1,k;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			scanf("%d",&cb[i][j]);
	for(i=0;i<8;i++)
	{
		int h=0,v=0;
		for(j=0;j<8;j++)
		{
			
			if(cb[i][j]==1)
				h++;
			if(cb[j][i]==1)
				v++;
			if(h>1 || v>1)
			{
				f=0;
				break;
			}
		}
		if(f==0)
			break;
	}
	
	if(f)
	{
		for(i=0;i<7;i++)
		{
			int d1=0,d2=0;
			int t=i;
			for(j=0;j<8 && i<8;j++)
			{
				if(cb[i][j]==1)
					d1++;
				if(cb[j][i]==1)
					d2++;
				i++;
				if(d1>1 || d2>1)
				{
					f=0;
					break;
				}
			}
			i=t;
			if(f==0)
				break;
		}
		if(f)
		{
			for(k=1;k<=13;k++)
			{
				int d=0;
				for(i=0;i<8;i++)
				{
					for(j=0;j<8;j++)
					{
						if(i+j==k && cb[i][j]==1)
							d++;
						if(d>1)
						{
							f=0;
							break;
						}
							
					}
					if(f==0)
						break;
				}
				if(f==0)
					break;
			}
		}	
	}
	if(f)
		printf("YES\n");
	else
		printf("NO\n");
}
