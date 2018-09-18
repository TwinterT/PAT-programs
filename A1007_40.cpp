#include<stdio.h>

const int maxn = 10010;

int n,a[maxn];
int dp[maxn],s[maxn]={0};


int main()
{
	scanf("%d",&n);
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=0)flag=true;
	}

	if(flag==false)
	{
		printf("0 %d %d",a[0],a[n-1]);
		return 0;
	}
	dp[0]=a[0];
	for(int i=1;i<n;i++)
	{
		if(dp[i-1]+a[i]>a[i])
		{
			dp[i]=dp[i-1]+a[i];
			s[i]=s[i-1];
		}
		else
		{
			dp[i]=a[i];
			s[i]=i;
		}
	}
	int temp=0;
	for(int i=1;i<n;i++)
	{
		if(dp[i]>dp[temp])temp=i;
	}
	printf("%d %d %d",dp[temp],a[s[temp]],a[temp]);
	return 0;
}


















/*
#include<stdio.h>

int n,a[10010];
int max_sum=0,max_i=0,max_j=0;
int temp_sum=0,temp_i=0,temp_j=0;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(temp_sum<=0)
		{
			temp_sum=num[i];
			temp_i=i;
			temp_j=i; 
		}
		else
		{
			temp_sum+=num[i];
			temp_j++;
		}
		if(temp_sum>max_sum)
		{
			max_sum=temp_sum;
			max_i=temp_i;
			max_j=temp_j;
		}

	}
	printf("%d %d %d",max_sum,num[max_i],num[max_j]);
	return 0;
} 
*/
