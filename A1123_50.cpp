#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<math.h>

using namespace std;

typedef struct node
{
	int data,high;
	struct node *left,*right;
}node;

node *create(int data)
{
	node *ans=new node;
	ans->data=data;
	ans->high=1;
	ans->left=ans->right=NULL;
	return ans;
}

int get_high(node *root)
{
	if(root==NULL)return 0;
	else return root->high;
}
void updata_high(node *root)
{
	root->high=max(get_high(root->right),get_high(root->left))+1;
}

int get_balance(node *root)
{
	return get_high(root->left)-get_high(root->right);
}

void R(node* &root)
{
	node *temp=root->left;
	root->left=temp->right;
	temp->right=root;
	updata_high(root);
	updata_high(temp);
	root=temp;
}

void L(node* &root)
{
	node *temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updata_high(root);
	updata_high(temp);
	root=temp;
}

void insert(node* &root,int data)
{
	if(root==NULL)
	{
		root=create(data);
		return;
	}
	if(data<root->data)
	{
		insert(root->left,data);
		updata_high(root);
		if(get_balance(root)==2)
		{
			if(get_balance(root->left)==1)
			{
				R(root);
			}
			else if(get_balance(root->left)==-1)
			{
				L(root->left);
				R(root);
			}
		}
	}
	else 
	{
		insert(root->right,data);
		updata_high(root);
		if(get_balance(root)==-2)
		{
			if(get_balance(root->right)==-1)
			{
				L(root);
			}
			else if(get_balance(root->right)==1)
			{
				R(root->right);
				L(root);
			}
		}
	}
}

void level(node *root,int n)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node *top=q.front();
		q.pop();
		printf("%d",top->data);
		n--;
		printf(n?" ":"\n");
		if(top->left!=NULL)	q.push(top->left);
		if(top->right!=NULL)q.push(top->right);
	}
}

bool judge(node *root,int n)
{
	queue<node*> q;
	q.push(root);
	while(n)
	{
		node *top=q.front();
		q.pop();
		if(top==NULL)return false;
		n--;
		q.push(top->left);
		q.push(top->right);
	}
	return true;
}

int main()
{
	node *root=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int data;
		scanf("%d",&data);
		insert(root,data);
	}
	level(root,n);
	printf(judge(root,n)?"YES\n":"NO\n");
	system("pause");
	return 0;
}