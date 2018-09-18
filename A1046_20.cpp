#include<stdio.h>
#include<algorithm>

using namespace std;

int n,sum=0,m;
int dis[100010],A[100010];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
		sum+=A[i];
		dis[i]=sum;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int u,v,ans;
		scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		ans=dis[v-1]-dis[u-1];
		printf("%d\n",min(ans,sum-ans));
	}
	return 0;
}
