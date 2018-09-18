#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int m,n,s;
string member[1010];
map<string,bool> mp;

int main()
{
	scanf("%d %d %d",&m,&n,&s);
	for(int i=1;i<=m;i++)
	{
		cin>>member[i];
	}
	if(m<s)printf("Keep going...\n");
	else
	{
		for(int i=s;i<=m;)
		{
			if(mp.find(member[i])==mp.end())
			{
				cout<<member[i]<<endl;
				mp[member[i]]=true;
				i+=n;
			}
			else i++;
		}
	}
	system("pause");
	return 0;
}