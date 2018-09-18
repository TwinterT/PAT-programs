#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn=26*26*26*10+10;

int n,k;
vector<int> data[maxn];

int get_id(char a[])
{
	int ans=0;
	for(int i=0;i<3;i++)
	{
		ans=ans*26+(a[i]-'A');
	}
	ans=ans*10+(a[3]-'0');
	return ans;
} 

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	scanf("%d %d",&n,&k);
	char temp[6];	
	for(int i=0;i<k;i++)
	{
		int number,m;
		scanf("%d %d",&number,&m);
		for(int j=0;j<m;j++)
		{
			scanf("%s",temp);
			int idx=get_id(temp);
			data[idx].push_back(number);
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",temp);
		printf("%s",temp);
		int idx=get_id(temp);
		printf(" %d",data[idx].size());
		sort(data[idx].begin(),data[idx].end(),cmp);
		for(int j=0;j<data[idx].size();j++)
		{
			printf(" %d",data[idx][j]);
		}
		printf("\n");
	}
	return 0;
} 




















//以下算法超时 
/*
#include<stdio.h>
#include<set>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int n,k;
map<string,set<int> > mp;

int main()
{
	int number;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&number);
		int m;
		string str;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			cin>>str;
			mp[str].insert(number);
		}
	}
	string temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		int len=mp[temp].size();
		cout<<temp;
		printf(" %d",len);
		for(set<int>::iterator it=mp[temp].begin();it!=mp[temp].end();it++)
		{
			printf(" %d",*it);
		}
		printf("\n");
	}
	return 0;
}
*/
