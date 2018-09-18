#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

priority_queue<double,vector<double>,greater<double> > q;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		double data;
		scanf("%lf",&data);
		q.push(data);
	}
	while(q.size()>1)
	{
		double u=q.top();
		q.pop();
		double v=q.top();
		q.pop();
		q.push((u+v)/2);
	}
	printf("%d",(int)q.top());
	system("pause");
	return 0;
}