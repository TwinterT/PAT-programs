#include<stdio.h>
#include<math.h>

typedef long long LL;

LL n;

int main()
{
	scanf("%lld",&n);
	LL  i,sqr=(LL)sqrt(1.0*n),ans=0,temp=n,idx=0,anslen=0,len=0;;
	for(i=2;i<=sqr;i++)
	{
		idx=i;
		len=0;
		temp=n;
		while(temp%(idx+len)==0)
		{
			temp/=(idx+len);
			len++;
		}
		if(anslen<len)
		{
			ans=idx;
			anslen=len;
		}
	}
	if(anslen==0)printf("1\n%lld",n);
	else 
	{
		printf("%d\n",anslen);
		for(i=0;i<anslen;i++)
		{
			printf("%lld",ans+i);
			if(i!=anslen-1)printf("*");
		}
	}
	return 0;
}
