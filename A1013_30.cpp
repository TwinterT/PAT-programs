#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

const int maxn = 1010;

int n,m,k;
vector<int> G[maxn];
bool vis[maxn]={false};

void dsf(int d,int st)
{
	if(st==d)return;
	vis[st]=true;
	for(int i=0;i<G[st].size();i++)
	{
		if(vis[G[st][i]]==false)dsf(d,G[st][i]);
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	for(int i=0;i<k;i++)
	{
		int d;
		scanf("%d",&d);
		memset(vis,false,sizeof(vis));
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==false&&j!=d)
			{
				dsf(d,j);
				ans++;
			}
		}
		printf("%d\n",ans-1);
	}
	return 0;
} 
