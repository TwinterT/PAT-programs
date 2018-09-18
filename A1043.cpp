#include<stdio.h>
#include<vector>

using namespace std;

struct node
{
	int data;
	node *left,*right;
};

int num;
vector<int> origin,pre,preM,post,postM;

void insert(node* &root,int data)
{
	if(root==NULL)
	{
		root=new node;
		root->data=data;
		root->right=NULL;
		root->left=NULL;
		return;
	}
	if(root->data>data)insert(root->left,data);
	else insert(root->right,data);
}

void preorder(node *root)
{
	if(root==NULL)return;
	pre.push_back(root->data);
	preorder(root->left);
	preorder(root->right); 
}

void preorderM(node *root)
{
	if(root==NULL)return;
	preM.push_back(root->data);
	preorderM(root->right);
	preorderM(root->left);	
}

void postorder(node *root)
{
	if(root==NULL)return;
	postorder(root->left);
	postorder(root->right);
	post.push_back(root->data);
}

void postorderM(node *root)
{
	if(root==NULL)return;
	postorderM(root->right);
	postorderM(root->left);
	postM.push_back(root->data);
}

int main()
{
	node *root=NULL;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		origin.push_back(temp);
		insert(root,temp);
	}
	preorder(root);
	preorderM(root);
	postorder(root);
	postorderM(root);
	if(pre==origin)
	{
		printf("YES\n");
		for(int i=0;i<post.size();i++)
		{
			printf("%d",post[i]);
			if(i<post.size()-1)printf(" ");
		}
	} else if(origin==preM)
		{
			printf("YES\n");
			for(int i=0;i<postM.size();i++)
			{
				printf("%d",postM[i]);
				if(i<postM.size()-1)printf(" ");
			}
		}
		else
		{
			printf("NO\n");
		}
	return 0;
} 
