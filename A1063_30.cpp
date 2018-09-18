#include<stdio.h>
#include<set>
#include<algorithm>

using namespace std;


set<int> data[55];
int n,k;

void judge(int a,int b)
{
	double ans=0;	
	set<int>::iterator it_a=data[a].begin(),it_b=data[b].begin();
	while(it_a!=data[a].end()&&it_b!=data[b].end())
	{
		if(*it_a<*it_b)it_a++;
		else if(*it_a>*it_b)it_b++;
		else
		{
			it_a++;
			it_b++;
			ans++;
		}
	}
	double res=ans/(data[a].size()+data[b].size()-ans)*100.0;
	printf("%.1f%%\n",res);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++)
		{
			int temp;
			scanf("%d",&temp);
			data[i].insert(temp);
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		judge(u,v);
	}
	return 0;
} 
