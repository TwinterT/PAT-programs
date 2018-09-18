#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

const int maxn=100010;

int n;
int data[maxn];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
	}
	sort(data+1,data+n+1,cmp);
	int ans=1;
	while(ans<=n&&ans<data[ans])
	{
		ans++;
	}
	printf("%d\n",ans-1);
	system("pause");
	return 0;
}