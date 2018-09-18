#include<stdio.h> 
#include<algorithm>

using namespace std;

const int maxn=510;
const int INF=1000000000;

//n城市数  m道路数  s起点 d终点 
//G为图   cost为花费  path为路径   c为实时花费  d为路长度 
//vis判断是否访问  
int n,m,st,de;
int G[maxn][maxn],cost[maxn][maxn],path[maxn],c[maxn],d[maxn];
bool vis[maxn]={false}; 

void Dijkstra(int st)
{
	d[st]=0;
	c[st]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1,min=INF;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				min=d[j];
				u=j;
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cost[u][v];
					path[v]=u;
				}
				else if((d[u]+G[u][v]==d[v])&&(c[u]+cost[u][v]<c[v]))
				{
					c[v]=c[u]+cost[u][v];
					path[v]=u;
				}
			}
		}
	}
}

void DFS(int v)
{
	if(v==st)
	{
		printf("%d ",v);
		return;
	}
	DFS(path[v]);
	printf("%d ",v);
} 

int main()
{
	scanf("%d %d %d %d",&n,&m,&st,&de);
	fill(cost[0],cost[0]+maxn*maxn,INF);
	fill(c,c+maxn,INF);
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(d,d+maxn,INF);
	for(int i=0;i<n;i++)
	{
		path[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		scanf("%d %d",&G[u][v],&cost[u][v]);
		G[v][u]=G[u][v];
		cost[v][u]=cost[u][v];
	}
	Dijkstra(st);
	DFS(de);
	printf("%d %d",d[de],c[de]);
	return 0;
} 
