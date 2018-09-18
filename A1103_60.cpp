#include<stdio.h>
#include<vector>

using namespace std;

int n,p,k,max_sum=-1;
vector<int> fac,temp,res;

int power(int v)
{
	int ans=1;
	for(int i=0;i<p;i++)
	{
		ans*=v;
	}
	return ans;
}

void DSF(int index,int sum,int idx_sum,int num)
{
	if(sum>n||num>k)
	{
		return;
	}
	if(sum==n&&num==k)
	{
		if(idx_sum>max_sum)
		{
			res=temp;
			max_sum=idx_sum;
		}
		return;
	}
	if(index>0)
	{
		temp.push_back(index);
		DSF(index,sum+fac[index],idx_sum+index,num+1);
		temp.pop_back();
		DSF(index-1,sum,idx_sum,num);
	}
}

void init()
{
	int i=0;
	while(power(i)<=n)
	{
		fac.push_back(power(i));
		i++;
	}
}


int main()
{
	scanf("%d %d %d",&n,&k,&p);
	init();
	DSF(fac.size()-1,0,0,0);
	if(max_sum==-1)printf("Impossible\n");
	else
	{
		printf("%d = %d^%d",n,res[0],p);
		for(int i=1;i<res.size();i++)
		{
			printf(" + %d^%d",res[i],p);
		}
	}
	return 0;
}