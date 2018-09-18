#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

int n;

bool isnum(string str)
{
	if(str[0]=='-')
	{
		str.erase(str.begin());
	}
	if(str.length()==0)return false;
	int pos=-1;
	for(int i=0;i<str.length();i++)
	{
		if(!(str[i]=='.'||(str[i]>='0'&&str[i]<='9')))return false;
		if(str[i]=='.')
		{
			if(pos==-1)pos=i;
			else return false;
		}
		
	}
	if(pos!=-1&&str.length()-1-pos>2)return false;
	double temp;
	sscanf(str.c_str(),"%lf",&temp);
	return temp<=1000;
}



int main()
{
	double ans=0,number;
	string temp;
	int num=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(isnum(temp))
		{
			sscanf(temp.c_str(),"%lf",&number);
			ans+=number;
			num++;
		}
		else 
		{
			printf("ERROR: %s is not a legal number\n",temp.c_str());
		}
	}
	if(num==0)printf("The average of 0 numbers is Undefined\n");
	else if(num==1)printf("The average of 1 number is %.2f\n",ans);
		else 
		{
			printf("The average of %d numbers is %.2f\n",num,ans/num);
		}
	system("pause");
	return 0;
}