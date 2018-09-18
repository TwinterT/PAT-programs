#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long LL;

int n;

bool judge(char data[])
{
	int len=strlen(data);
	LL a=0,b=0,pre=0;
	int i=0;
	for(;i<len/2;i++)
	{
		a=a*10+(data[i]-'0');
		pre=pre*10+(data[i]-'0');
	}
	for(;i<len;i++)
	{
		b=b*10+(data[i]-'0');
		pre=pre*10+(data[i]-'0');
	}
	if(a==0||b==0)return false;
	if(pre%(a*b)==0)return true;
	else return false;
}


int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char data[20];
		scanf("%s",data);
		if(judge(data)==true)printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}