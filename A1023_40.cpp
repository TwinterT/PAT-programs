#include<stdio.h>
#include<string.h>

typedef struct node
{
	int n[22];
	int len;
	node()
	{
		memset(n,0,sizeof(n));
		len=0;		
	}
}node;

char num[22];
 
node turn_num(char num[])
{
	int len=strlen(num);
	node ans;
	for(int i=0;i<len;i++)
	{
		ans.n[i]=num[len-i-1]-'0';
	}
	ans.len=len;
	return ans;
}//低位在前高位在后 
 
node multi(node s,int a)
{
	node ans;
	int carry=0;
	for(int i=0;i<s.len;i++)
	{
		int temp=s.n[i]*a+carry;
		ans.n[ans.len++]=temp%10;
		carry=temp/10;
	}
	while(carry!=0)
	{
		ans.n[ans.len++]=carry%10;
		carry/=10;
	}
	return ans;
} 

bool judge(node a,node b)
{
	if(a.len!=b.len)return false;
	int temp[10]={0};
	for(int i=0;i<a.len;i++)
	{
		temp[a.n[i]]++;
		temp[b.n[i]]--;
	}
	for(int i=0;i<10;i++)
	{
		if(temp[i]!=0)return false;
	}
	return true;
}

void print(node a)
{
	for(int i=a.len-1;i>=0;i--)
	{
		printf("%d",a.n[i]);
	}
}

int main()
{
	scanf("%s",num);
	node s=turn_num(num);
	node mul=multi(s,2);
	if(judge(s,mul))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	
	}
	print(mul);
	return 0;
} 
