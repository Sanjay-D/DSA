#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char a[20][20];
	int size;
};

int isPal(char s[],int start,int end)
{
	while(start<end)
	{
		if(s[start]!=s[end])
			return 0;
		start++;
		end--;
	}
	return 1;
}

void find(struct node *min,char temp[][20],int start, int n,char str[],int index)
{
//	printf("I: %d\n",start);
	if(start>=n && index<(min->size))
	{
	//	printf("Yes\n");
		int k;
		for(k=0;k<index;k++)
		{
			strcpy(min->a[k],temp[k]);
		}
		min->size=index;
		return;
	}
	int i,j;
	
	for(i=start;i<n;i++)
	{
		if(isPal(str,start,i))
		{
			for(j=0;j<i-start+1;j++)
			{
				temp[index][j]=str[j+start];
			}
			temp[index][j]='\0';
			index++;
			find(min,temp,i+1,n,str,index);
			index--;
		}
	}
}

int main()
{
	int i,j;
	int n;
	char s[20];
	scanf("%s",s);
	n=strlen(s);
	
	struct node *min=(struct node *)malloc(sizeof(struct node));
	min->size=100;
	char a[20][20];
	
	find(min,a,0,n,s,0);
	
	printf("%d\n",min->size);
	for(i=0;i<min->size;i++)
	{
		printf("%s ",min->a[i]);
	}
	printf("\n");
}
