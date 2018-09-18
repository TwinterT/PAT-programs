#include<stdio.h>

int k,order[54],start[54],end[54];
char mp[5]={'S','H','C','D','J'};

void print()
{
	for(int i=0;i<54;i++)
	{
		int temp=end[i]/13;
		printf("%c%d",mp[temp],end[i]%13+1);
		if(i!=53)printf(" ");
	} 
	
}

int main()
{
	scanf("%d",&k);
	for(int i=0;i<54;i++)
	{
		int temp;
		scanf("%d",&temp); 
		order[i]=temp-1;
	}
	for(int i=0;i<54;i++)
	{
		start[i]=i;
		end[i]=i;
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<54;j++)
		{
			end[order[j]]=start[j];
		}
		for(int v=0;v<54;v++)
		{
			start[v]=end[v];
		}
	}
	print();
	return 0;
} 
