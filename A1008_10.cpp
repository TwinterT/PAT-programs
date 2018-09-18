#include<stdio.h>
#include<vector>

using namespace std;

int total=0,n,now_f=0;
vector<int> floor;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		floor.push_back(temp);
	}
	for(int i=0;i<n;i++)
	{
		if(floor[i]>=now_f)
		{
			total=total+(floor[i]-now_f)*6+5;
			now_f=floor[i];
		}
		else
		{
			total=total+(now_f-floor[i])*4+5;
			now_f=floor[i];
		}
	}
	printf("%d",total);
	return 0;
} 
