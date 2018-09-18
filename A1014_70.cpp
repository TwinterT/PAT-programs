#include<stdio.h>
#include<queue>

using namespace std;

const int maxn = 1010;

typedef struct Window
{
	int endTime,popTime;
	queue<int> q;
}Window;

int convertTime(int hour,int min)
{
	return hour*60+min;
}


Window window[20];
int n,m,k,query,q;
int needTime[maxn],ans[maxn];

int main()
{
	int inIndex=0;
	scanf("%d %d %d %d",&n,&m,&k,&query);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&needTime[i]);
	}
	for(int i=0;i<n;i++)
	{
		window[i].endTime=window[i].popTime=convertTime(8,0);
	}
	for(int i=0;i<min(n*m,k);i++)
	{
		window[inIndex%n].q.push(inIndex);
		window[inIndex%n].endTime+=needTime[inIndex];
		if(inIndex<n)window[inIndex%n].popTime+=needTime[inIndex];
		ans[inIndex]=window[inIndex%n].endTime;
		inIndex++;
	}
	for(;inIndex<k;inIndex++)
	{
		int idx=-1,minpopTime=1<<30;
		for(int i=0;i<n;i++)
		{
			if(window[i].popTime<minpopTime)
			{
				idx=i;
				minpopTime=window[i].popTime;
			}
		}
		window[idx].q.pop();
		window[idx].q.push(inIndex);
		window[idx].endTime+=needTime[inIndex];
		window[idx].popTime+=needTime[window[idx].q.front()];
		ans[inIndex]=window[idx].endTime;		
	}
	for(int i=0;i<query;i++)
	{
		scanf("%d",&q);
		if(ans[q-1]-needTime[q-1]>=convertTime(17,0))printf("Sorry\n");
		else printf("%02d:%02d\n",ans[q-1]/60,ans[q-1]%60);
	}
	return 0;
}
