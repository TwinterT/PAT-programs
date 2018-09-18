#include<stdio.h> 
#include<algorithm>

using namespace std;

const int maxn = 100010;

typedef struct Node
{
	int address,key,next;
	bool flag;
}Node;

Node test[maxn];

bool cmp(Node n1,Node n2)
{
	if(n1.flag==false||n2.flag==false)return n1.flag>n2.flag;
	else return n1.key<n2.key;
}

int main()
{
	for(int i=0;i<maxn;i++)
	{
		test[i].flag=false;
	}
	int n,address,begin;
	scanf("%d%d",&n,&begin);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&address);
		scanf("%d%d",&test[address].key,&test[address].next);
		test[address].address=address;
		test[address].flag=true;
	}
	sort(test,test+maxn,cmp);
	printf("%d %05d\n",n,test[0].address);
	for(int i=0;i<n;i++)
	{
		printf("%05d %d",test[i].address,test[i].key);
		if(i==n-1)printf(" -1\n");
		else printf(" %05d\n",test[i+1].address);
	}
	return 0;
}
