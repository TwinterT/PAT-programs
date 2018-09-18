#include<stdio.h>

int n;
double v;

int main()
{
	double ans=0;
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&v);
		ans+=i*(n+1-i)*v;
	}
	printf("%.2f\n",ans);
	return 0;
}