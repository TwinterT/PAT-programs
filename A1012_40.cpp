#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 2010;
const int INF = 1000000000;

typedef struct node
{
	int ID;
	int grade[4];
	int rank[4];
}node;//0=A,1=C,2=M,3=E

node test[maxn];
char mp[4]={'A','C','M','E'};
int now;

bool cmp(node a,node b)
{
	return a.grade[now]>b.grade[now];
}

void get_rank(int n)
{
	for(int i=0;i<4;i++)
	{
		now=i;
		sort(test,test+n,cmp);
		test[0].rank[now]=1;
		for(int j=1;j<n;j++)
		{
			if(test[j].grade[now]==test[j-1].grade[now])test[j].rank[now]=test[j-1].rank[now];
			else test[j].rank[now]=j+1;
		}
	}
}

int search(int key,int n)
{
	for(int i=0;i<n;i++)
	{
		if(test[i].ID==key)return i;
	}
	return -1;
}

void print(int m,int n)
{
	for(int i=0;i<m;i++)
	{
		int key;
		scanf("%d",&key);
		int key_x=search(key,n);
		if(key_x==-1)printf("N/A\n");
		else
		{
			int temp,min=INF;
			for(int i=0;i<4;i++)
			{
				if(test[key_x].rank[i]<min)
				{
					min=test[key_x].rank[i];
					temp=i;
				}
			}
			printf("%d %c\n",min,mp[temp]);
		}
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&test[i].ID,&test[i].grade[1],&test[i].grade[2],&test[i].grade[3]);
		test[i].grade[0]=test[i].grade[1]+test[i].grade[2]+test[i].grade[3];
	}
	get_rank(n);
	print(m,n);
	return 0;
}
