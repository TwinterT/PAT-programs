#include<stdio.h>
#include<math.h>
#include<string.h>

int Msize,n;
int Hash[10010];

bool Is_prime(int k)
{
	if(k<=1)return false;
	bool tag=true;
	int sqr=(int)sqrt(k*1.0);
	for(int i=2;i<=sqr;i++)
	{
		if(k%i==0)tag=false;
	}
	return tag;
}


int main()
{
	int temp,num,pos,tank=0;
	scanf("%d %d",&Msize,&n);
	memset(Hash,-1,sizeof(Hash));
	while(!Is_prime(Msize))
	{	
		Msize++;
	}
	for(int i=0;i<n;i++)
	{
		pos=-1;
		scanf("%d",&num);
		if(Hash[num%Msize]==-1)
		{
			Hash[num%Msize]=num;
			pos=num%Msize;
		}
		else
		{
			int step;
			for(step=1;step<Msize;step++)
			{
				int M=(num+step*step)%Msize;
				if(Hash[M]==-1)
				{
					pos=M;
					Hash[M]=num;
					break;
				}
			}
		}
		if(pos!=-1)printf("%d",pos);
		else printf("-");
		if(i!=n-1)printf(" ");
	}
	return 0;
}