#include<stdio.h>

const int maxn = 54;
int k;
int start[maxn+1],end[maxn+1],next[maxn+1];
char mp[5]={'S','H','C','D','J'};

int main()
{	
	scanf("%d",&k);
	for(int i=1;i<=54;i++)
	{
		start[i]=i;
	}
	for(int i=1;i<=54;i++)
	{
		scanf("%d",&next[i]);
	}
	for(int i=1;i<k;i++)
	{
		for(int j=1;j<54;j++)
		{
			end[next[j]]=start[j];
		}
		for(int v=1;v<=54;v++)
		{
			start[v]=end[v];
		}
	}
	for(int i=1;i<=54;i++)
	{
		end[i]--;
		printf("%c%d",mp[end[i]/13],end[i]%13+1);
		if(i!=54)printf(" ");
	}
	return 0;
}
