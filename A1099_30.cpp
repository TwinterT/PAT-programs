#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

const int maxn = 110;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;


int left[maxn],right[maxn],n,data[maxn],num=0;

node *build(int root)
{
	if(root==-1)
	{
		return NULL;
	}
	node *ans=new node;
	ans->data=root;
	ans->left=build(left[root]);
	ans->right=build(right[root]);
	return ans;
}

void intravel(node *root)
{
	if(root==NULL)return ;
	intravel(root->left);
	root->data=data[num++];
	intravel(root->right);
}

void level(node *root)
{
	int num=0;
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node *top=q.front();
		q.pop();
		if(num==0)printf("%d",top->data);
		else printf(" %d",top->data);
		num++;
		if(top->left!=NULL)q.push(top->left);
		if(top->right!=NULL)q.push(top->right);
	}
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&left[i],&right[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	sort(data,data+n);
	node *root=build(0);
	intravel(root);
	level(root);
	return 0;
}