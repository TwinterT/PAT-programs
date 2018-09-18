#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

const int maxn = 110;

int n,m;
vector<int> G[maxn];
int level[maxn],num[maxn]={0};
bool vis[maxn]={false};

void BSF(int st)
{
	vis[st]=true;
	level[st]=1;
	queue<int> q;
	q.push(st);
	while(!q.empty())
	{
		int topnode=q.front();
		q.pop();
		for(int i=0;i<G[topnode].size();i++)
		{
			if(vis[G[topnode][i]]==false)
			{
				level[G[topnode][i]]=level[topnode]+1;
				vis[G[topnode][i]]=true;
				q.push(G[topnode][i]);
			}
		}
	}
}

int main()
{
	int i,j,id,chd,temp;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&id,&chd);
		for(j=0;j<chd;j++)
		{
			scanf("%d",&temp);
			G[id].push_back(temp);
		}
	}
	BSF(1);
	int max=-1;
	for(i=1;i<=n;i++)
	{
		num[level[i]]++;
		if(level[i]>max)max=level[i];
	}
	int ans=-1,idx;
	for(i=1;i<=max;i++)
	{
		if(num[i]>ans)
		{
			ans=num[i];
			idx=i;
		}
	}
	printf("%d %d\n",ans,idx);
	return 0;
}