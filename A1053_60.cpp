#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 105;

vector<int> t[maxn];
int weight[maxn],pre[maxn];
int n,m,s;

bool cmp(int a,int b)
{
	return weight[a]>weight[b];
}

void print_path(int v)
{
	if(v==0)
	{
		printf("%d",weight[v]);
		return;
	}
	print_path(pre[v]);
	printf(" %d",weight[v]);
}

void DFS(int v,int ans)
{
	ans+=weight[v];
	if(t[v].size()==0)
	{
		if(ans==s)
		{
			print_path(v);
			printf("\n");
		}	
		return;
	}
	for(int i=0;i<t[v].size();i++)
	{
		pre[t[v][i]]=v;
		DFS(t[v][i],ans);
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	for(int i=0;i<m;i++)
	{
		int id,num;
		scanf("%d %d",&id,&num);
		for(int j=0;j<num;j++)
		{
			int temp;
			scanf("%d",&temp);
			t[id].push_back(temp);
		}
	}
	for(int i=0;i<n;i++)
	{
		sort(t[i].begin(),t[i].end(),cmp);
	}
	DFS(0,0);
	return 0;
} 
