#include<stdio.h>
#include<stdlib.h>
#include<set>

using namespace std;

const int maxn=50010;

typedef struct node
{
	int id,cnt;
	friend bool operator <(node a,node b)
	{
		if(a.cnt!=b.cnt)return a.cnt>b.cnt;
		else return a.id<b.id;
	}
}node;

int times[maxn]={0};
set<node> s;

void print(int k)
{
	int i = 0;
    for (auto it = s.begin(); i < k && it != s.end(); it++, i++) {
        printf(" %d", it->id);
    }
    printf("\n");
}

int main()
{
	int n,k,pre,temp;
	node p;
	scanf("%d %d %d",&n,&k,&pre);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&temp);
		printf("%d:",temp);
		p.id=pre;
		p.cnt=times[pre];
		auto it=s.find(p);
		if(it!=s.end())s.erase(it);
		times[pre]++;
		p.cnt++;
		s.insert(p);
		print(k);
		pre=temp;
	}
	system("pause");
	return 0;
}