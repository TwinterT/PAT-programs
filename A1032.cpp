#include<stdio.h>

const int maxn = 100010;

typedef struct Node
{
	char data;
	int next;
	bool flag;
}Node;

int find_same(Node test[],int ad1,int ad2)
{
	int ans=-1;
	for(int k=ad1;k!=-1;k=test[k].next)
	{
		test[k].flag=true;
	}
	for(int k=ad2;k!=-1;k=test[k].next)
	{
		if(test[k].flag==true)
		{
			ans=k;
			break;
		}
	}
	return ans;
}

int main()
{
	Node test[maxn];
	for(int i=0;i<maxn;i++)
		test[i].flag=false;
	int ad1,ad2,n;
	int temp1,temp2;
	char da;
	scanf("%d%d%d",&ad1,&ad2,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %c %d",&temp1,&da,&temp2);
		test[temp1].data=da;
		test[temp1].next=temp2;
	}
	int ans=find_same(test,ad1,ad2);
	if(ans==-1)printf("-1\n");
	else printf("%05d",ans);
	return 0;
} 
