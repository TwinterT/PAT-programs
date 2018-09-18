#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

const int maxn=10010;

typedef struct memeber
{
	char name[10];
	int high;
}member;

bool cmp(member a,member b)
{
	if(a.high!=b.high)return a.high>b.high;
	else return strcmp(a.name,b.name)<0;
}

int main()
{
	member person[maxn];
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s%d",person[i].name,&person[i].high);
	}
	sort(person,person+n,cmp);
	int num=n-(k-1)*(n/k),leftPos=0;
	while(leftPos<n)
	{
		for(int i=(num%2)?(num-2):(num-1);i>=1;i-=2)
		{
			printf("%s ",person[leftPos+i].name);
		}
		for(int i=0;i<num;i+=2)
		{
			printf("%s",person[leftPos+i].name);
			if(num-i>2)printf(" ");
			else printf("\n");
		}
		leftPos+=num;
		num=n/k;
	}
	system("pause");
	return 0;
}