#include<stdio.h>
#include<math.h>
#include<stdlib.h>

const int maxn=10010;

int n,k;
int data[maxn]={0};//3=Mystery Award,2=Minion,1=Chocolate,0=Are you kidding?,-1=Checked.

bool isprime(int v)
{
	if(v<=1)return false;
	int sqr=(int)sqrt(v*1.0);
	for(int i=2;i<=sqr;i++)
	{
		if(v%i==0)return false;
	}
	return true;
}

int main()
{
	int id;
	scanf("%d",&n);
	scanf("%d",&id);
	data[id]=3;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&id);
		if(isprime(i)==true)data[id]=2;
		else data[id]=1;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&id);
		if(data[id]==3)
		{
			printf("%04d: Mystery Award\n",id);
			data[id]=-1;
		}
		else if(data[id]==2)
			{
				printf("%04d: Minion\n",id);
				data[id]=-1;
			}
			else if(data[id]==1)
				{
					printf("%04d: Chocolate\n",id);
					data[id]=-1;
				}
				else if(data[id]==0)
				{
					printf("%04d: Are you kidding?\n",id);
				}
				else printf("%04d: Checked\n",id);
	}
	system("pause");
	return 0;
}