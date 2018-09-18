#include<stdio.h>
#include<algorithm>

using namespace std;

int n,num[100010];

int main()
{
	int ans=0;
	scanf("%d",&n);
	int left=n-1;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		num[temp]=i;
		if(temp==i&&temp!=0)left--;
	}
	int k=1;
	while(left>0)
	{
		if(num[0]==0)
		{
			while(k<n)
			{
				if(num[k]!=k)
				{
					swap(num[0],num[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while(num[0]!=0)
		{
			swap(num[0],num[num[0]]);
			ans++;
			left--;
		}
	}
	printf("%d\n",ans); 
	return 0;
} 
