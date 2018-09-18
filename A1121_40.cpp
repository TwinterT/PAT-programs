#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn=100010;

int couple[maxn];
int guest[maxn];
int n,m;
vector<int> v[maxn],ans;

int main()
{
	memset(couple,-1,sizeof(couple));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		couple[u]=v;
		couple[v]=u;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&guest[i]);
		int temp=couple[guest[i]];
		if(temp!=-1)
		{
			v[temp].push_back(guest[i]);
			v[guest[i]].push_back(temp);
		}
	}
	for(int i=0;i<m;i++)
	{
		if(v[guest[i]].size()!=2)
		{
			ans.push_back(guest[i]);
		}
	}
	printf("%d\n",ans.size());
	sort(ans.begin(),ans.end());
	for(auto it=ans.begin();it!=ans.end();it++)
	{
		if(it==ans.begin())printf("%05d",*it);
		else printf(" %05d",*it);
	}
	return 0;
}