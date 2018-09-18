#include<stdio.h>
#include<iostream>
#include<map>
#include<string>

using namespace std;

const int maxn = 2000;
map<string,int> STI;
map<int,string>	ITS;
map<string,int>	Gang;
int G[maxn][maxn]={0},weight[maxn]={0},number=0;
int n,k;
bool vis[maxn]={false};

int change(string str)
{
	if(STI.find(str)!=STI.end())
	{
		return STI[str];
	}
	else
	{
		STI[str]=number;
		ITS[number]=str;
		return number++;
	}
}

void DSF(int index,int& head,int& memnum,int& total)
{
	memnum++;
	vis[index]=true;
	if(weight[index]>weight[head])
	{
		head=index;
	}
	for(int i=0;i<number;i++)
	{
		if(G[index][i]>0)
		{
			total+=G[index][i];
			G[index][i]=G[i][index]=0;
			if(vis[i]==false)
			{
				DSF(i,head,memnum,total);
			}
		}
	}
}
 
 void DSFTravel()
 {
 	for(int i=0;i<number;i++)
 	{
 		if(vis[i]==false)
 		{
 			int head=i,memnum=0,total=0;
 			DSF(i,head,memnum,total);
 			if(memnum>2&&total>k)
 			{
 				Gang[ITS[head]]=memnum;
 			}
 		}
 	}
 }


int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int w;
		string temp1,temp2;
		cin>>temp1>>temp2>>w;
		int v1=change(temp1);
		int v2=change(temp2);
		G[v1][v2]+=w;
		G[v2][v1]+=w;
		weight[v1]+=w;
		weight[v2]+=w;
	}
	DSFTravel();
	printf("%d\n",Gang.size());
	for(map<string,int>::iterator it=Gang.begin();it!=Gang.end();it++)
	{
		cout<<it->first<<' '<<it->second<<endl;
	} 
	return 0;
} 
