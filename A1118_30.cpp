#include<stdio.h>
#include<vector>
#include<set>
#include<stdlib.h>

using namespace std;

const int maxn=10010;

int father[maxn];
vector<int> temp;
set<int> num_father;
int find_father(int v)
{
	return (v==father[v])?v:father[v]=find_father(father[v]);
}

void init()
{
	for(int i=0;i<maxn;i++)
	{
		father[i]=i;
	}
}

void unit(int u,int v)
{
	int i=find_father(u);
	int j=find_father(v);
	father[j]=i;
}

int n,q;

int main()
{
	init();
	int num_max=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++)
		{
			int bird;
			scanf("%d",&bird);
			if(bird>num_max)num_max=bird;
			temp.push_back(bird);
		}
		if(temp.size()>1)
		{
			int temp_bird=temp[0];
			for(int k=1;k<temp.size();k++)
			{
				unit(temp_bird,temp[k]);
			}
		}
		temp.clear();
	}
	for(int i=1;i<=num_max;i++)
	{
		num_father.insert(find_father(i));
	}
	printf("%d %d\n",num_father.size(),num_max);
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		if(find_father(u)==find_father(v))
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}
	system("pause");
	return 0;
}