#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

typedef long long LL;

typedef struct num
{
	LL numerator;//·Ö×Ó
	LL denominator;
}num;

int n;

LL min(LL a,LL b)
{
	if(a<b)return a;
	else return b;
}

LL max(LL a,LL b)
{
	if(a>b)return a;
	else return b;
}

LL get(LL a,LL b)
{
	if(b==0)return a;
	else get(b,a%b);
}

void down(num &a)
{
	if(a.denominator<0)
	{
		a.denominator=-a.denominator;
		a.numerator=-a.numerator;
	}
	if(a.numerator==0)a.denominator=1;
	else
	{
		LL k=get(max(abs(a.denominator),abs(a.numerator)),min(abs(a.denominator),abs(a.numerator)));
		a.denominator/=k;
		a.numerator/=k;
	}
}

num sum(num a,num b)
{
	num ans;
	ans.numerator=a.numerator*b.denominator+b.numerator*a.denominator;
	ans.denominator=a.denominator*b.denominator;
	down(ans);
	return ans;
}

int main()
{
	num A,B;
	scanf("%d",&n);
	scanf("%lld/%lld",&A.numerator,&A.denominator);
	for(int i=1;i<n;i++)
	{
		scanf("%lld/%lld",&B.numerator,&B.denominator);
		A=sum(A,B);
		
	}
	if(A.denominator==1)printf("%lld\n",A.numerator);
	else if(abs(A.numerator)>abs(A.denominator))
	{
		printf("%lld %lld/%lld\n",A.numerator/A.denominator,abs(A.numerator)%A.denominator,A.denominator);
	}
	else printf("%lld/%lld\n",A.numerator,A.denominator);
}
