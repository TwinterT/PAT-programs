#include<stdio.h>
#include<map>
#include<string.h>

using namespace std;

char origin[85],now[85];
map<char,bool> mp;

int main()
{
	int i,j,len_ori,len_now;
	mp['-']=false;
	for(i=0;i<10;i++)
	{
		mp['0'+i]=false;
	}
	for(i=0;i<26;i++)
	{
		mp['A'+i]=false;
	}
	scanf("%s\n%s",origin,now);
	len_ori=strlen(origin);
	len_now=strlen(now);
	j=0;
	for(i=0;i<len_now;i++,j++)
	{
		while(origin[j]!=now[i])
		{
			char temp=origin[j];
			if(temp>='a'&&temp<='z')temp-=32;
			if(mp[temp]==false)
			{
				printf("%c",temp);
				mp[temp]=true;
			}
			j++;
		}
	}
	while(j<len_ori)
	{
		char temp=origin[j];
		if(temp>='a'&&temp<='z')temp-=32;
		if(mp[temp]==false)
		{
			printf("%c",temp);
			mp[temp]=true;
		}
		j++;
	} 
	return 0;
}
