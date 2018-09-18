#include<stdio.h>

int n;

int main()
{
	scanf("%d",&n);
	int k=1,left,right,now,ans=0;
	while(n/k!=0)
	{
		now=n/k%10;
		left=n/(k*10);
		right=n%k;
		if(now==0)ans+=left*k;
		else if(now==1)ans+=left*k+right+1;
			else ans+=(left+1)*k;
		k*=10;
	} 
	printf("%d\n",ans);
	return 0;
} 
