#include<stdio.h>
#include<stdlib.h>

const int maxn=50010;

int n;
int pre[maxn],in[maxn];

int get_first(int pre_left,int pre_right,int in_left,int in_right)
{
	if(pre_left==pre_right)return pre[pre_left];
	int root=pre[pre_left];
	int idx;
	for(int i=in_left;i<=in_right;i++)
	{
		if(root==in[i])
		{
			idx=i;
			break;
		}
	}
	int left_num=idx-in_left;
	if(left_num>0)return get_first(pre_left+1,pre_left+left_num,in_left,idx-1);//×ó×ÓÊ÷ÕÒ
	else return get_first(pre_left+left_num+1,pre_right,idx+1,in_right);
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
		scanf("%d",&in[i]);
	}
	int ans=get_first(0,n-1,0,n-1);
	printf("%d\n",ans);
	system("pause");
	return 0;
}