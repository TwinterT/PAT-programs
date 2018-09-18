#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct node
{
	double t_price;
	double weight;
	double pri;
}node;

node data[1010];
double d;
int n;

bool cmp(node a,node b)
{
	return a.pri>b.pri;
}

int main()
{
	scanf("%d %lf",&n,&d);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&data[i].weight);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&data[i].t_price);
		data[i].pri=data[i].t_price/data[i].weight;
	}
	sort(data,data+n,cmp);
	double ans=0;
	for(int i=0;i<n;i++)
	{
		if(d>=data[i].weight)
		{
			ans+=data[i].t_price;
			d-=data[i].weight;
		}
		else
		{
			ans+=data[i].pri*d;
			break;
		}
	}
	printf("%.2f",ans);
	return 0;
} 
