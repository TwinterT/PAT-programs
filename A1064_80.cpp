#include<stdio.h>
#include<algorithm>

using namespace std;

int n,num[1010],t[1010],index=0;

void inorder(int root)
{
	if(root>n)
	{
		return;
	}
	inorder(root*2);
	t[root]=num[index++];
	inorder(root*2+1);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	inorder(1);
	for(int i=1;i<=n;i++)
	{
		printf("%d",t[i]);
		if(i!=n)printf(" ");
	}
	return 0;
} 
