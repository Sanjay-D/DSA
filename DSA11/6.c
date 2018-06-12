#include<stdio.h>
#include<string.h>
 
int max(int a, int b)
{
	return (a>b)?a:b;
}
void lcsOf3(char a[], char b[], char c[], int m,
                               int n, int o)
{
    int L[m+1][n+1][o+1];
 
    int i,j,k; 
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            for (k=0; k<=o; k++)
            {
                if (i == 0 || j == 0||k==0)
                    L[i][j][k] = 0;
 
                else if (a[i-1] == b[j-1] && a[i-1]==c[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
 
                else
                    L[i][j][k] = max(max(L[i-1][j][k], L[i][j-1][k]),L[i][j][k-1]);
            }
        }
    }
 
    int index=L[m][n][o];
    char t[index+1];
    t[index]='\0';
    i=m,j=n,k=o;
    while(i>0 && j>0 && k>0)
    {
    	if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
		{
			t[index-1]=a[i-1];
			i--;
			j--;
			k--;
			index--;
		}
		else if(L[i-1][j][k]>=L[i][j-1][k] && L[i-1][j][k]>=L[i][j][k-1])
			i--;
		else if(L[i][j-1][k]>=L[i-1][j][k] && L[i][j-1][k]>=L[i][j][k-1])
			j--;
		else
			k--;
	}
	printf("%d\n",L[m][n][o]);
	printf("%s\n",t);
}
 
int main()
{
    char a[] = "dabjcld";
    char b[] = "axbbmczcd";
    char c[] = "aqbuicdt";
 
    int m = strlen(a); 
    int n =strlen(b); 
    int o = strlen(c); 
 
    lcsOf3(a,b,c,m,n,o);
}
