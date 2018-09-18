#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct node
{
	char name[15];
	char id[15];
	int grade;
}node;

int n;
vector<node> female,male;

bool cmp_1(node a,node b)
{
	return a.grade>b.grade;
}

bool cmp_2(node a,node b)
{
	return a.grade<b.grade;
}

int main()
{	
	node temp;
	char gender;
	scanf("%d ",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %c %s %d",temp.name,&gender,temp.id,&temp.grade);
		if(gender=='F')female.push_back(temp);
		else male.push_back(temp);
	}
	sort(female.begin(),female.end(),cmp_1);
	sort(male.begin(),male.end(),cmp_2);
	if(female.size()==0)
	{
		printf("Absent\n");
	}
	else printf("%s %s\n",female[0].name,female[0].id);
	if(male.size()==0)
	{
		printf("Absent\n");
	}
	else printf("%s %s\n",male[0].name,male[0].id);
	if(female.size()==0||male.size()==0)
	{
		printf("NA\n");
	}
	else printf("%d\n",female[0].grade-male[0].grade);
	return 0;
} 
