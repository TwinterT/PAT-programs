#include<stdio.h>
#include<map>
#include<string>
#include<iostream>

using namespace std;

map<string,int> mp;

bool judge(char c)
{
	if(c>='0'&&c<='9')return true;
	if(c>='A'&&c<='Z')return true;
	if(c>='a'&&c<='z')return true;
	return false;
}

int main()
{
	string str;
	getline(cin,str);
	int i=0;
	while(i<str.length())
	{
		string word;
		while(i<str.length()&&judge(str[i])==true)
		{
			if(str[i]>='A'&&str[i]<='Z')
			{
				str[i]+=32;
			}
			word+=str[i];
			i++;
		}
		if(word!="")
		{
			if(mp.find(word)==mp.end())mp[word]=1;
			else mp[word]++;
		}
		while(i<str.length()&&judge(str[i])==false)
		{
			i++;
		}
	}int max=0;
	string ans; 
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>max)
		{
			max=it->second;
			ans=it->first;
		}
	}
	cout<<ans<<" "<<max<<endl;
	return 0;
}


/*
#include<stdio.h>
#include<map>
#include<string>
#include<iostream>

using namespace std;

map<string,int> mp;

bool judge(char c)
{
	if(c>='0'&&c<='9')return true;
	if(c>='A'&&c<='Z')return true;
	if(c>='a'&&c<='z')return true;
	return false;
}

int main()
{
	string str,temp;
	getline(cin,str);	
	for(int i=0;i<str.length();i++)
	{
		if(judge(str[i])==true)
		{
			if(str[i]>='A'&&str[i]<='Z')
			{
				char c=str[i]+32;
				temp+=c;
			}
			else temp+=str[i];
		}
		else 
		{
			if(temp.size()!=0)
			{
				if(mp.find(temp)!=mp.end())mp[temp]++;
				else mp[temp]=1;
				temp.clear();
			}
		}	
	}
	int max=0;
	string ans; 
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>max)
		{
			max=it->second;
			ans=it->first;
		}
	}
	cout<<ans<<" "<<max<<endl;
	return 0;
} 
*/
