#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 510;
const int INF = 1000000000;

int G[maxn][maxn];
int vis[maxn]={false};
int num[maxn],d[maxn],weight[maxn],w[maxn];
int n,m,st,ed;

void Dijkstra(int s)
{
	fill(d,d+maxn,INF);
	memset(w,0,sizeof(w));
	memset(num,0,sizeof(num));
	w[s]=weight[s];
	d[s]=0;
	num[s]=1;
	for(int i=0;i<n;i++)
	{
		int u=-1,min=INF;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j];
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
				w[v]=w[u]+weight[v];
				num[v]=num[u];
			}else if(d[u]+G[u][v]==d[v])
					{
					if(w[u]+weight[v]>w[v])
					{
						w[v]=w[u]+weight[v];
					}
					num[v]=num[v]+num[u];
					}
			}
		}
	}
}


int main()
{
	fill(G[0],G[0]+maxn*maxn,INF);
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	int u,v;
	for(int i=0;i<m;i++)
	{
	
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
	Dijkstra(st);
	printf("%d %d\n",num[ed],w[ed]);
	return 0;
} 
