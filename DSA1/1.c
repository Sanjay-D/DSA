#include<string.h>
#include<math.h>
#include<stdio.h>

int main()
{
	char a[101];
	scanf("%s",a);
	if(floor((double)sqrt(strlen(a)))==ceil((double)sqrt(strlen(a))))
	{
		int N=sqrt(strlen(a));
		char b[N][N];
		int i,j,k=0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				b[i][j]=a[k];
				k++;
			}
		}
		char t[101];
		k=0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				t[k]=b[j][i];
				k++;
			}
		}
		t[k]='\0';
		if(strcmp(a,t)!=0)
			printf("No\n");
		else
		{
				k=0;
			for(i=N-1;i>=0;i--)
			{
				for(j=N-1;j>=0;j--)
				{
					t[k]=b[i][j];
					k++;
				}
			}
			t[k]='\0';
			if(strcmp(a,t)!=0)
			printf("No\n");
			else
			{
				k=0;
				for(i=N-1;i>=0;i--)
				{
					for(j=N-1;j>=0;j--)
					{
					t[k]=b[j][i];
					k++;
					}
				}
				t[k]='\0';
				if(strcmp(a,t)!=0)
				printf("No\n");
				else
					printf("Yes\n");
			}
		}
	}
	else
		printf("No\n");
}
