#include<stdio.h>
#include<string.h>
#include<map>

using namespace std;

char a[65],b[65],c[65],d[65];
char  mp[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
map<char,int> mpt;
int main()
{
	for(int i=0;i<10;i++)
	{
		mpt['0'+i]=i;
	}
	for(int i=0;i<14;i++)
	{
		mpt['A'+i]=i+10;
	}
	scanf("%s\n%s\n%s\n%s",a,b,c,d);
	int len_a=strlen(a),len_b=strlen(b),len_c=strlen(c),len_d=strlen(d);
	int i; 
	for(i=0;i<len_a&&i<len_b;i++)
	{
			if(a[i]<='G'&&a[i]>='A'&&a[i]==b[i])
			{
				printf("%s ",mp[a[i]-'A']);
				break;
			}		
	}
	for(i=i+1;i<len_a&&i<len_b;i++)
	{
		if(a[i]==b[i]&&((a[i]<='N'&&a[i]>='A')||(a[i]<='9'&&a[i]>='0')))
		{
			printf("%02d:",mpt[a[i]]);
			break;
		}	
	}
	for(int j=0;j<len_c&&j<len_d;j++)
	{
		if((c[j]<='z'&&c[j]>='a')||(c[j]<='Z'&&c[j]>='A'))
		{
			if(c[j]==d[j])
			{
				printf("%02d",j);
				break;	
			}
		}
		
	}
	return 0;
} 
