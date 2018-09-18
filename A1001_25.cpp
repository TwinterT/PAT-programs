#include<stdio.h>
#include<vector>
#include<math.h>
#include<stack>

using namespace std;

typedef struct node
{
	bool tag;
	vector<int> num;
}node;

node Get_result(int res)
{
	node ans;
	if(res<0)ans.tag=false;
	else ans.tag=true;
	res=fabs(res*1.0);
	if(res==0)ans.num.push_back(0);
	while(res>0)
	{
		ans.num.push_back(res%10);
		res=res/10;
	}
	return ans;
}

void print_result(node ans)
{
	if(ans.tag==false)printf("-");
	int s=ans.num.size();
	for(int i=s-1;i>=0;i--)
	{
		printf("%d",ans.num[i]);
		if(i%3==0&&i!=0)printf(",");
	}
	return;
}

int main()
{
	int a,b,res;
	scanf("%d%d",&a,&b);
	res=a+b;
	node ans=Get_result(res);
	print_result(ans);	
	return 0;
}
