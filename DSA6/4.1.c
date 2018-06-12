#include<stdio.h>
int post[100],stack[100];
float stack1[100];
int top=-1,curr=-1;
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

int prec(int a)
{
	if(a==-4 || a==-3)
		return 3;
	if(a==-2 || a==-1)
		return 2;
	if(a==-5)
		return 1;
}

void push(char element, int f)
{
	if(f<0)
		stack[++top]=f;
	else
		post[curr]=post[curr]*10+element-48;
}

void pop()
{
	if(stack[top]!=-5)
		post[++curr]=stack[top--];
	else
		top--;
}

void postfix(char s[],int len)
{
	int i;
	for(i=0;i<=len;i++)
	{
		if(i==len)
		{
			while(top!=-1)
				pop();
		}
		else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
		{
			p=0;
			while(top>=0 && prec(type(s[i]))<=prec(stack[top]))
				pop();
			push(s[i],type(s[i]));
		}
		else if(s[i]=='(')
		{
			p=0;
			push(s[i],type(s[i]));
		}
		else if(s[i]==')')
		{
			p=0;
			while(stack[top]!=-5)
				pop();
			pop();
		}
		else
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
	float ans=0;
	int i;
	for(i=0;i<=curr;i++)
	{
		if(post[i]<0)
		{
			float t1=stack1[top--];
			float t2=stack[top--];
			if(post[i]==-1)
				ans+=t2+t1;
			else if(post[i]==-2)
				ans+=t2-t1;
			else if(post[i]==-3)
				ans+=t2*t1;
			else if(post[i]==-4)
				ans+=t2/t1;
			stackl[++top]=post[i];				
		}
		else
			stack1[++top]=post[i];
	}
	
}

int main()
{
	
}
