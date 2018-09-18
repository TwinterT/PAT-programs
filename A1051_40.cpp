#include<stdio.h>
#include<stack>

using namespace std;

int m,n,k,test[1010];
stack<int> st;

int main()
{
	scanf("%d%d%d",&m,&n,&k);
	for(int i=0;i<k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&test[j]);
		}
		bool tag=true;
		int idx=1;
		while(st.size()>0)st.pop();
		for(int v=1;v<=n;v++)
		{
			if(st.size()<m)st.push(v);
			else 
			{
				tag=false;
				break;
			}
			while(st.size()>0&&st.top()==test[idx])
			{
				st.pop();
				idx++;
			}
		}
		if(st.size()!=0)tag=false;
		if(tag==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
