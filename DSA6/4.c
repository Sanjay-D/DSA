#include<stdio.h>
#include<string.h>
int top=-1,top1=-1,curr=-1;
int stack[100],post[100]={0};
float stack1[100];
int p=0;

int type(char c)
{
	if(c=='+')
		return -1;
	if(c=='-')
		return -2;
	if(c=='*')
		return -3;
	if(c=='/')
		return -4;
	if(c=='(')
		return -5;
}

void push(char element,int f)            //Function to push elements into stack
{
	if(f<0)
		stack[++top]=f;
	else
		post[curr]=post[curr]*10+(element-48);
}

void pop()                              //Function to pop elements from stack and into postfix array
{	
	if(stack[top]!=-5)	
		post[++curr]=stack[top--];
	else
		top--;
}

int prec(int a)						//Function to return the precedence of operators
{
	if(a==-4) return 3;
	if(a==-3) return 3;
	if(a==-1) return 1;
	if(a==-2) return 1;
	if(a==-5) return 0;
} 

void postfix(char s[],int len)			//Evaluates postfix expression
{
	int i;
	for(i=0;i<=len;i++)
	{
		if(i==len)						//If end of infix expression is reached keep popping elements from the stack till it's empty
		{
			while(top!=-1)
				pop();
		}
		else if(s[i]=='/' || s[i]=='+' || s[i]=='*' || s[i]=='-') 
		{
			p=0;
			while(top>=0 && prec(type(s[i]))<=prec(stack[top]))   //If operator and precedence is lower than the top element in stack pop them
				{
					pop();
				}
			push(s[i],type(s[i]));
		}
		else if(s[i]=='(')         		//Push if '('
		{
			p=0;
			push(s[i],type(s[i]));
		}
		else if(s[i]==')')              //Pop till '(' is obtained
		{
			p=0;
			while((stack[top])!=-5)
			{
				pop();
			}
			pop();                       //Pop '(' and do not push to postfix array
		}
		else						     //If it's an atom push to postfix array
		{
			if(p==0)
				curr++;
			push(s[i],0);
			p=1;
		}
	}
}

float eval()
{
	int i;
	float ans=0;
	for(i=0;i<=curr;i++)
	{
		if(post[i]<0)
		{
			float t1=(stack1[top1--]);
			float t2=stack1[top1--];
			if(post[i]==-1)
				ans=t2+t1;
			else if(post[i]==-2)
				ans=t2-t1;
			else if(post[i]==-3)
				ans=t2*t1;
			else if(post[i]==-4)
				ans=t2/t1;
			stack1[++top1]=ans;
		}
		else
		{
			stack1[++top1]=post[i];
		}
	}
	ans=stack1[top1--];
	return ans;
}

int main()
{
	char infix[100];
	int i;
	printf("Enter infix expression \n");
	scanf("%s",infix);
	postfix(infix,strlen(infix));
	printf("Postfix expression : ");
	for(i=0;i<=curr;i++)
	{
		if(post[i]>=0)
			printf("%d ",post[i]);
		else if(post[i]==-1)
			printf("%c ",'+');
		else if(post[i]==-2)
			printf("%c ",'-');
		else if(post[i]==-3)
			printf("%c ",'*');
		else if(post[i]==-4)
			printf("%c ",'/');
	}
	printf("\n");
	printf("Evaluates to:\n");
	printf("%f\n",eval());
}
