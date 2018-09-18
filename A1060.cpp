#include<iostream>
#include<string>

using namespace std;

int n;

string deal(string str , int &e)
{
	while(str.length()>0&&str[0]=='0')
	{
		str.erase(str.begin());
	}
	if(str[0]=='.')
	{
		str.erase(str.begin());
		while(str.length()>0&&str[0]=='0')
		{
			str.erase(str.begin());
			e--;
		} 
	}
	else
	{
		int k=0;
		while(k<str.length()&&str[k]!='.')
		{
			e++;
			k++;
		}
	}
	if(str.length()==0)e=0;
	string ans;
	for(int i=0;i<n;i++)
	{
		if(i<str.length())ans+=str[i];
		else ans+='0';
	}
	return ans;
}

int main()
{
	string s1,s2,s3,s4;
	int e1=0,e2=0;
	cin>>n>>s1>>s2;
	s3=deal(s1,e1);
	s4=deal(s2,e2);
	if(s3==s4)cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
	else cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;	
	return 0;
} 
