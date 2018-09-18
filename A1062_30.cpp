#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct member
{
	int id;
	int virtue;
	int talent;
}member;

member mem[100010];
int n,L,H,num=0;

int judge_1(member a)
{
	if(a.virtue>=H&&a.talent>=H)return 5;
	else if(a.virtue>=H&&a.talent<H)return 4;
	else if(a.virtue<H&&a.talent<H&&a.virtue>=a.talent)return 3;
	else return 2;
}

bool judge_2(member a,member b)
{
	int total_a=a.virtue+a.talent,total_b=b.talent+b.virtue;
	if(total_a!=total_b)return total_a>total_b;
	else if(a.virtue!=b.virtue)return a.virtue>b.virtue;
		else return a.id<b.id;
	
}

bool cmp(member a,member b)
{
	if(judge_1(a)==judge_1(b))return judge_2(a,b);
	else return judge_1(a)>judge_1(b); 
}

int main()
{
	member temp;
	scanf("%d %d %d",&n,&L,&H);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&temp.id,&temp.virtue,&temp.talent);
		if(temp.talent<L||temp.virtue<L)continue;
		else 
		{
			mem[num++]=temp;
		}
	}
	sort(mem,mem+num,cmp);
	printf("%d\n",num);
	for(int i=0;i<num;i++)
	{
		printf("%d %d %d\n",mem[i].id,mem[i].virtue,mem[i].talent);
	}
	return 0;
} 
