
#include<stdio.h>

const int maxn=1010;

double a[maxn]={0},b[maxn]={0},ans[2010]={0};

int main()
{
	int u,v;
	scanf("%d",&u);
	//读入第一个多项式 
	for(int i=0;i<u;i++)
	{
		int ex;
		scanf("%d",&ex);
		scanf("%lf",&a[ex]);
	}
	scanf("%d",&v);
	//读入第二个多项式 
	for(int i=0;i<v;i++)
	{
		int ex;
		scanf("%d",&ex);
		scanf("%lf",&b[ex]);
	}  
	//进行乘法计算 
	for(int i=0;i<maxn;i++)
	{
		if(a[i]==0)continue;
		for(int j=0;j<maxn;j++)
		{
			if(b[j]==0)continue;
			int ex=i+j;
			ans[ex]+=a[i]*b[j];
		}
	}
	//输出 
	int num=0;
	for(int i=0;i<2010;i++)
	{
		if(ans[i]!=0)num++;
	}
	printf("%d",num);
	for(int i=2009;i>=0;i--)
	{
		if(ans[i]!=0)
		{
			printf(" %d %.1f",i,ans[i]);
		}
	}
	return 0;
}
 
