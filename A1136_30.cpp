#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

const int maxn=10000;

string n;

bool judge(string num)
{
	int len=num.length();
	for(int i=0;i<=(len-1)/2;i++)
	{
		if(num[i]!=num[len-1-i])return false;
	}
	return true;
}

string num_sum(string a,string b)
{
	int carry=0;
	int i=a.length()-1,j=b.length()-1;
	for(;i>=0&&j>=0;i--,j--)
	{
		int sum=(a[i]-'0')+(b[j]-'0')+carry;
		carry=sum/10;
		if(sum>=10)sum%=10;
		
		a[i]='0'+sum;
	}
	
	if(carry!=0)
	{
		a.insert(a.begin(),'1');
	}
	return a;
}


int main()
{
	cin>>n;
	int times=0;
	while(!judge(n)&&times<10)
	{
		string re_n=n;
		reverse(re_n.begin(),re_n.end());
		cout<<n<<" + "<<re_n<<" = ";
		n=num_sum(n,re_n);
		cout<<n<<endl;
		times++;
	}
	if(times<10)cout<<n<<" is a palindromic number."<<endl;
	else printf("Not found in 10 iterations.\n");
	system("pause");
	return 0;
}