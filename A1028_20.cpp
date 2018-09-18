#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

typedef struct student
{
	int id;
	char name[10];
	int grade;
}student;

int n,c;
student stu[100010];

bool cmp_id(student a,student b)
{
	return a.id<b.id;
}

bool cmp_name(student a,student b)
{
	if(strcmp(a.name,b.name))return strcmp(a.name,b.name)<0;
	else return a.id<b.id;
}

bool cmp_grade(student a,student b)
{
	if(a.grade!=b.grade)return a.grade<b.grade;
	else return a.id<b.id;
}

void print()
{
	for(int i=0;i<n;i++)
	{
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
}

int main()
{
	scanf("%d %d",&n,&c);
	for(int i=0;i<n;i++)
	{
		scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].grade);
	}
	if(c==1)sort(stu,stu+n,cmp_id);
	else if(c==2)sort(stu,stu+n,cmp_name);
		else sort(stu,stu+n,cmp_grade);
	print();
	return 0;
} 
