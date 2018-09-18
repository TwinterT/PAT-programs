#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

string str;

bool symmetric(string a)
{
	int len=a.size();
	for(int i=0;i<=len/2;i++)
	{
		if(a[i]!=a[len-i-1])return false;
	}
	return true;
}

int main()
{
	getline(cin,str);
	int len = str.size();
	int max_ans=1;
	for(int i=0;i<len;i++)
	{
		for(int j=len-1;j>=i;j--)
		{
			string temp=str.substr(i,j-i+1);
			if(symmetric(temp)&&max_ans<temp.size())max_ans=temp.size();
		}
	}
	printf("%d",max_ans);
	return 0;
} 
