#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct node
{
	int data,high;
	struct node *left,*right;
}node;

node *newNode(int data)
{
	node *ans=new node;
	ans->high=1;
	ans->data=data;
	ans->left=ans->right=NULL;
	return ans;
}

int get_high(node *t)
{
	if(t==NULL)return 0;
	return t->high;
}

void updata_high(node *t)
{
	t->high=max(get_high(t->left),get_high(t->right))+1;
}

int get_balance(node *t)
{
	return get_high(t->left)-get_high(t->right);
}

void R(node* &t)
{
	node *temp=t->left;
	t->left=temp->right;
	temp->right=t;
	updata_high(t);
	updata_high(temp);
	t=temp;
}

void L(node* &t)
{
	node *temp=t->right;
	t->right=temp->left;
	temp->left=t;
	updata_high(t);
	updata_high(temp);
	t=temp;
}


void insert(node* &t,int data)
{
	if(t==NULL)
	{
		t=newNode(data);
		return;
	}
	if(data<t->data)
	{
		insert(t->left,data);
		updata_high(t);
		if(get_balance(t)==2)
		{
			if(get_balance(t->left)==1)R(t);
			else if(get_balance(t->left)==-1){
				L(t->left);
				R(t);
			} 
		}
	}
	else
	{
		insert(t->right,data);
		updata_high(t);
		if(get_balance(t)==-2)
		{
			if(get_balance(t->right)==-1)L(t);
			else if(get_balance(t->right)==1){
				R(t->right);
				L(t);
			}
		}
	}
}

int main()
{
	node *root=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		insert(root,temp);
	}
	printf("%d\n",root->data);
	return 0;
}









/*
#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct node
{
	int data;
	int high;
	struct node *left,*right;
} node;

node *create(int data)
{
	node *ans=new node;
	ans->data=data;
	ans->left=ans->right=NULL;
	ans->high=1;
	return ans;
}

int get_hight(node *t)
{
	if(t==NULL)return 0;
	return t->high;
	
}

void updata_high(node *t)
{
	t->high=max(get_hight(t->left),get_hight(t->right))+1;
} 

int get_balance(node *t)
{
	return get_hight(t->left)-get_hight(t->right);
}

void R(node* &t)
{
	node *temp=t->left;
	t->left=temp->right;
	temp->right=t;
	updata_high(t);
	updata_high(temp);
	t=temp;
}

void L(node* &t)
{
	node *temp=t->right;
	t->right=temp->left;
	temp->left=t;
	updata_high(t);
	updata_high(temp);
	t=temp;
}

void insert(node* &t,int data)
{
	if(t==NULL)
	{
		t=create(data);
		return ;
	}
	if(data<t->data)
	{
		insert(t->left,data);
		updata_high(t);
		if(get_balance(t)==2)
		{
			if(get_balance(t->left)==1)R(t);
			else if(get_balance(t->left)==-1){
				L(t->left);
				R(t);
			}
		}
	}
	else 
	{
		insert(t->right,data);
		updata_high(t);
		if(get_balance(t)==-2)
		{
			if(get_balance(t->right)==-1)L(t);
			else if(get_balance(t->right)==1){
				R(t->right);
				L(t);
			}
		}
	}
	
}

int n;

int main()
{
	scanf("%d",&n);
	node *root=NULL;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		insert(root,temp);
	}
	printf("%d\n",root->data);
	return 0;
} 
*/
