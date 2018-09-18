#include<stdio.h>
#include<math.h>

typedef long long LL;

typedef struct number
{
	bool tag;
	LL up;
	LL down;
	LL inte;
	number()
	{
		tag=true;
		inte=0;
	}
}number;

LL get(LL a,LL b)
{
	if(b==0)return a;
	else get(b,a%b);
}

number simple(number &a)
{
	
	if(a.down<0)
	{
		a.up=-a.up;
		a.down=-a.down;
	}
	if(a.up<0)
	{
		a.tag=false;
		a.up=-a.up;
	}
	if(a.up>a.down)
	{
		a.inte=a.up/a.down;
		a.up=a.up%a.down;
		if(a.up==0)a.down=1;
	}
	LL temp=get(abs(a.down),abs(a.up));
	a.down/=temp;
	a.up/=temp;
	return a;
}

void print(number a)
{
	if(a.tag==false)
	{
		printf("(-");
		if(a.up==0)printf("%lld",a.inte);
		else 
		{
			if(a.inte!=0)printf("%lld ",a.inte);
			printf("%lld/%lld",a.up,a.down);
		}
		printf(")");
	}
	else
	{
		if(a.up==0)printf("%lld",a.inte);
		else 
		{
			if(a.inte!=0)printf("%lld ",a.inte);
			printf("%lld/%lld",a.up,a.down);
		}
	}
}

void sum(number a,number b)
{
	number ans;
	LL up_a,up_b;
	up_a=(a.inte*a.down+a.up)*b.down;
	up_b=(b.inte*b.down+b.up)*a.down;
	if(a.tag==false)up_a=-up_a;
	if(b.tag==false)up_b=-up_b;
	ans.up=up_a+up_b;
	ans.down=a.down*b.down;
	simple(ans);
	print(ans);
}

void difference(number a,number b)
{
	if(b.tag==true)b.tag=false;
	else b.tag=true;
	sum(a,b);
}

void  product(number a,number b)
{
	number ans;
	if((a.tag==true&&b.tag==true)||(a.tag==false&&b.tag==false))ans.tag=true;
	else ans.tag=false;
	LL up_a,up_b;
	up_a=a.inte*a.down+a.up;
	up_b=b.inte*b.down+b.up;
	ans.up=up_a*up_b;
	ans.down=a.down*b.down;
	simple(ans);
	print(ans);
}

void quotient(number a,number b)
{
	if(b.inte==0&&b.up==0)printf("Inf");
	else 
	{
		LL up=b.inte*b.down+b.up;
		b.up=b.down;
		b.down=up;
		b.inte=0;
		simple(b);
		product(a,b);
	}
}

int main()
{
	number a,b;
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
	simple(a);
	simple(b);
	print(a);
	printf(" + ");
	print(b);
	printf(" = ");
	sum(a,b);
	printf("\n");
	print(a);
	printf(" - ");
	print(b);
	printf(" = ");
	difference(a,b);
	printf("\n");
	print(a);
	printf(" * ");
	print(b);
	printf(" = ");
	product(a,b);
	printf("\n");
	print(a);
	printf(" / ");
	print(b);
	printf(" = ");
	quotient(a,b);
	return 0;
}