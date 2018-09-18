#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn=100;

struct node
{
	int weight;
	vector<int> child;	
}node[maxn];

bool cmp(int a ,int b)
{
	return node[a].weight>node[b].weight;
}

int num,non_leaf,w;
int path[maxn];

void DSF(int index,int numNode,int sum)
{
	if(sum>w)return;
	if(sum==w)
	{
		if(node[index].child.size()!=0)return;
		for(int i=0;i<numNode;i++)
		{
			printf("%d",node[path[i]].weight);
			if(i==numNode-1)printf("\n");
			else printf(" ");
		}
		return;
	}
	for(int i=0;i<node[index].child.size();i++)
	{
		int child=node[index].child[i];
		path[numNode]=child;
		DSF(child,numNode+1,sum+node[child].weight);
	}
}

int main()
{
	scanf("%d %d %d",&num,&non_leaf,&w);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&node[i].weight);
	}
	for(int i=0;i<non_leaf;i++)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int j=0;j<k;j++)
		{
			int tempc;
			scanf("%d",&tempc);
			node[n].child.push_back(tempc);
		}
		sort(node[n].child.begin(),node[n].child.end(),cmp);
	}
	path[0]=0;
	DSF(0,1,node[0].weight);
	return 0;
} 
