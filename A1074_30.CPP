#include<stdio.h>
#include<algorithm>

using namespace std;

const int INF=1000000000;

typedef struct node
{
	int id;
	int num;
	int next;
	int order;
	node()
	{
		id=-1;
		num=INF;
		next=-1;
		order=INF;
	}
}node;

node data[100010];
int head,n,k,num=0;

bool cmp(node a,node b)
{
	return a.order<b.order;
}

int main()
{
	int i;
	scanf("%d %d %d",&head,&n,&k);
	for(i=0;i<n;i++)
	{
		int h;
		scanf("%d",&h);
		scanf("%d %d",&data[h].num,&data[h].next);
		data[h].id=h;
	}
	int ad=head;
	while(ad!=-1)
	{
		data[ad].order=num++;
		ad=data[ad].next;
	}
	sort(data,data+100010,cmp);
	for(i=0;i<num;i+=k)
	{
		if((i+k)<=num)reverse(data+i,data+i+k);
	}
	for(i=0;i<num-1;i++)
	{
		printf("%05d %d %05d\n",data[i].id,data[i].num,data[i+1].id);
	}
	printf("%05d %d -1\n",data[i].id,data[i].num);
	return 0;
}