#include<stdio.h>
#include<math.h>

int N,D;

bool IsPrime(int n)
{
	if(n<=1)return false;
	else
	{
		for(int i=2;i<=(int)sqrt(n*1.0);i++)
		{
			if(n%i==0)return false;
		}
		return true;
	}
}

int get_reverse(int n,int d)
{
	int num[20],k=0,ans=0;
	while(n!=0)
	{
		num[k++]=n%d;
		n=n/d;
	}
	for(int i=0;i<k;i++)
	{
		ans=ans*d+num[i];
	}
	return ans;
}

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		if(N<0)return 0;
		else
		{
			scanf("%d",&D);
			int re=get_reverse(N,D);
			if(IsPrime(N)&&IsPrime(re))
			{
				printf("Yes\n");
			}
			else printf("No\n");
		}
	}
	return 0;
} 
