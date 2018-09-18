#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct node
{
	int id;
	int data;
	int next;
	bool flag;
	node()
	{
		flag=false;
	} 
}node;


node test[100010];
int n,st;

bool cmp(node a,node b)
{
	if(a.flag!=true||b.flag!=true)return a.flag>b.flag;
	else return a.data<b.data;
}

int main()
{
	scanf("%d %d",&n,&st);
	for(int i=0;i<n;i++)
	{
		int address;
		scanf("%d",&address);
		scanf("%d %d",&test[address].data,&test[address].next);
		test[address].id=address;
	}
	int num=0;
	while(st!=-1)
	{
		test[st].flag=true;
		st=test[st].next;
		num++;
	}
	if(num==0)printf("0 -1\n");
	else
	{
		sort(test,test+100010,cmp); 
		printf("%d %05d\n",num,test[0].id);
		for(int i=0;i<num-1;i++)
		{
			printf("%05d %d %05d\n",test[i].id,test[i].data,test[i+1].id);
		}
		printf("%05d %d -1\n",test[num-1].id,test[num-1].data);
	}
	return 0;
} 
