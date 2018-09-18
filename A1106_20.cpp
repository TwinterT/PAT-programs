#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>

using namespace std;

const int maxn = 100010;
const int INF = 1000000000;
int n;
double p,r;
double price[maxn];
vector<int> G[maxn];
bool retailer[maxn]={false};

void level(int root)
{
	queue<int> q;
	price[root]=p;
	q.push(root);
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(int i=0;i<G[top].size();i++)
		{
			price[G[top][i]]=price[top]*(1+r);
			q.push(G[top][i]);
		}
	}
}


int main()
{
	scanf("%d %lf %lf",&n,&p,&r);
	r/=100;
	int num,v;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		if(num==0)retailer[i]=true;
		else
		{
			for(int j=0;j<num;j++)
			{
				scanf("%d",&v);
				G[i].push_back(v);
			}
		}
	}
	level(0);
	double min=INF;
	for(int i=0;i<n;i++)
	{
		if(retailer[i]==true&&price[i]<min)
		{
			min=price[i];
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(retailer[i]==true&&price[i]==min)
			ans++;
	}
	printf("%.4f %d\n",min,ans);
	system("pause");
	return 0;
}