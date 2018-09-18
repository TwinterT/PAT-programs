#include<stdio.h>
#include<string.h>

typedef struct node
{
	int p,t;
	node()
	{
		p=0;
		t=0;
	}
}node;

node num[100010];
char str[100010];

int main()
{
	int i,num_p=0,num_t=0,len,ans=0;
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]=='P')num_p++;
		if(str[i]=='A')
		{
			num[i].p=num_p;
		}
	}
	for(i=len-1;i>=0;i--)
	{
		if(str[i]=='T')num_t++;
		if(str[i]=='A')
		{
			num[i].t=num_t;
		}
	}
	for(i=1;i<len-1;i++)
	{
		if(str[i]=='A')
		{
			ans=(ans+num[i].p*num[i].t)%1000000007;
		}
	}
	printf("%d\n",ans);
	return 0;
}
