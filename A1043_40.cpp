#include<stdio.h>
#include<vector>

using namespace std;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

void insert(node* &root,int data)
{
	if(root==NULL)
	{
		root=new node;
		root->data=data;
		root->left=root->right=NULL;
		return;
	}
	if(data<root->data)insert(root->left,data);
	else insert(root->right,data);
}

void preorder(node* root,vector<int> &vi)
{
	if(root==NULL)return;
	vi.push_back(root->data);
	preorder(root->left,vi);
	preorder(root->right,vi);
}

void preordermirror(node* root,vector<int> &vi)
{
	if(root==NULL)return;
	vi.push_back(root->data);
	preordermirror(root->right,vi);
	preordermirror(root->left,vi);
}

void postorder(node* root,vector<int> &vi)
{
	if(root==NULL)return;
	postorder(root->left,vi);
	postorder(root->right,vi);
	vi.push_back(root->data);
}

void postordermirror(node* root,vector<int> &vi)
{
	if(root==NULL)return;
	postordermirror(root->right,vi);
	postordermirror(root->left,vi);
	vi.push_back(root->data);
}

vector<int> origin,pre,preM,post,postM;

int main()
{
	int n,data;
	scanf("%d",&n);
	node *root=NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		insert(root,data);
		origin.push_back(data);
	}
	preorder(root,pre);
	preordermirror(root,preM);
	postorder(root,post);
	postordermirror(root,postM);
	if(origin==pre)
	{
		printf("YES\n");
		for(int i=0;i<post.size();i++)
		{
			printf("%d",post[i]);
			if(i!=post.size()-1)printf(" ");
		}
	}
	else if(origin==preM)
		{
			printf("YES\n");
			for(int i=0;i<postM.size();i++)
			{
				printf("%d",postM[i]);
				if(i!=postM.size()-1)printf(" ");
			}
		}
		else printf("NO\n");
	return 0;
} 
