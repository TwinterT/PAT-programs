#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<string.h>

using namespace std;

const int maxn=310;
const int maxv=10010;

typedef struct node
{
	int x,y;
}node;

int n,m,k;
node ans[maxv];
map<int,map<int,bool> > mp;
vector<int> same[maxv];

bool cmp(node a,node b)
{
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		char x[6],y[6];
		scanf("%s %s",x,y);
		int u=abs(atoi(x));
		int v=abs(atoi(y));
		mp[u][v]=mp[v][u]=true;
		if(strlen(x)==strlen(y))
		{
			same[u].push_back(v);
			same[v].push_back(u);
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int x,y,cnt=0;
		scanf("%d %d",&x,&y);
		x=abs(x);
		y=abs(y);
		for(int u=0;u<same[x].size();u++)
		{
			for(int v=0;v<same[y].size();v++)
			{
				if(same[y][v]==x||same[x][u]==y)continue;
				if(mp[same[x][u]][same[y][v]]==true)
				{
					ans[cnt].x=same[x][u];
					ans[cnt++].y=same[y][v];
				}
			}
		}
		sort(ans,ans+cnt,cmp);
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++)
		{
			printf("%04d %04d\n",ans[i].x,ans[i].y);
		}
	}
	system("pause");
	return 0;
}