#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;

const int maxn=10010;

int n;
vector<int> G[maxn];
int high[maxn];
bool vis[maxn]={false};
int level[maxn]={0};

int find_max()
{
	int max=-1;
	for(int i =1;i<=n;i++)
	{
		if(max<level[i])max=level[i];
	}
	return max;
}

void BSF(int st)
{
	queue<int> q;
	q.push(st);
	level[st]=1;
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		vis[temp]=true;
		for(int i=0;i<G[temp].size();i++)
		{
			if(vis[G[temp][i]]==false)
			{
				q.push(G[temp][i]);
				level[G[temp][i]]=level[temp]+1;
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int part=1;
	BSF(1);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			BSF(i);
			part++;
		}
	}
	if(part!=1)
	{
		printf("Error: %d components",part);
		return 0;
	}
	high[1]=find_max();
	for(int i=2;i<=n;i++)
	{
		memset(level,0,sizeof(level));
		memset(vis,false,sizeof(vis));
		BSF(i);	
		high[i]=find_max();
	}
	int max=-1;
	for(int i=1;i<=n;i++)
	{
		if(max<high[i])max=high[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(high[i]==max)printf("%d\n",i);
	}
	return 0;
} 
