#include<stdio.h>
#include<algorithm>

using namespace std;

const int INF=1000000000;

typedef struct node
{
	double price;
	double dis;
}node;

node station[510];
double cmax,d,davg;
int n;

bool cmp(node a,node b)
{
	return a.dis<b.dis;
}



int main()
{
	scanf("%lf %lf %lf %d",&cmax,&d,&davg,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf",&station[i].price,&station[i].dis);	
	}
	sort(station,station+n,cmp);
	station[n].price=0;
	station[n].dis=d;
	//开始贪心
	if(station[0].dis!=0)printf("The maximum travel distance = 0.00\n"); 
	else
	{
		int now=0;
		//花费  满油走最远路 
		double ans=0,max=cmax*davg,nowTank=0;
		while(now<n)
		{
			int u=-1;
			double minPrice=INF;
			for(int i=now+1;i<=n&&((station[i].dis-station[now].dis)<=max);i++)
			{
				if(station[i].price<minPrice)
				{
					u=i;
					minPrice=station[i].price;
					if(minPrice<station[now].price)break;
				}
			} 
			if(u==-1)break;
			double need=(station[u].dis-station[now].dis)/davg;
			if(minPrice<station[now].price)
			{
				if(nowTank<need)
				{
					ans+=(need-nowTank)*station[now].price;
					nowTank=0;
				}
				else nowTank-=need;
			}
			else
			{
				ans+=(cmax-nowTank)*station[now].price;
				nowTank=cmax-need;
			}
			now=u;
		}
		if(now==n)printf("%.2f",ans);
		else printf("The maximum travel distance = %.2f",station[now].dis+max);
	}
	return 0;
}
