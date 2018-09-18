#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>

using namespace std;

const int maxn=10010;

vector<int> G[maxn];
bool vis[maxn]={false};
int n,m,k;

bool judge()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			if(vis[i]==true)break;
			else
			{
				if(vis[G[i][j]]==false)return false;
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		memset(vis,false,sizeof(vis));
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++)
		{
			int v;
			scanf("%d",&v);
			vis[v]=true;
		}
		if(judge()==true)printf("Yes\n");
		else printf("No\n");
	}
	system("pause");
	return 0;
}