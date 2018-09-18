#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

typedef struct student
{
	char id[15];//准考证号 
	int score;//分数 
	int rank;//考场内排名 
	int local;//考场号 
	
}student;

bool cmp(student stu1,student stu2)
{
	if(stu1.score!=stu2.score)return stu1.score>stu2.score;
	else return strcmp(stu1.id,stu2.id)<0;
} 

int  main()
{
	student stu[30010];
	int k,n,num=0,temp=1;
	scanf("%d",&k);//输入考场个数
	for(int i=0;i<k;i++)
	{
		scanf("%d",&n);//输入考场人数
		for(int j=0;j<n;j++)
		{
			scanf("%s %d",&stu[num].id,&stu[num].score);
			stu[num].local=temp;
			num++;
		}
		temp++;
		sort(stu+num-n,stu+num,cmp);
		stu[num-n].rank=1;
		for(int k=num-n+1;k<num;k++)
		{
			if(stu[k].score==stu[k-1].score)stu[k].rank=stu[k-1].rank;
			else 
			{
				stu[k].rank=k-num+n+1;
			}
		}			
	} 
	printf("%d\n",num);
	sort(stu,stu+num,cmp);
	int r=1;
	printf("%s %d %d %d\n",stu[0].id,r,stu[0].local,stu[0].rank); 
	for(int i=1;i<num;i++)
	{
		printf("%s ",stu[i].id);
		if(stu[i].score==stu[i-1].score)printf("%d ",r);
		else
		{
			r=i+1;
			printf("%d ",r);
		}
		printf("%d %d\n",stu[i].local,stu[i].rank);
	}
	return 0;
}
