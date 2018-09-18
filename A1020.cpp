#include<stdio.h>
#include<queue>

using namespace std;

const int maxn = 100;
int in[maxn],post[maxn];
int num;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

node *create(int inL,int inR,int postL,int postR)
{
	if(inL>inR)return NULL;
	node *root = new node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++)
	{
		if(in[k]==post[postR])break;
	}
	int num=k-inL;//×ó×ÓÊ÷¸öÊý
	root->left=create(inL,k-1,postL,postL+num-1);
	root->right=create(k+1,inR,postL+num,postR-1);
	return root; 
}

void level_print(node *root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		printf("%d ",temp->data);
		if(temp->left)q.push(temp->left);
		if(temp->right)q.push(temp->right);
	}
	printf("\n");
	return;
}

int main()
{
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&post[i]);
	}
	for(int i=0;i<num;i++)
	{
		scanf("%d",&in[i]);
	}
	node *root=create(0,num-1,0,num-1);
	level_print(root);
	return 0;
}
