#include<stdio.h> 
#include<string>
#include<iostream>
#include<string.h>

using namespace std;

bool vis[300];
string a,b;

int main()
{
	memset(vis,true,sizeof(vis));
	getline(cin,a);
	getline(cin,b);	
	int u=a.size();
	int v=b.size();
	for(int i=0;i<v;i++)
	{
		vis[b[i]]=false;
	}
	for(int i=0;i<u;i++)
	{
		if(vis[a[i]]==true)printf("%c",a[i]);
	}
	return 0;
}
