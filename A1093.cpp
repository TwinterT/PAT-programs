#include<stdio.h>
#include<string.h>

const int maxn = 100;

int main()
{
	char str[maxn];
	gets(str);
	int leftnumP[maxn]={0};
	int len = strlen(str);
	for(int i = 0; i <len ;i++)
	{
		if(i>0)leftnumP[i]=leftnumP[i-1];
		if(str[i]=='P')leftnumP[i]++; 
	}
	int ans=0,rightnumT=0;
	for(int i=len-1;i>=0;i--)
	{
		if(str[i]=='T')rightnumT++;
		else if(str[i]=='A')
		{
			ans=ans+leftnumP[i]*rightnumT;
		}
	} 
	printf("%d",ans);
	return 0;
} 
