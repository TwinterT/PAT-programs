#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn=40010;

typedef struct node//ѧ���ڵ�
{
	int id;
	int ge,gi,total;
	int prefer[6];
	int r;
}node;

typedef struct Node//ѧУ�ڵ�
{
	int quota;
	int id[40010];
	int real;//��������
	int last;//���һ������ѧ����λ��
}Node;

int n,m,k;
node stu[maxn];
Node school[110];

bool cmp(node a,node b)
{
	if(a.total!=b.total)return a.total>b.total;
	else return a.ge>b.ge;
}

bool cmp_id(int a,int b)
{
	return stu[a].id<stu[b].id;
}

int main()
{
	int i,j;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%d",&school[i].quota);
		school[i].real=0;
		school[i].last=-1;
	}
	for(i=0;i<n;i++)
	{
		stu[i].id=i;
		scanf("%d %d",&stu[i].ge,&stu[i].gi);
		stu[i].total=stu[i].ge+stu[i].gi;
		for(j=0;j<k;j++)
		{
			scanf("%d",&stu[i].prefer[j]);
		}
	}	
	sort(stu,stu+n,cmp);
	for(i=0;i<n;i++)//����
	{
		if(i>0&&stu[i].total==stu[i-1].total&&stu[i].ge==stu[i-1].ge)stu[i].r=stu[i-1].r;
		else stu[i].r=i;
	}
	for(i=0;i<n;i++)//����
	{
		for(j=0;j<k;j++)
		{
			int pre=stu[i].prefer[j];
			int num=school[pre].real;
			int last=school[pre].last;
			if(num<school[pre].quota||(last!=-1&&stu[i].r==stu[last].r))
			{
				school[pre].id[num]=i;
				school[pre].last=i;
				school[pre].real++;
				break;
			}
		}
	}

	for(i=0;i<m;i++)//������
	{
		if(school[i].real>0)
		{
			sort(school[i].id,school[i].id+school[i].real,cmp_id);
			for(j=0;j<school[i].real;j++)
			{
				printf("%d",stu[school[i].id[j]].id);
				if(j<school[i].real-1)printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
