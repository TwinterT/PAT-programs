#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

typedef struct number
{
	string str;
	int exp;
}number;

string a,b;
int n;
 
number turn(string k)
{
	number ans;
	ans.exp=0;
	while(k.size()>0&&k[0]=='0')
	{
		k.erase(k.begin());
	}
	if(k[0]=='.')
	{
		k.erase(k.begin());
		while(k.size()>0&&k[0]=='0')
		{
			k.erase(k.begin());
			ans.exp--;
		}
	}
	else 
	{
		int temp=0;
		while(temp<k.size()&&k[temp]!='.')
		{
			temp++;
			ans.exp++;
		}
		if(k.size()>0&&k[temp]=='.')k.erase(k.begin()+temp);
	}
	if(k.size()==0)ans.exp=0;
	for(int i=0;i<n;i++)
	{
		if(i<k.size())ans.str+=k[i];
		else ans.str+='0';
	}
	return ans;
}
 
 
int main()
{
	scanf("%d",&n);
	cin>>a>>b;
	number u=turn(a);
	number v=turn(b);
	if(u.str==v.str&&u.exp==v.exp)cout<<"YES 0."<<u.str<<"*10^"<<u.exp<<endl;
	else cout<<"NO 0."<<u.str<<"*10^"<<u.exp<<" 0."<<v.str<<"*10^"<<v.exp<<endl;
	return 0;
} 
