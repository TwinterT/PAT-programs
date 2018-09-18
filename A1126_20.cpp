#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

const int maxn=510;

int n,m;
int degree[maxn]={0};
vector<int> G[maxn];
bool vis[maxn]={false};
int num=0;

void DFS(int v)
{
	if(vis[v]==true)
	{
		return;
	}
	num++;
	vis[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(vis[G[v][i]]==false)
				DFS(G[v][i]);
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		degree[u]++;
		degree[v]++;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int uneven=0;
	for(int i=1;i<=n;i++)
	{
		if(degree[i]%2!=0)uneven++;
		printf("%d",degree[i]);
		printf((i==n)?"\n":" ");
	}
	DFS(1);
	if(uneven==0&&num==n)printf("Eulerian\n");
	else if(uneven==2&&num==n)printf("Semi-Eulerian\n");
	else printf("Non-Eulerian\n");
	system("pause");
	return 0;
}