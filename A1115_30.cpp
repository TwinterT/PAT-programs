#include<stdio.h>
#include<queue>
#include<stdlib.h>

using namespace std;

const int maxn=1010;

int n,max_level=-1;
int lev[maxn]={0};

typedef struct node
{
	int level;
	int data;
	struct node *left,*right;
}node;

void insert(node* &root,int key)
{
	if(root==NULL)
	{
		root=new node;
		root->data=key;
		root->right=NULL;
		root->left=NULL;
		return;
	}
	if(key<=root->data)insert(root->left,key);
	else insert(root->right,key);
}

void level(node *root)
{
	queue<node*> q;
	q.push(root);
	root->level=0;
	while(!q.empty())
	{
		node *top=q.front();
		q.pop();
		if(top->level>max_level)max_level=top->level;
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
	node *root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int key;
		scanf("%d",&key);
		insert(root,key);
	}
	level(root);
	printf("%d + %d = %d\n",lev[max_level],lev[max_level-1],lev[max_level]+lev[max_level-1]);
	system("pause");
	return 0;
}