#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

const int maxn=10010;

typedef struct node
{
	int id;
	int score[6];
	bool flag;
	int score_all;
	int solve;
}node;

node stu[maxn];
int n,k,m;
int full[6];

bool cmp(node a,node b)
{
	if(a.score_all!=b.score_all)return a.score_all>b.score_all;
	else if(a.solve!=b.solve)return a.solve>b.solve;
	else return a.id<b.id;
}

void init()
{
	for(int i=1;i<=n;i++)
	{
		stu[i].id=i;
		stu[i].score_all=0;
		stu[i].solve=0;
		stu[i].flag=false;
		memset(stu[i].score,-1,sizeof(stu[i].score));
	}
}
int main()
{
	int i,j;
	scanf("%d%d%d",&n,&k,&m);
	init();
	for(i=1;i<=k;i++)
	{
		scanf("%d",&full[i]);
	}
	int u_id,p_id,score_obtained;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&u_id,&p_id,&score_obtained);
		if(score_obtained!=-1)
		{
			stu[u_id].flag=true;
		}
		if(score_obtained==-1&&stu[u_id].score[p_id]==-1)
		{
			stu[u_id].score[p_id]=0;
		}
		if(score_obtained==full[p_id]&&stu[u_id].score[p_id]<full[p_id])
		{
			stu[u_id].solve++;
		}
		if(score_obtained>stu[u_id].score[p_id])
		{
			stu[u_id].score[p_id]=score_obtained;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(stu[i].score[j]!=-1)
				stu[i].score_all+=stu[i].score[j];
		}
	}
	sort(stu+1,stu+1+n,cmp);
	int r=1;
	for(i=1;i<=n&&stu[i].flag==true;i++)
	{
		if(i>1&&stu[i].score_all!=stu[i-1].score_all)
		{
			r=i;
		}
		printf("%d %05d %d",r,stu[i].id,stu[i].score_all);
		for(j=1;j<=k;j++)
		{
			if(stu[i].score[j]==-1)
			{
				printf(" -");
			}
			else 
			{
				printf(" %d",stu[i].score[j]);
			}
		}
		printf("\n");
	}
	return 0;
}

/*
#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct node
{
	int id;
	int rank;
	int total;
	int num[7];
	int down;
	int perfect;
	node()
	{
		total=0;
		down=0;
		for(int i=0;i<7;i++)
		{
			num[i]=-1;
		}
		perfect=0;
	}
}node;

int n,k,m;//用户数，问题数，申请数
int p[7];
node data[10010];

bool cmp(node a,node b)
{
	if(a.total!=b.total)return a.total>b.total;
	else if(a.perfect!=b.perfect)return a.perfect>b.perfect;
	else return a.id<b.id;
}

int main()
{
	int i,j,id,p_id,temp;
	scanf("%d %d %d",&n,&k,&m);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&p[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&id,&p_id);
		scanf("%d",&temp);
		data[id].id=id;
		if(temp>=0)data[id].down++;
		if(temp==-1)temp=0;
		if(temp>data[id].num[p_id])data[id].num[p_id]=temp;
	}	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(data[i].num[j]!=-1)
			{
				data[i].total+=data[i].num[j];
				if(data[i].num[j]==p[j])data[i].perfect++;
			}
		}
	}
	sort(data+1,data+n+1,cmp);//注意sort的起始位置
	data[1].rank=1;
	printf("%d %05d %d",data[1].rank,data[1].id,data[1].total);
	for(i=1;i<=k;i++)
	{
		if(data[1].num[i]!=-1)printf(" %d",data[1].num[i]);
		else printf(" -");
	}
	printf("\n");
	for(i=2;i<=n;i++)
	{
		if(data[i].down>0)
		{
			if(data[i].total==data[i-1].total)data[i].rank=data[i-1].rank;
			else data[i].rank=i;
			printf("%d %05d %d",data[i].rank,data[i].id,data[i].total);
			for(j=1;j<=k;j++)
			{
				if(data[i].num[j]!=-1)printf(" %d",data[i].num[j]);
				else printf(" -");
			}
			printf("\n");
		}
		else break;
	}
	return 0;
}

  */