#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

const int INF=1000000000;
const int maxn=1050;

int n,m,k,ds;
int G[maxn][maxn],d[maxn];
bool vis[maxn]={false};


int turn(char t[])
{
	int i=0,len=strlen(t),ID=0;
	while(i<len)
	{
		if(t[i]!='G')
		{
			ID=ID*10+(t[i]-'0');
		}
		i++;
	}
	if(t[0]=='G')return n+ID;
	else return ID;
}

void dijkstra(int k)
{
	fill(d,d+maxn,INF);
	memset(vis,false,sizeof(vis));
	d[k]=0;
	for(int i=0;i<n+m;i++)
	{
		int u=-1,min=INF;
		for(int j=1;j<=n+m;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				min=d[j];
				u=j;
			}
		}
		if(u==-1)return;
		vis[u]=true;
		for(int v=1;v<=n+m;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v])
			{
				d[v]=d[u]+G[u][v];
			}
		} 
	}
}

int main()
{
	scanf("%d %d %d %d",&n,&m,&k,&ds);
	fill(G[0],G[0]+maxn*maxn,INF);
	int u,v,w;
	char temp_1[6],temp_2[6];
	for(int i=0;i<k;i++)
	{	
		scanf("%s %s %d",temp_1,temp_2,&w);
		u=turn(temp_1);
		v=turn(temp_2);
		G[u][v]=G[v][u]=w;
	}
	double ansDis=-1,ansAvg=INF;
	int ansID=-1;
	for(int i=n+1;i<=n+m;i++)
	{
		double minDis=INF,avg=0;
		dijkstra(i);
		for(int j=1;j<=n;j++)
		{
			if(d[j]>ds)
			{
				minDis=-1;
				break;
			}
			if(d[j]<minDis)minDis=d[j];
			avg+=1.0*d[j]/n;
		}
		if(minDis==-1)continue;
		if(minDis>ansDis)
		{
			ansID=i;
			ansDis=minDis;
			ansAvg=avg; 
		}
		else if(minDis==ansDis&&avg<ansAvg)
		{
			ansID=i;
			ansAvg=avg;
		}
	}
	if(ansID==-1)printf("No Solution\n");
	else
	{
		printf("G%d\n",ansID-n);
		printf("%.1f %.1f\n",ansDis,ansAvg);
	}
	return 0;
} 
