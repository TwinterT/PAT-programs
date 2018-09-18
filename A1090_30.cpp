#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

const int N=100010;

int n;
double p,r;
int father[N];
double price[N];
vector<int> G[N];
bool vis[N]={false};

int build()
{	
	int root;
	for(int i=0;i<n;i++)
	{
		if(father[i]==-1)root=i;
		else G[father[i]].push_back(i);
	}
	return root;
}

void BSF(int st)
{
	memset(vis,false,sizeof(vis));
	fill(price,price+n,p);
	queue<int> q;
	q.push(st);
	vis[st]=true;
	while(!q.empty())
	{
		int topnode=q.front();
		q.pop();
		for(int i=0;i<G[topnode].size();i++)
		{
			if(vis[G[topnode][i]]==false)
			{
				price[G[topnode][i]]=price[topnode]*(1+r);
				vis[G[topnode][i]]=true;
				q.push(G[topnode][i]);
			}
		}
	}
}

int main()
{
	int i=0,root;
	scanf("%d %lf %lf",&n,&p,&r);
	r/=100;
	for(i=0;i<n;i++)
	{
		scanf("%d",&father[i]);
	}
	root=build();
	BSF(root);
	double max=-1;
	int num=0;
	for(i=0;i<n;i++)
	{
		if(max<price[i])max=price[i];
	}
	for(i=0;i<n;i++)
	{
		if(max==price[i])num++;
	}
	printf("%.2f %d",max,num);
	return 0;
}