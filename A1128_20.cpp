#include<stdio.h>
#include<stdlib.h>
#include<set>

using namespace std;

int n;

bool judge(int num)
{
	set<int> row,a,b;
	for(int i=1;i<=num;i++)
	{
		int data;
		scanf("%d",&data);
		row.insert(data);
		a.insert(data+i);
		b.insert(data-i);
	}
	if(row.size()==num&&a.size()==num&&b.size()==num)return true;
	else return false;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		if(judge(num))printf("YES\n");
		else printf("NO\n");
	}
	system("pause");
	return 0;
}