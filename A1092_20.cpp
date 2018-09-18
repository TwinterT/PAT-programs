#include<stdio.h>
#include<map>
#include<string.h>

using namespace std;

typedef struct node
{
	int need;
	int real;
	node()
	{
		real=0;
	}
}node;

map<char,node> mp;
char str[1010],eva[1010];

int main()
{
	int i,extra=0,missing=0;
	gets(str);
	gets(eva);
	int len_eva=strlen(eva);
	int len=strlen(str);
	for(i=0;i<len_eva;i++)
	{
		if(mp.find(eva[i])==mp.end())mp[eva[i]].need=1;
		else mp[eva[i]].need++;
	}
	for(i=0;i<len;i++)
	{
		if(mp.find(str[i])==mp.end())extra++;
		else 
		{
			if(mp[str[i]].real<mp[str[i]].need)mp[str[i]].real++;
			else extra++;
		}
	}
	bool tag=true;
	for(map<char,node>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if(it->second.real!=it->second.need)
		{
			tag=false;
			missing+=it->second.need-it->second.real;
		}
	}
	if(tag==true)
	{
		printf("Yes %d\n",extra);
	}
	else printf("No %d\n",missing);
	return 0;
}