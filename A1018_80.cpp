#include<stdio.h>
#include<algorithm>
#include<vector>
 
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

int cmax,n,sp,m,weight[maxn],d[maxn],G[maxn][maxn],minNeed=INF,minRemain=INF;
bool vis[maxn]={false};
vector<int> pre[maxn];
vector<int> temppath,path;

void Dijkstra(int s)
{
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<=n;i++)
	{
		int u=-1,min=INF;
		for(int j=0;j<=n;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				min=d[j];
				u=j;
			}
		} 
		if(u==-1)return;
		vis[u]=true;
		for(int v=0;v<=n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v)
{
	if(v==0)
	{
		temppath.push_back(v);
		int need=0,remain=0;
		for(int i=temppath.size()-1;i>=0;i--)
		{
			int id=temppath[i];
			if(weight[id]>0)
			{
				remain+=weight[id];
			}
			else
			{
				if(remain>abs(weight[id]))
				{
					remain-=abs(weight[id]);
				}
				else
				{
					need+=abs(weight[id])-remain;
					remain=0;
				}
			}			
		}
		if(need<minNeed)
		{
			minNeed=need;
			minRemain=remain;
			path=temppath;
		}
		else if(need==minNeed&&remain<minRemain)
			{
				minRemain=remain;
				path=temppath;
			}
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for(int i=0;i<pre[v].size();i++)
	{
		DFS(pre[v][i]);
	}
	temppath.pop_back();
}

int main()
{
	scanf("%d %d %d %d",&cmax,&n,&sp,&m);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&weight[i]);
		weight[i]-=cmax/2;
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
	Dijkstra(0);
	DFS(sp);
	printf("%d ",minNeed);
	for(int i=path.size()-1;i>=0;i--)
	{
		printf("%d",path[i]);
		if(i!=0)printf("->");
	}
	printf(" %d",minRemain);
	return 0;
} 
