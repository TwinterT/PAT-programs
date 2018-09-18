#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

typedef struct people
{
	char name[10];
	int age;
	int worth;
}people;

bool cmp(people a,people b)
{
	if(a.worth!=b.worth)return a.worth>b.worth;
	else if(a.age!=b.age)return a.age<b.age;
		else return strcmp(a.name,b.name)<0;
}

people data[100010],valid[100010];
int n,k,validnum=0;
int age[100010]={0};

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d %d",data[i].name,&data[i].age,&data[i].worth);
	}
	sort(data,data+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(age[data[i].age]<100)
		{
			age[data[i].age]++;
			valid[validnum++]=data[i];
		}
	}
	int m,ageL,ageR;
	for(int i=1;i<=k;i++)
	{
		scanf("%d %d %d",&m,&ageL,&ageR);
		printf("Case #%d:\n",i);
		int printnum=0;
		for(int j=0;j<validnum&&printnum<m;j++)
		{
			if(valid[j].age>=ageL&&valid[j].age<=ageR)
			{
				printf("%s %d %d\n",valid[j].name,valid[j].age,valid[j].worth);
				printnum++;
			}
		}
		if(printnum==0)printf("None\n");
		
	}
	return 0;
} 



//³¬Ê±Ëã·¨ 
/*
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

typedef struct people
{
	char name[10];
	int age;
	int worth;
}people;

bool cmp_1(people a,people b)
{
	return a.age<b.age;
}

bool cmp_2(people a,people b)
{
	if(a.worth!=b.worth)return a.worth>b.worth;
	else if(a.age!=b.age)return a.age<b.age;
		else return strcmp(a.name,b.name)<0;
}

people data[100010];

int n,k;

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d %d",data[i].name,&data[i].age,&data[i].worth);
	}
	for(int i=1;i<=k;i++)
	{
		int m,amin,amax,left=-1,right=-1;
		scanf("%d %d %d",&m,&amin,&amax);
		printf("Case #%d:\n",i);
		sort(data,data+n,cmp_1);
		for(int j=0;j<n;j++)
		{
			if(data[j].age>=amin)
			{
				left=j;
				break;
			}
		}
		for(int j=left+1;j<n;j++)
		{
			if(data[j].age<=amax)right=j;
			else break;
		}
		if(left==-1||right==-1)printf("None\n");
		else
		{
			sort(data+left,data+right+1,cmp_2);
			for(int u=left;u<left+min(m,right-left+1);u++)
			{
				printf("%s %d %d\n",data[u].name,data[u].age,data[u].worth);
			}
		}
	}
	return 0;
} 
*/
