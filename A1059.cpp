#include<stdio.h>
#include<math.h>

const int maxn=1000000;
int Prim[maxn],num=0;

typedef struct fact
{
	int a,b;	
}fact;

bool Is_Prim(int n)
{
	if(n==1)return false;
	for(int i=2;i<=(int)sqrt(n*1.0);i++)
	{
		if(n%i==0)return false;	
	}
	return true;
}

void Get_Prim()
{
	for(int i=2;i<maxn;i++)
	{
		if(Is_Prim)
		{
			Prim[num++]=i;
		}
	}
}

int main()
{	
	Get_Prim();
	int n,sum=0,sqr=(int)sqrt(n*1.0);
	fact f[10];
	scanf("%d",&n);
	if(n==1)printf("1=1\n");
	else
	{
		printf("%d=",n);
		for(int i=0;i<num&&Prim[i]<sqr;i++)
		{
			if(n%Prim[i]==0)
			{
				f[sum].a=Prim[i];
				f[sum].b=0;
				while(n%Prim[i]==0)
				{
					f[sum].b++;
					n=n/Prim[i];
				}
				sum++;
			}
			if(n==1)break;
		}
		if(n!=1)
		{
			f[sum].a=n;
			f[sum++].b=1;
		}
		for(int i=0;i<sum;i++)
		{
			if(i>0)printf("*");
			printf("%d",f[i].a);
			if(f[i].b>1)printf("^%d",f[i].b);
		}
	}
	return 0;
}
