#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

const int maxn = 110;

queue<int> q;
vector<int> p[maxn];
int n,m,max_h=0,level[maxn]={0},leaf[maxn]={0};//n为节点数，m为非叶节点数 

void travel()
{
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int id=q.front();
		q.pop();
		max_h=max(max_h,level[id]);
		if(p[id].size()==0)leaf[level[id]]++;
		for(int u=0;u<p[id].size();u++)
		{
			level[p[id][u]]=level[id]+1;
			q.push(p[id][u]);
		}
	}
}


int main()
{
	level[1]=1;
	scanf("%d %d",&n,&m);
	int id,cd,cd_num;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&id,&cd_num);
		for(int j=0;j<cd_num;j++)
		{
			scanf("%d",&cd);
			p[id].push_back(cd);
		}
	} 
	travel();
	for(int i=1;i<=max_h;i++)
	{
		printf("%d",leaf[i]);
		if(i!=max_h)printf(" ");
	}
	return 0;
} 
