#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long LL;

const int maxn=100010;

int nc,np;
LL coupon[maxn],product[maxn];

bool cmp(LL a,LL b)
{
	return a>b;
}

int main()
{
	scanf("%d",&nc);
	for(int i=0;i<nc;i++)
	{
		scanf("%lld",&coupon[i]);
	}
	scanf("%d",&np);
	for(int i=0;i<np;i++)
	{
		scanf("%lld",&product[i]);
	}
	sort(coupon,coupon+nc,cmp);
	sort(product,product+np,cmp);
	int fc=0,fp=0,ec=nc-1,ep=np-1;
	LL ans=0;
	while(fc<nc&&fp<np)
	{
		if(coupon[fc]<0||product[fp]<0)break;
		else ans+=coupon[fc++]*product[fp++];
	}
	while(ec>=fc&&ep>=fp)
	{
		if(coupon[ec]>0||product[ep]>0)break;
		else ans+=coupon[ec--]*product[ep--];
	}
	printf("%d\n",ans);
	return 0;
}
