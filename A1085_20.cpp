#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 100010;

typedef long long LL;

LL num[maxn];
int n;
LL p;
int dp[maxn];

int main()
{
	int i,j;
	scanf("%d %lld",&n,&p);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&num[i]);
	}
	sort(num,num+n);
	
	j=0;
	for(i=0;i<n;i++)
	{
		LL min=num[i];
		for(;j<n;j++)
		{
			if(num[j]>min*p)break;
		}
		dp[i]=j-i;
	}
	int max=-1;
	for(i=0;i<n;i++)
	{
		if(max<dp[i])
		{
			max=dp[i];
		}
	}
	printf("%d\n",max);
	return 0;
}