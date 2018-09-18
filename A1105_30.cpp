#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

const int INF = 1000000000;
const int maxn=10010;
int N,m,n;
int data[maxn],matrix[maxn][maxn];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&data[i]);
	}
	int sqr=(int)sqrt(N*1.0),min=INF;
	for(int i=1;i<=sqr;i++)
	{
		if(N%i==0&&(N/i-i)<min)
		{
			n=i;
			m=N/i;
			min=m-n;
		}
	}
	if(N==1)
	{
		printf("%d",data[0]);
		return 0;
	}
	sort(data,data+N,cmp);
	int i=1,j=1,now=0;
	int U=1,D=m,L=1,R=n;
	while(now<N)
	{
		while(now<N&&j<R)
		{
			matrix[i][j]=data[now++];
			j++;
		}
		while(now<N&&i<D)
		{
			matrix[i][j]=data[now++];
			i++;
		}
		while(now<N&&j>L)
		{
			matrix[i][j]=data[now++];
			j--;
		}
		while(now<N&&i>U)
		{
			matrix[i][j]=data[now++];
			i--;
		}
		U++,D--,L++,R--;
		i++,j++;
		if(now==N-1)
		{
			matrix[i][j]=data[now++];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d",matrix[i][j]);
			if(j!=n)printf(" ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}