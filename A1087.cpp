#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=210;
const int INF=1000000000;

int n,k;
int weight[maxn];
int G[maxn][maxn];
int d[maxn],w[maxn],num[maxn],pt[maxn],pre[maxn];
bool vis[maxn]={false};
map<string,int> cityToindex;
map<int,string> indexTocity;

void dijkstra(int s)
{	int i;
	fill(d,d+n,INF);
	memset(w,0,sizeof(w));
	memset(num,0,sizeof(num));
	memset(pt,0,sizeof(pt));
	for(i=0;i<n;i++)
	{
		pre[i]=i;
	}
	d[s]=0;
	num[s]=1;
	w[s]=weight[s];
	for(i=0;i<n;i++)
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
					num[v]=num[s];
					w[v]=w[u]+weight[v];
					pt[v]=pt[u]+1;
					pre[v]=u;
				}
				else if(d[u]+G[u][v]==d[v])
				{
					num[v]+=num[u];
					if(w[u]+weight[v]>w[v])
					{
						w[v]=w[u]+weight[v];
						pt[v]=pt[u]+1;
						pre[v]=u;
					}else if(w[u]+weight[v]==w[v])
					{
						double uAvg=1.0*(w[u]+weight[v])/(pt[u]+1);
						double vAvg=1.0*w[v]/pt[v];
						if(uAvg>vAvg)
						{
							pt[v]=pt[u]+1;
							pre[v]=u;
						}
					}
				}
			}
		}
	}
}

void printPath(int v)
{
	if(v==0)
	{
		cout<<indexTocity[v];
		return;
	}
	printPath(pre[v]);
	cout<<"->"<<indexTocity[v];
}


int main()
{
	fill(G[0],G[0]+maxn*maxn,INF);
	string root,city1,city2;
	int i,j,temp;
	cin>>n>>k>>root;
	cityToindex[root]=0;
	indexTocity[0]=root;
	for(i=1;i<n;i++)
	{
		cin>>city1>>temp;
		cityToindex[city1]=i;
		indexTocity[i]=city1;
		weight[i]=temp;
	}
	for(i=0;i<k;i++)
	{
		cin>>city1>>city2>>temp;
		int u=cityToindex[city1],v=cityToindex[city2];
		G[u][v]=G[v][u]=temp;
	}
	dijkstra(0);
	int rom=cityToindex["ROM"];
	printf("%d %d %d %d\n",num[rom],d[rom],w[rom],w[rom]/pt[rom]);
	printPath(rom);
	return 0;
}