#include<stdio.h>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int n;
map<string,int> strToNum;
string unitdigit[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tendigit[13]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string numToStr[170];

void init()
{	int i,j;
	for(i=0;i<13;i++)
	{
		numToStr[i]=unitdigit[i];
		strToNum[unitdigit[i]]=i;
		numToStr[i*13]=tendigit[i];
		strToNum[tendigit[i]]=i*13;
	}
	for(i=1;i<13;i++)
	{
		for(j=1;j<13;j++)
		{
			string str=tendigit[i]+" "+unitdigit[j];
			numToStr[i*13+j]=str;
			strToNum[str]=i*13+j;
		}
	}
}


int main()
{
	init();
	int i;
	scanf("%d%*c",&n);
	while(n--)
	{
		string str;
		getline(cin,str);
		if(str[0]>='0'&&str[0]<='9')
		{
			int num=0;
			for(i=0;i<str.length();i++)
			{
				num=num*10+(str[i]-'0');
			}
			cout<<numToStr[num]<<endl;
		}
		else
		{
			cout<<strToNum[str]<<endl;
		}
	}
	return 0;
}