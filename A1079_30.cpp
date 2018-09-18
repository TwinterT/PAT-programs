#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;

const int maxn = 100010;

int n;
double p,r;
double total;
bool vis[maxn]={false};
double price[maxn]={0};
int goods[maxn];
vector<int> G[maxn];

void BSF(int st)
{
	queue<int> q;
	price[st]=p;
	vis[st]=true;
	q.push(st);
	while(!q.empty())
	{
		int topnode=q.front();
		q.pop();
		for(int i=0;i<G[topnode].size();i++)
		{
			if(vis[G[topnode][i]]==false)
			{
				price[G[topnode][i]]=price[topnode]*(r+1);
				vis[G[topnode][i]]=true;
				q.push(G[topnode][i]);
			}
		}
	}
}


int main()
{
	memset(vis,false,sizeof(vis));
	fill(goods,goods+maxn,-1);
	int i,j,num,v;
	scanf("%d %lf %lf",&n,&p,&r);
	r=r/100;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		if(num==0)
		{
			scanf("%d",&goods[i]);
		}
		else
		{
			for(j=0;j<num;j++)
			{
				scanf("%d",&v);
				G[i].push_back(v);
			}
		}
	}
	BSF(0);
	for(i=0;i<n;i++)
	{
		if(goods[i]!=-1)
		{
		 total+=goods[i]*price[i];
		}
	}
	printf("%.1f",total);
	return 0;
}