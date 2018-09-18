#include<stdio.h>
#include<queue>

using namespace std;

const int maxn=15;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

int n;
int left[maxn],right[maxn];
int father[maxn];
int travel[maxn];
int num=0;

int find_father(int v)
{
	return (father[v]==v)?v:(father[v]=find_father(father[v]));
}

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

void level(node* r)
{
	
	queue<node *> q;
	q.push(r);
	while(!q.empty())
	{
		node *top=q.front();
		q.pop();
		travel[num++]=top->data;
		if(top->right!=NULL)q.push(top->right);
		if(top->left!=NULL)q.push(top->left);
		
	}
}

void inorder(node *r)
{
	if(r==NULL)
	{
		return;
	}
	inorder(r->right);
	travel[num++]=r->data;
	inorder(r->left);
}

int main()
{
	int i,root;
	char a,b;
	scanf("%d%*c",&n);
	for(i=0;i<n;i++)
	{
		scanf("%c %c%*c",&a,&b);
		if(a=='-')left[i]=-1;
		else left[i]=a-'0';
		if(b=='-')right[i]=-1;
		else right[i]=b-'0';
		
	}
	for(i=0;i<n;i++)
	{
		father[i]=i;
	}
	for(i=0;i<n;i++)
	{
		if(left[i]!=-1)father[left[i]]=i;
		if(right[i]!=-1)father[right[i]]=i;
	}
	root=find_father(0);
	node *r=build(root);
	level(r);
	for(i=0;i<num;i++)
	{
		printf("%d",travel[i]);
		if(i!=n-1)printf(" ");
	}
	printf("\n");
	num=0;
	inorder(r);
	for(i=0;i<num;i++)
	{
		printf("%d",travel[i]);
		if(i!=n-1)printf(" ");
	}
	printf("\n");
	return 0;
}