#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int n,k;
char stu[40010][5];
vector<int> course[2510];

bool cmp(int a,int b)
{
	return strcmp(stu[a],stu[b])<0;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%s %d",stu[i],&num);
		for(int j=0;j<num;j++)
		{
			int temp;
			scanf("%d",&temp);
			course[temp].push_back(i);
		} 	
	}
	for(int i=1;i<=k;i++)
	{
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(int j=0;j<course[i].size();j++)
		{
			printf("%s\n",stu[course[i][j]]);
		}
	}
	return 0;
} 
