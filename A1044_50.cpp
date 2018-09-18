#include<stdio.h>

const int N=100010;


int n,m;
int sum[N]={0};

int upper_bound(int L,int R,int x)
{
	int left=L,right=R,mid;
	while(left<right)
	{
		mid=(left+right)/2;
		if(sum[mid]>x)
		{
			right=mid;
		}
		else left=mid+1;
	}
	return left;
}

int main()
{
	int min=100000000;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		sum[i]=sum[i-1]+temp;
	}
	for(int i=1;i<=n;i++)
	{
		int j=upper_bound(i,n+1,sum[i-1]+m);
		if(sum[j-1]-sum[i-1]==m)
		{
			min=m;
			break;
		}
		else if(j<=n&&sum[j]-sum[i-1]<min)
		{
			min=sum[j]-sum[i-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int j=upper_bound(i,n+1,sum[i-1]+min);
		if(sum[j-1]-sum[i-1]==min)
		{
			printf("%d-%d\n",i,j-1);
		}
	}
	return 0;
} 















//ÒÔÏÂ³¬Ê± 

/*
#include<stdio.h>

const int INF=1000000000;

int n,m;
int num[100010];
int dp[100010];

void print(int i)
{
	int j=i,temp=dp[i];
	while(temp!=0)
	{
		temp-=num[j--];
	}
	printf("%d-%d\n",j+2,i+1);
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	dp[0]=num[0];
	for(int i=1;i<n;i++)
	{
		int j=i;
		int ans=0;
		while(j>=0&&ans<m)
		{
			ans+=num[j--];
		}
		dp[i]=ans;
	}
	int min=INF;
	bool tag=true;
	for(int i=0;i<n;i++)
	{
		if(dp[i]==m)
		{
			print(i);
			tag=false;
		}
		else if(dp[i]>m&&dp[i]<min)
			{
				min=dp[i];
			}
	}
	if(tag==true)
	{
		for(int i=0;i<n;i++)
		{
			if(dp[i]==min)print(i);
		}
	}
	return 0;
} 
*/
