#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;

const int maxn=35;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

int n;
int in[maxn],pre[maxn],post[maxn],p_num=0;

node *create(int data)
{
	node *ans=new node;
	ans->data=data;
	ans->left=ans->right=NULL;
	return ans;
}


node *build(int in[],int in_left,int in_right,int pre[],int pre_left,int pre_right)
{
	if(in_left>in_right||pre_left>pre_right)
	{
		return NULL;
	}
	int temp=pre[pre_left],mid;
	for(int i=in_left;i<=in_right;i++)
	{
		if(temp==in[i])
		{
			mid=i;
			break;
		}
	}
	int l_num=mid-in_left;
	int r_num=in_right-mid;
	node *ans=create(in[mid]);
	ans->left=build(in,in_left,in_left+l_num-1,pre,pre_left+1,pre_left+l_num);
	ans->right=build(in,mid+1,in_right,pre,pre_right-r_num+1,pre_right);
	return ans;
}

void post_travel(node *root)
{
	if(root==NULL)
	{
		return;
	}
	post_travel(root->left);
	post_travel(root->right);
	post[p_num++]=root->data;
}

int main()
{
	char str[6];
	int i,key,in_num=0,pre_num=0;
	stack<int> s;
	scanf("%d",&n);
	for(i=0;i<2*n;i++)
	{
		scanf("%s",str);
		if(strcmp(str,"Push")==0)
		{
			scanf("%d\n",&key);
			s.push(key);
			pre[pre_num++]=key;
		}
		else
		{
			key=s.top();
			s.pop();
			in[in_num++]=key;
		}
	}
	node *root=build(in,0,n-1,pre,0,n-1);
	post_travel(root);
	for(i=0;i<p_num;i++)
	{
		printf("%d",post[i]);
		if(i!=p_num-1)printf(" ");
	}
	return 0;
}