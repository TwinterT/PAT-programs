#include<stdio.h>
#include<queue>

using namespace std;

const int maxn = 40;

int postorder[maxn],inorder[maxn],n;

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

node *get_t(int postorder[],int left_p,int right_p,int inorder[],int left_i,int right_i)
{
	if(left_p>right_p||left_i>right_i)return NULL;
	node *t=new node;
	int mid;
	for(mid=left_i;mid<=right_i;mid++)
	{
		if(inorder[mid]==postorder[right_p])break;
	}
	t->data=postorder[right_p];
	t->left=get_t(postorder,left_p,left_p+mid-left_i-1,inorder,left_i,mid-1);
	t->right=get_t(postorder,left_p+mid-left_i,right_p-1,inorder,mid+1,right_i);
	return t;
}

void Level_travel(node *T)
{
	queue<node*> q;
	q.push(T);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		printf("%d",temp->data);
		if(temp->left!=NULL)q.push(temp->left);
		if(temp->right!=NULL)q.push(temp->right);
		if(!q.empty())printf(" ");
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&postorder[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&inorder[i]);
	}
	node *T=get_t(postorder,0,n-1,inorder,0,n-1);
	Level_travel(T);
	return 0;
} 
