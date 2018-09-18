#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

const int maxn=100005;

typedef struct node
{
	int id;
	int data;
	int next;
	int order;
	node()
	{
		order=maxn*2;
	}
}node;

node table[maxn],valid[maxn],invalid[maxn];
bool vis[maxn]={false};
int root,n;

bool cmp(node a,node b)
{
	return a.order<b.order;
}

int main()
{
	int i,num_va=0,num_in=0,temp;
	scanf("%d %d",&root,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		scanf("%d %d",&table[temp].data,&table[temp].next);
		table[temp].id=temp;
	}
	int address=root;
	while(address!=-1)
	{
		if(vis[abs(table[address].data)]==false)
		{
			table[address].order=num_va++;
			vis[abs(table[address].data)]=true;
		}
		else 
		{
			table[address].order=maxn+num_in++;
		}
		address=table[address].next;
	}
	sort(table,table+maxn,cmp);
	int count=num_va+num_in;
	for(i=0;i<count;i++)
	{
		if(i!=num_va-1&&i!=count-1)
		{
			printf("%05d %d %05d\n",table[i].id,table[i].data,table[i+1].id);
		}
		else printf("%05d %d -1\n",table[i].id,table[i].data);
	}
	return 0;
}