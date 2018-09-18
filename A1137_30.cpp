#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=10010;

typedef struct node
{
	string id;
	int point;
	double mid;
	double final;
	int g;
	node()
	{
		point=-1;
		mid=-1;
		final=-1;
		g=-1;
	}
}node;

map<string,int> mp;
node data[maxn];
int p,m,n,num=0;

bool cmp(node a,node b)
{
	if(a.g!=b.g)return a.g>b.g;
	else return a.id<b.id;
}

void print()
{
	for(int i=0;i<p;i++)
	{
		if(data[i].g<60)break;
		cout<<data[i].id<<" "<<data[i].point<<" "<<data[i].mid<<" "<<data[i].final<<" "<<data[i].g<<endl;
	}
}

int main()
{
	scanf("%d %d %d",&p,&m,&n);
	for(int i=0;i<p;i++)
	{
		string id;
		int point;
		cin>>id>>point;
		if(point>=200)
		{
			data[num].point=point;
			data[num].id=id;
			mp[id]=num;
			num++;
		}
	}
	for(int i=0;i<m;i++)
	{
		string id;
		double mid;
		cin>>id>>mid;
		if(mp.find(id)!=mp.end())
		{
			data[mp[id]].mid=mid;
		}
	}
	for(int i=0;i<n;i++)
	{
		string id;
		double final;
		cin>>id>>final;
		if(mp.find(id)!=mp.end())
		{
			data[mp[id]].final=final;
		}
	}
	for(int i=0;i<p;i++)
	{
		if(data[i].mid!=-1||data[i].final!=-1)
		{
			if(data[i].mid>data[i].final)
			{
				if(data[i].final==-1)data[i].g=(int)(data[i].mid*0.4+0.5);
				else data[i].g=(int)(data[i].mid*0.4+data[i].final*0.6+0.5);
			}
			else data[i].g=data[i].final;
		}
	}
	sort(data,data+num,cmp);
	print();
	system("pause");
	return 0;
}