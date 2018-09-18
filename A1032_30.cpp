#include<stdio.h>

using namespace std;

typedef struct node
{
	char data;
	int next;
	bool flag;
	node()
	{
		flag=false;
	}
}node;

node test[100010];

int main()
{
	int ad1,ad2,n;
	scanf("%d %d %d",&ad1,&ad2,&n);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d ",&temp);
		scanf("%c %d",&test[temp].data,&test[temp].next);
	}
	int p;
	for(p=ad1;p!=-1;p=test[p].next)
	{
		test[p].flag=true;
	}
	for(p=ad2;p!=-1;p=test[p].next)
	{
		if(test[p].flag==true)break;
	}
	if(p==-1)printf("-1");
	else printf("%05d",p); 
	return 0;
} 
