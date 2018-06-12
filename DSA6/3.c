#include<stdio.h>
int x[100],y[100],m[100];
int top=-1;

int path(int x1,int y1) // checks if the point(x1,y1) has already been visited
{
	int i;
	for(i=top;i>=0;i--)
	{
		if(x1==x[i] && y1==y[i])
			return 0;
	}
	return 1;
}

int main()
{
	int i,j=0,k,move=1,r=0,c=0,count=0;
	int maze[10][10]={{1,1,1,1,1,1,1,0,0,0},
		  			  {1,0,1,1,0,0,0,0,0,0},
		  			  {1,1,0,0,1,1,0,0,0,0},
		  			  {1,0,1,1,1,1,1,1,1,1},
		  			  {1,1,1,1,1,1,0,0,0,0},
		  			  {1,1,1,1,1,1,1,1,1,1},
		  			  {0,0,0,0,1,1,1,0,0,0},
		  			  {0,0,0,0,1,0,0,1,1,1},
		  			  {0,0,0,0,1,1,1,1,0,1},
		  			  {0,0,0,1,1,1,1,1,0,1}};
	/*for(i=0;i<10;i++)
	{
		for(i=0;i<10;i++)
			scanf("%d",maze[i][j]);
	}*/
	maze[0][0]++;
	while(1)
	{
		if(r==9 && c==9)
			break;
		if(move==1 && move++ && c+1<10 && maze[r][c+1]!=0 && path(r,c+1))
		{
		
			x[++top]=r;
			y[top]=c;
			m[top]=1;
			maze[r][c+1]++;
			c++;
			count++;
			move=1;
		//	printf("A(%d,%d)\n",r,c);
		}
		else if(move==2 && move++ && r+1<10 && maze[r+1][c]!=0 && path(r+1,c))
		{
			x[++top]=r;
			y[top]=c;
			m[top]=2;
			maze[r+1][c]++;
			r++;
			count++;
			move=1;
		//	printf("B(%d,%d)\n",r,c);
		}
		else if(move==3 && move++ && c-1>=0 && maze[r][c-1]!=0 && path(r,c-1))
		{
		
			x[++top]=r;
			y[top]=c;
			m[top]=3;
			maze[r][c-1]++;
			c--;
			count++;
			move=1;
		//	printf("C(%d,%d)\n",r,c);
			
		}
		else if(move==4 && r-1>=0 && maze[r-1][c]!=0 && path(r-1,c))
		{
			
			x[++top]=r;
			y[top]=c;
			m[top]=4;
			maze[r-1][c]++;
			r--;
			count++;
			move=1;
			//printf("D(%d,%d)\n",r,c);
		}
		else
		{
			while(top>=0 && m[top]==4)
			{
				top--;
				r++;
				count++;
				maze[r][c]++;
			//	printf("E(%d,%d)\n",r,c);
			}
			if(top==-1)
			{
				printf("Not possible\n");
				return 0;
			}
			move=m[top--];
			if(move==3)
			{
				move++;
				c++;
				count++;
				maze[r][c]++;
			//	printf("F(%d,%d)\n",r,c);
			}
			else if(move==2)
			{
				move++;
				r--;
				count++;
				maze[r][c]++;
				//printf("G(%d,%d)\n",r,c);
			}
			else if(move==1)
			{
				move++;
				c--;
				count++;
				maze[r][c]++;
			//	printf("H(%d,%d)\n",r,c);
			}
		}	
	}
	printf("Path:\n");
	for(i=0;i<=top;i++)
	{
		printf("(%d,%d)\n",x[i],y[i]);
	}
	printf("(9,9)\n");
	for(i=0;i<10;i++,printf("\n"))
		for(j=0;j<10;j++)
			printf("%d ",maze[i][j]);
	printf("Total moves: %d\n",count);			
}
