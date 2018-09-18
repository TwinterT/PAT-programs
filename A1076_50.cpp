#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>

using namespace std;

const int maxn = 1010;

typedef struct node
{
	int data;
	int layer;
}node;

int n,l,k;
vector<node > G[maxn];
bool vis[maxn]={false};

int BSF(int st,int level)
{
	int ans=0;
	queue<node> q;
	node head;
	head.data=st;
	head.layer=0;
	q.push(head);
	vis[st]=true;
	while(!q.empty())
	{
		
		node temp=q.front();
		q.pop();
		int u=temp.data;
		for(int i=0;i<G[u].size();i++)
		{
			G[u][i].layer=temp.layer+1;
			if(vis[G[u][i].data]==false&&G[u][i].layer<=level)
			{
				q.push(G[u][i]);		
				vis[G[u][i].data]=true;
				ans++;
			}
		}
	}
	return ans;
}

int main()
{
	int i,j,num,query,ans=0;
	node temp;
	scanf("%d %d",&n,&l);
	for(i=1;i<=n;i++)
	{
		temp.data=i;
		scanf("%d",&num);
		for(j=0;j<num;j++)
		{
			int u;
			scanf("%d",&u);
			G[u].push_back(temp);
		}
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		ans=0;
		scanf("%d",&query);
		memset(vis,false,sizeof(vis));
		ans=BSF(query,l);
		printf("%d\n",ans);
	}
	return 0;
}