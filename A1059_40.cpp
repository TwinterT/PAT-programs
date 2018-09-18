#include<stdio.h>
#include<math.h>

const int maxn = 100010;

typedef struct factor
{
	int x,cnt;
}factor;

int n,prime[maxn],pnum=0,num=0;
factor fac[10];

bool is_prime(int k)
{
	if(k==1)return false;
	int sqr=(int)sqrt(k*1.0);
	for(int i=2;i<=sqr;i++)
	{
		if(k%i==0)return false;
	}
	return true;
}


void get_prime()
{
	for(int i=2;i<maxn;i++)
	{
		if(is_prime(i)==true)prime[pnum++]=i;
	}
}

int main()
{
	get_prime();
	scanf("%d",&n);
	if(n==1)printf("1=1");
	else
	{
		printf("%d=",n);
		int sqr=(int)sqrt(n*1.0);
		for(int i=0;i<pnum&&prime[i]<=sqr;i++)
		{
			if(n%prime[i]==0)
			{
				fac[num].x=prime[i];
				fac[num].cnt=0;
				while(n%prime[i]==0)
				{
					fac[num].cnt++;
					n=n/prime[i];
				}
				num++;
			}
			if(n==1)break;
		}
		if(n!=1)
		{
			fac[num].x=n;
			fac[num++].cnt=1;
		}
		for(int i=0;i<num;i++)
		{
			if(i>0)printf("*");
			printf("%d",fac[i].x);
			if(fac[i].cnt>1)printf("^%d",fac[i].cnt);
		}
	}
	return 0;
} 
