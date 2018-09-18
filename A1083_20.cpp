#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct sturdent
{
	char name[12],id[12];
	int grade;
}student;

vector<student> stu;

bool cmp(student a,student b)
{
	return a.grade>b.grade;
}

int main()
{
	student temp;
	int n,i,up,down;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %s %d\n",temp.name,temp.id,&temp.grade);
		stu.push_back(temp);
	}
	scanf("%d %d",&down,&up);
	sort(stu.begin(),stu.end(),cmp);
	int ans=0;
	for(i=0;i<n;i++)
	{
		if(stu[i].grade<down)break;
		else	if(stu[i].grade<=up&&stu[i].grade>=down)
			{
				printf("%s %s\n",stu[i].name,stu[i].id);
				ans++;
			}
	}
	if(ans==0)printf("NONE\n");
	return 0;              
}