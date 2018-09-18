#include<stdio.h>
#include<vector>
#include<algorithm>

typedef long long LL;

using namespace std;

vector<LL> test;
int n,m;
 
bool cmp(LL a,LL b)
{
	return a<b;
}

int main()
{
	LL temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&temp);
		test.push_back(temp);
	}	
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%lld",&temp);
		test.push_back(temp);
	}
	sort(test.begin(),test.end(),cmp);
	int mid=(test.size()+1)/2-1;
	printf("%lld",test[mid]);
	return 0;
} 
