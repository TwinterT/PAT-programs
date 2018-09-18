#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 10010;
const int INF = 1000000000;

int n,m,start,end;
int G[maxn][maxn],C[maxn][maxn];
int dis[maxn],cost[maxn];
bool vis[maxn]={false};
int path[maxn];

void Dijkstra(int s)
{
	for(int i=0;i<n;i++)path[i]=i;
	fill(dis,dis+maxn,INF);
	fill(cost,cost+maxn,INF);
	dis[s]=0;
	cost[s]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1,min=INF;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&dis[j]<min)
			{
				u=j;
				min=dis[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF)
			{
				if(dis[u]+G[u][v]<dis[v])
				{
					dis[v]=dis[u]+G[u][v];
					path[v]=u;
					cost[v]=cost[u]+C[u][v];
				}
				else if(dis[u]+G[u][v]==dis[v])
					{
						if(cost[u]+C[u][v]<cost[v])
						{
							path[v]=u;
							cost[v]=cost[u]+C[u][v];
						}
					}
			}
		}
	}
}

void DSF(int v)
{
	if(v==start)
	{
		printf("%d ",v);
		return;
	}
	DSF(path[v]);
	printf("%d ",v);
}

int main()
{
	fill(G[0],G[0]+maxn*maxn,INF);
	scanf("%d %d %d %d",&n,&m,&start,&end);
	for(int i=0;i<m;i++)
	{
		int s,e;
		scanf("%d %d",&s,&e);
		scanf("%d %d",&G[s][e],&C[s][e]);
		G[e][s]=G[s][e];
		C[e][s]=C[s][e];
	}
	Dijkstra(start);
	DSF(end);
	printf("%d %d\n",dis[end],cost[end]);
	return 0;
}
