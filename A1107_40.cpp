#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int maxn=1010;

int n;
int hobby[maxn]={0};
int father[maxn];
int root[maxn]={0};

void init()
{
	for(int i=0;i<=n;i++)
	{
		father[i]=i;
	}
}

int find_father(int v)
{
	return (father[v]==v)?v:father[v]=find_father(father[v]);
}

void uni(int a,int b)
{
	int fat_a=find_father(a);
	int fat_b=find_father(b);
	father[fat_a]=fat_b;
	return;
}


bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int num,v;
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%d:",&num);
		for(int j=0;j<num;j++)
		{
			scanf("%d",&v);
			if(hobby[v]==0)
			{
				hobby[v]=i;
			}
			uni(i,hobby[v]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		root[find_father(i)]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(root[i]!=0)ans++;
	}
	sort(root+1,root+n+1,cmp);
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
	{
		printf("%d",root[i]);
		if(i!=ans)printf(" ");
	}
	printf("\n");
	system("pause");
	return 0;
}