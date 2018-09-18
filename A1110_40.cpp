#include<stdio.h>
#include<string.h>
#include<queue>
#include<stdlib.h>

using namespace std;

const int maxn=30;

typedef struct node
{
	int left,right;
}node;


bool isroot[maxn]={false};
node tree[maxn];
int n;

int input()
{
	char str[5];
	scanf("%s",str);
	if(str[0]=='-')return -1;
	if(strlen(str)==1)return str[0]-'0';
	else return (str[0]-'0')*10+(str[1]-'0');
}

int find_root()
{
	for(int i=0;i<n;i++)
	{
		if(isroot[i]==false)return i;
	}
}

bool level(int root,int &last)
{
	int num=0;
	queue<int> q;
	q.push(root);
	while(num<n)
	{
		int top=q.front();
		q.pop();
		if(top==-1)return false;
		last=top;
		num++;
		q.push(tree[top].left);
		q.push(tree[top].right);
		
	}
	return true;
}

int main()
{
	int left,right;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		left=input();
		right=input();
		if(left!=-1)isroot[left]=true;
		if(right!=-1)isroot[right]=true;
		tree[i].left=left;
		tree[i].right=right;
	}
	int root=find_root();
	int last;
	bool tag=level(root,last);
	if(tag==true)printf("YES %d\n",last);
	else printf("NO %d\n",root);
	system("pause");
	return 0;
}