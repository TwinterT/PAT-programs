#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn=35;

typedef struct node
{
	int data;
	int level;
	struct node *right,*left;
}node;

int lev[maxn]={0},ans[maxn];
int in[maxn],post[maxn];
int n,max_level=1;

node *build(int in_left,int in_right,int post_left,int post_right)
{
	if(in_left>in_right||post_left>post_right)
	{
		return NULL;
	}
	node *ans=new node;
	ans->data=post[post_right];
	int i;
	for(i=in_left;i<=in_right;i++)
	{
		if(in[i]==post[post_right])break;
	}
	int num=i-in_left;
	ans->left=build(in_left,i-1,post_left,post_left+num-1);
	ans->right=build(i+1,in_right,post_left+num,post_right-1);
	return ans;
}

void travel(node *root,int num)
{
	queue<node*> q;
	root->level=1;
	q.push(root);
	while(!q.empty())
	{
		node *top=q.front();
		q.pop();
		ans[num++]=top->data;
		if(max_level<top->level)max_level=top->level;
		lev[top->level]++;
		if(top->left!=NULL)
		{
			top->left->level=top->level+1;
			q.push(top->left);
		}
		if(top->right!=NULL)
		{
			top->right->level=top->level+1;
			q.push(top->right);
		}

	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&post[i]);
	}
	node *root=build(0,n-1,0,n-1);
	travel(root,0);
	int temp=0;
	for(int i=1;i<=max_level;i++)
	{
		if(i%2==1)
		{
			reverse(ans+temp,ans+temp+lev[i]);
		}
		temp+=lev[i];
	}
	for(int i=0;i<n;i++)
	{
		printf("%d",ans[i]);
		if(i!=n-1)printf(" ");
		else printf("\n");
	}
	system("pause");
	return 0;
}