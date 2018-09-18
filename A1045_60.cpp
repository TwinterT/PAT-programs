#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int mp[202],color[10010],dp[10010];
int n,m,L;

int main()
{
	scanf("%d %d",&n,&m);
	fill(mp,mp+n+1,-1);
	for(int i=0;i<m;i++)
	{
		int temp;
		scanf("%d",&temp);
		mp[temp]=i;
	}
	scanf("%d",&L);
	int num=0;
	for(int i=0;i<L;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(mp[temp]>=0)
		{
			color[num++]=mp[temp];
		}
	}
	int ans=0;
	for(int i=0;i<num;i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if((color[i]>=color[j])&&(dp[i]<dp[j]+1))
			{
				dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
} 
