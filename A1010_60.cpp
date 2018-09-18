#include<stdio.h>
#include<map>
#include<algorithm>
#include<string.h>

using namespace std;

typedef long long LL;

map<char,LL> mp;

LL inf=((LL)1<<63)-1;

void init()
{
	for(char c='0';c<='9';c++)
	{
		mp[c]=c-'0';
	}
	for(char c='a';c<='z';c++)
	{
		mp[c]=c-'a'+10;
	}
}

LL convertNum10(char N1[],int radix,LL t)
{
	LL ans=0;
	int len=strlen(N1);
	for(int i=0;i<len;i++)
	{
		ans=mp[N1[i]]+ans*radix;
		if(ans<0||ans>t)return -1;
	}
	return ans;
}

LL findLargestDigit(char N2[])
{
	LL max=-1;
	int len=strlen(N2) ;
	for(int i=0;i<len;i++)
	{
		if(max<mp[N2[i]])max=mp[N2[i]];
	}
	return max+1;
}

int cmp(char N2[],LL radix,LL t)
{
	int len = strlen(N2);
	LL num = convertNum10(N2,radix,t);
	if(num<0)return 1;
	if(t>num)return -1;
	else if(t==num)return 0;
		else return 1;
}


LL binarySearch(char N2[],LL left,LL right,LL t)
{
	LL mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		int flag=cmp(N2,mid,t);
		if(flag==0)return mid;
		else if(flag==-1)left=mid+1;
			else right = mid-1;
	}
	return -1;
} 

char n1[13],n2[13];
int radix,tag;

int main()
{
	init();
	scanf("%s %s %d %d",n1,n2,&tag,&radix);
	if(tag==2)
	{
		char temp[13];
		strcpy(temp,n1);
		strcpy(n1,n2);
		strcpy(n2,temp);
	}	
	LL t=convertNum10(n1,radix,inf);
	LL low=findLargestDigit(n2);
	LL high=max(low,t)+1;
	LL ans = binarySearch(n2,low,high,t);
	if(ans==-1)printf("Impossible\n");
	else printf("%lld\n",ans);
	return 0;
} 
