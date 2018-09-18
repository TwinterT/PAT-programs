#include<stdio.h>
#include<stdlib.h>

const int maxn=40;

int n;
int pre[maxn],post[maxn];
bool unique=true;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

node *build(int pre[],int pre_left,int pre_right,int post[],int post_left,int post_right)
{
	if(pre_left>pre_right||post_left>post_right)
	{
		return NULL;
	}
	node *ans=new node;
	ans->data=pre[pre_left];
	int k,numleft=0;
	for(k=post_left;k<post_right;k++)
	{
		numleft++;
		if(post[k]==pre[pre_left+1])break;
	}
	printf("%d\n",k);
	printf("%d %d\n",pre_left+1,pre_left+numleft); 
	if(k==post_right-1)unique=false;
	ans->left=build(pre,pre_left+1,pre_left+numleft,post,post_left,k);
	ans->right=build(pre,pre_left+numleft+1,pre_right,post,k+1,post_right-1);
	return ans;
}
int num=0;
void inorder(node *root)
{
	if(root==NULL)return;
	inorder(root->left);
	if(num==0)
	{
		printf("%d",root->data);
		num++;
	}
	else 
	{
		printf(" %d",root->data);
		num++;
	}
	inorder(root->right);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&post[i]);
	}
	node* root=build(pre,0,n-1,post,0,n-1);
	if(unique==true)printf("Yes\n");
	else printf("No\n");
	inorder(root);
	printf("\n");
	system("pause");
	return 0;
}
