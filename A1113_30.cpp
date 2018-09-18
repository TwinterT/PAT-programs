#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int maxn=100010;

int n,num[maxn];



int main()
{
	scanf("%d",&n);
	int sum=0,sum_1=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		sum+=num[i];
	}
	nth_element(num,num+n/2,num+n);
	for(int i=0;i<n/2;i++)
	{
		sum_1+=num[i];
	}
	printf("%d %d\n",n%2,sum-sum_1-sum_1);
	system("pause");
	return 0;
}






/*

#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

const int maxn=100010;

int n,num[maxn];

int main()
{
	int sum=0,sum_1=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		sum+=num[i];
	}
	sort(num,num+n);
	for(int i=0;i<n/2;i++)
	{
		sum_1+=num[i];
	}
	printf("%d %d\n",n%2,sum-sum_1-sum_1);
	system("pause");
	return 0;
}

*/