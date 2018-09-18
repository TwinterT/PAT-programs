#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stdlib.h>

using namespace std;

const int maxn=510;
const int INF=1000000000;

int n,m,start,des;
int G[maxn][maxn],ti_me[maxn][maxn],dis[maxn],t[maxn];
vector<int > pre_d[maxn],pre_t[maxn];
vector<int> tempPath,pathT,pathD;
int min_time=INF;
bool vis[maxn];


void dijkstra(int st,vector<int> pre[],int d[],int G[][maxn])
{
	memset(vis,false,sizeof(vis));
	fill(d,d+maxn,INF);
	d[st]=0;
	pre[st].push_back(st);
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
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[u]+G[u][v]==d[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}

void get_path_d()
{
	int temp_time=0;
	for(int i=tempPath.size()-1;i>=1;i--)
	{
		int u=tempPath[i];
		int v=tempPath[i-1];
		temp_time+=ti_me[u][v];
	}
	if(temp_time<min_time)
	{
		min_time=temp_time;
		pathD=tempPath;
	}
}

void get_path_t()
{
	if(pathT.size()==0||tempPath.size()<pathT.size())
	{
		pathT=tempPath;
	}
}

void DFS(int index,bool tag,vector<int> pre[])
{
	if(index==start)
	{
		tempPath.push_back(index);
		if(tag==true)get_path_d();
		else get_path_t();
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(index);
	for(int i=0;i<pre[index].size();i++)
	{
		DFS(pre[index][i],tag,pre);
	}
	tempPath.pop_back();
}

void print_path(vector<int> path)
{
	printf("%d",path.back());
	for(int i=path.size()-2;i>=0;i--)
	{
		printf(" -> %d",path[i]);
	}
	printf("\n");
}

int main()
{
	int u,v,one_way,length,cost_time;
	scanf("%d %d",&n,&m);
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(ti_me[0],ti_me[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d %d %d",&u,&v,&one_way,&length,&cost_time);
		G[u][v]=length;
		ti_me[u][v]=cost_time;
		if(one_way!=1)
		{
			G[v][u]=length;
			ti_me[v][u]=cost_time;
		}
	}
	scanf("%d %d",&start,&des);
	dijkstra(start,pre_d,dis,G);
	dijkstra(start,pre_t,t,ti_me);
	DFS(des,true,pre_d);
	DFS(des,false,pre_t);
	if(pathD==pathT)
	{
		printf("Distance = %d; Time = %d: ",dis[des],t[des]);
		print_path(pathD);
	}
	else
	{
		printf("Distance = %d: ",dis[des]);
		print_path(pathD);
		printf("Time = %d: ",t[des]);
		print_path(pathT);
	}
	return 0;
}