#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m;
int value[100010];

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&value[i]);
	}
	sort(value,value+n,cmp);
	int u=0,v=n-1;
	while(u!=v)
	{
		if((value[u]+value[v])<m)u++;
		else if((value[u]+value[v])>m)v--;
			else break;
	}
	if(u==v)printf("No Solution\n");
	else printf("%d %d\n",value[u],value[v]);
	return 0;
} 
