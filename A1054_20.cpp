#include<stdio.h>
#include<map>
#include<algorithm>

using namespace std;

map<int,int> mp;
int m,n;

bool cmp()
{
	
}

int main()
{
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++)
	{
		for(int i=0;i<m;i++)
		{
			int temp;
			scanf("%d",&temp);
			if(mp.find(temp)!=mp.end())mp[temp]++;
			else mp[temp]=1;
		}
	}
	int max=-1,key;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>max)
		{
			key=it->first;
			max=it->second;
		}
	}
	printf("%d",key);
	return 0;
}
