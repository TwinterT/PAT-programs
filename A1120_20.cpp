#include<stdio.h>
#include<stdlib.h>
#include<set>

using namespace std;

int n;
set<int> st;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int key,sum=0;
		scanf("%d",&key);
		while(key!=0)
		{
			sum+=key%10;
			key/=10;
		}
		st.insert(sum);
	}
	printf("%d\n",st.size());
	for(set<int>::iterator it=st.begin();it!=st.end();it++)
	{
		if(it==st.begin())printf("%d",*it);
		else printf(" %d",*it);
	}
	printf("\n");
	system("pause");
	return 0;
}