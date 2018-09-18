#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;

typedef struct node
{
	int data;
	int layer;
}node;

const int maxn = 1010;
int n,L;
vector<node> G[maxn];
bool vis[maxn]={false};

int BSF(int start,int level)
{
	int num=0;
	queue<node> q;
	node s;
	s.data=start;
	s.layer=0;
	q.push(s);
	vis[start]=true;
	while(!q.empty())
	{
		node temp=q.front();
		q.pop();
		for(int i=0;i<G[temp.data].size();i++)
		{
			node next=G[temp.data][i];
			next.layer=temp.layer+1;
			if(vis[next.data]!=true&&next.layer<=L)
			{
				q.push(next);
				vis[next.data]=true;
				num++;
			}
		}
	}
	return num;
}

int main()
{
	scanf("%d %d",&n,&L);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			node mem;
			mem.data=i;
			int a;
			scanf("%d",&a);
			G[a].push_back(mem);
		}
	}
	int times;
	scanf("%d",&times);
	for(int i=0;i<times;i++)
	{
		memset(vis,false,sizeof(vis));
		int starts,num;
		scanf("%d",&starts);
		num=BSF(starts,L);
		printf("%d\n",num);		
	}
	return 0;
} 
