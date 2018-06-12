#include<stdio.h>

int main()
{
	char s[1000];
    scanf("%[^\t]",s);
    int n=strlen(s);
    char r[n];
    int ml=0,sl=0;
    int i,j=0;
    for(i=0;i<n;i++)
    {
    	if(s[i]=='\n' && sl)
    		sl=0;
		else if(s[i]=='*' && s[i+1]=='/' && ml)
			ml=0,i++; 
		else if(ml || sl)
			continue;
		else if(s[i]=='/' && s[i+1]=='*')
		{
			ml++; 
			i++;
		}
		else if(s[i]=='/' && s[i+1]=='/')
		{
			sl++;
			i++;
		}
		else
		{
			r[j]=s[i];
			j++;
		}
	}
	r[j]='\0';
	printf("\n %s \n",r);
}
