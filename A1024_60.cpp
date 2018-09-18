#include<stdio.h>
#include<string.h>

typedef struct node
{
	int d[1000];
	int len;
	node()
	{
		memset(d,0,sizeof(d));
		len=0;
	}
}node;

char num[15];
int k;

node turn_node(char a[])
{
	node ans;
	ans.len=strlen(a);
	for(int i=0;i<ans.len;i++)
	{
		ans.d[ans.len-1-i]=a[i]-'0';
	}
	return ans;
} //·´Ïò 

bool judge(node a)
{
	for(int i=0;i<=a.len/2;i++)
	{
		if(a.d[i]!=a.d[a.len-i-1])return false;
	}
	return true;
}

node sum(node a,node b)
{
	int carry=0;
	node ans;
	for(int i=0;i<a.len||i<b.len;i++)
	{
		int temp=a.d[i]+b.d[i]+carry;
		ans.d[ans.len++]=temp%10;
		carry=temp/10;
	}
	if(carry!=0)
	{
		ans.d[ans.len++]=carry;
	}
	return ans;
}

node reverse(node a)
{
	node ans;
	for(int i=0;i<a.len;i++)
	{
		ans.d[i]=a.d[a.len-i-1];
	}
	return ans;
}

void print(node a)
{
	for(int i=a.len-1;i>=0;i--)
	{
		printf("%d",a.d[i]);
	}
	printf("\n");
}

int main()
{
	scanf("%s %d",num,&k);
	node s=turn_node(num);
	int step=0;
	while(!judge(s)&&step<k)
	{
		node temp=reverse(s);
		s=sum(s,temp);
		step++;
	}
	print(s);
	printf("%d\n",step);
	return 0;
} 
