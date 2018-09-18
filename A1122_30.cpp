#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

const int maxn=210;

int n,m,k;
bool G[maxn][maxn]={false};
bool vis[maxn]={false};

bool judge(vector<int> &path)
{
	if(path.size()!=n+1||path.front()!=path.back())return false;
	else 
	{
		memset(vis,false,sizeof(vis));
		for(int j=1;j<path.size();j++)
		{
			if(vis[path[j]]==true||G[path[j-1]][path[j]]==false)
			{
				return false;
			}
			vis[path[j]]=true;
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
		G[u][v]=G[v][u]=true;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int num,tempNode;
		scanf("%d",&num);
		vector<int> path;
		for(int j=0;j<num;j++)
		{
			scanf("%d",&tempNode);
			path.push_back(tempNode);
		}
		printf(judge(path)?"YES\n":"NO\n");
	}
}