#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

typedef struct node
{
	char id[15];
	int score;
	int local_rank;
	int location;
}node;

node list[30010];
int n,k;

bool cmp(node a,node b)
{
	if(a.score!=b.score)return a.score>b.score;
	else return strcmp(a.id,b.id)<0;
}

int main()
{
	int num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			list[num].location=i;
			scanf("%s %d",list[num].id,&list[num].score);
			num++;
		}
		sort(list+num-k,list+num,cmp);
		list[num-k].local_rank=1;
		for(int u=num-k+1;u<num;u++)
		{
			if(list[u].score!=list[u-1].score)list[u].local_rank=u-num+k+1;
			else list[u].local_rank=list[u-1].local_rank;
		}
	}
	printf("%d\n",num); 
	sort(list,list+num,cmp);
	int r=1;
	printf("%s 1 %d %d\n",list[0].id,list[0].location,list[0].local_rank);
	for(int i=1;i<num;i++)
	{
		printf("%s ",list[i].id);
		if(list[i].score!=list[i-1].score)
		{
			r=i+1;
			printf("%d ",r);
		}
		else printf("%d ",r);
		printf("%d %d\n",list[i].location,list[i].local_rank);
	}
	return 0;
}
