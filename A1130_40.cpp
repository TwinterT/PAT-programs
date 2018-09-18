#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<string>
#include<iostream>

using namespace std;

const int maxn=25;

typedef struct node
{
	int data,high;
	struct node *left,*right;
}node;

map<int,string> mp;
int n;
int lchild[maxn],rchild[maxn];
bool vis[maxn]={false};

node *build(int root)
{
	if(root==-1)return NULL;
	node *ans=new node;
	ans->data=root;
	ans->left=build(lchild[root]);
	ans->right=build(rchild[root]);
	return ans;
}

int get_high(node *root)
{
	if(root==NULL)return 0;
	root->high=max(get_high(root->left),get_high(root->right))+1;
	return root->high;
}

void inorder(node *root)
{
	if(root==NULL)return;
	if(root->left!=NULL&&root->left->high>1)printf("(");
	inorder(root->left);
	if(root->left!=NULL&&root->left->high>1)printf(")");
	cout<<mp[root->data];
	if(root->right!=NULL&&root->right->high>1)printf("(");
	inorder(root->right);
	if(root->right!=NULL&&root->right->high>1)printf(")");
}

int main()
{
	string temp;
	int u,v,root;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>temp>>u>>v;
		mp[i]=temp;
		lchild[i]=u;
		rchild[i]=v;
		if(u!=-1)vis[u]=true;
		if(v!=-1)vis[v]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			root=i;
			break;
		}
	}
	node *r=build(root);
	get_high(r);
	inorder(r);
	system("pause");
	return 0;
}