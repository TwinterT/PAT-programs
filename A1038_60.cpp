#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<string>  data;
int n;

void print()
{
	string ans;
	for(int i=0;i<data.size();i++)
	{
		ans+=data[i];
	}
	while(ans.size()!=0&&ans[0]=='0')
	{
		ans.erase(ans.begin()); 
	}
	if(ans.size()==0)printf("0");
	else cout<<ans;
}

bool cmp(string a,string b)
{
	return (a+b)<(b+a); 
}

int main()
{
	string temp;
	scanf("%d ",&n);
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		data.push_back(temp);
	}
	sort(data.begin(),data.end(),cmp);
	print(); 
	return 0;
}
