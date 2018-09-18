#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn=100010;
const int INF=1000000000;

int n;
int max_num[maxn];
int min_num[maxn];
int data[maxn];
int pivot[maxn];

int main()
{
	int i,mi=INF,ma=-INF,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
		max_num[i]=ma;
		if(data[i]>ma)ma=data[i];
	}
	for(i=n-1;i>=0;i--)
	{
		min_num[i]=mi;
		if(data[i]<mi)mi=data[i];
	}
	for(i=0;i<n;i++)
	{
		if(data[i]>=max_num[i]&&data[i]<=min_num[i])
		{
			pivot[ans++]=data[i];
		}
	}
	sort(pivot,pivot+ans);
	printf("%d\n",ans);
	for(i=0;i<ans;i++)
	{
		printf("%d",pivot[i]);
		if(i!=ans-1)printf(" ");
	}
	printf("\n");
	return 0;
}