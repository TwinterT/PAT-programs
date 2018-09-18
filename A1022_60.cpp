#include<stdio.h>
#include<map>
#include<set>
#include<string>
#include<iostream>

using namespace std;

map<string,set<int> >  mpTitle,mpAuthor,mpKey,mpPub,mpYear;
int n,m;

void query(map<string,set<int> > &mp,string &str)
{
	if(mp.find(str)==mp.end())printf("Not Found\n");
	else
	{
		for(set<int>::iterator it=mp[str].begin();it!=mp[str].end();it++)
		{
			printf("%07d\n",*it);
		}
	}
}

int main()
{	
	int id,k;
	string title,author,key,pub,year;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{	
		scanf("%d",&id);
		char c=getchar();
		getline(cin,title);
		mpTitle[title].insert(id);
		getline(cin,author);
		mpAuthor[author].insert(id);
		while(cin>>key)
		{
			mpKey[key].insert(id);
			c=getchar();
			if(c=='\n')break;
		}
		getline(cin,pub);
		mpPub[pub].insert(id);
		getline(cin,year);
		mpYear[year].insert(id);
	}
	string temp;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d: ",&k);
		getline(cin,temp);
		cout<<k<<": "<<temp<<endl;
		if(k==1)query(mpTitle,temp);
		else if(k==2)query(mpAuthor,temp);
		else if(k==3)query(mpKey,temp);
		else if(k==4)query(mpPub,temp);
		else query(mpYear,temp);
	}
	return 0;
} 
