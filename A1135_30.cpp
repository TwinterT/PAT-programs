#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<set>

using namespace std;

typedef struct node
{
	int data;
	bool tag;//trueÎªºì£¬falseÎªºÚ
	struct node *right,*left;
}node;

int n;
set<int> ans;
int black_num;

node *create(int data)
{
	node *ans=new node;
	ans->data=abs(data);
	if(data<0)ans->tag=true;
	else ans->tag=false;
	ans->left=ans->right=NULL;
	return ans;
}


void insert(node* &root,int data)
{
	if(root==NULL)
	{
		root=create(data);
		return ;
	}
	if(abs(data)<root->data)insert(root->left,data);
	else insert(root->right,data);
}

bool judge_1(node *root)
{
	if(root->tag!=false)return false;
	else return true;
}

bool judge_2(node *root)
{
	if(root==NULL)return true;
	if(root->tag==true)
	{
		if((root->left==NULL||root->left->tag==false)&&(root->right==NULL||root->right->tag==false))
		{
			return judge_2(root->left)&&judge_2(root->right);
		}
		else return false;
	}
	return judge_2(root->left)&&judge_2(root->right);
}



void DFS(node *root)
{
	if(root==NULL)
	{
		ans.insert(black_num);
		return;
	}
	if(root->tag==false)black_num++;
	DFS(root->left);
	DFS(root->right);
	if(root->tag==false)black_num--;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int num;
		black_num=0;
		node *root=NULL;
		scanf("%d",&num);
		for(int j=0;j<num;j++)
		{
			int data;
			scanf("%d",&data);
			insert(root,data);
		}
		DFS(root);
		printf("j=%d jj=%d",judge_1(root),judge_2(root));
		if(judge_1(root)&&judge_2(root)&&ans.size()==1)
		{
			printf("Yes\n");
		}
		else printf("No\n");
		ans.clear();
	}
	system("pause");
	return 0;
}