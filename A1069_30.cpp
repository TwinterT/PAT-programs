#include<stdio.h>
#include<algorithm>

using namespace std;

bool cmp_down(int a,int b)
{
	return a>b;
}

bool cmp_up(int a,int b)
{
	return a<b;
}

void turn_int(int n[],int num)
{
	for(int i=0;i<4;i++)
	{
		n[i]=num%10;
		num=num/10;
	}
}

int turn_num(int n[])
{
	int ans=0;
	for(int i=0;i<4;i++)
	{
		ans=ans*10+n[i];
	}
	return ans;
}

int main()
{
	int num,n[4],a,b;
	scanf("%d",&num);
	turn_int(n,num);
	sort(n,n+4,cmp_down);
	a=turn_num(n);
	sort(n,n+4,cmp_up);
	b=turn_num(n);
	if(a==b)printf("%04d - %04d = 0000\n",a,b);
	else 
	{
		int c=a-b;
		while(c!=6174)
		{
			printf("%04d - %04d = %04d\n",a,b,c);
			turn_int(n,c);
			sort(n,n+4,cmp_down);
			a=turn_num(n);
			sort(n,n+4,cmp_up);
			b=turn_num(n);
			c=a-b;
		}
		printf("%04d - %04d = %04d\n",a,b,c);
	}
	return 0;
} 
