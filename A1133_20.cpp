#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

const int maxn=100010;

typedef struct node
{
	int id;
	int data;
	int next;
}node;

node data[maxn];
vector<node> ans,temp;
int n,k;

int main()
{
	int root;
	scanf("%d %d %d",&root,&n,&k);
	for(int i=0;i<n;i++)
	{
		int id;
		scanf("%d",&id);
		scanf("%d %d",&data[id].data,&data[id].next);
		data[id].id=id;
	}
	while(root!=-1)
	{
		temp.push_back(data[root]);
		root=data[root].next;
	}
	for(int i=0;i<temp.size();i++)
	{
		if(temp[i].data<0)ans.push_back(temp[i]);
	}
	for(int i=0;i<temp.size();i++)
	{
		if(temp[i].data>=0&&temp[i].data<=k)ans.push_back(temp[i]);
	}
	for(int i=0;i<temp.size();i++)
	{
		if(temp[i].data>k)ans.push_back(temp[i]);
	}
	for(int i=0;i<ans.size();i++)
	{
		if(i!=ans.size()-1)printf("%05d %d %05d\n",ans[i].id,ans[i].data,ans[i+1].id);
		else printf("%05d %d -1\n",ans[i].id,ans[i].data);
	}
	system("pause");
	return 0;
}