#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n;
char str[110][270];

int main()
{
	int i,j,minlen=10000;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(str[i]);
		if(strlen(str[i])<minlen)
		{
			minlen=strlen(str[i]);
		}
	}
	for(i=0;i<n;i++)
	{
		int len=strlen(str[i]);
		for(j=0;j<len/2;j++)
		{
			swap(str[i][j],str[i][len-j-1]);
		}
	}
	int ans=0;
	bool same=true;
	for(i=0;i<minlen;i++)
	{
		char c=str[0][i];
		for(j=0;j<n;j++)
		{
			if(c!=str[j][i])same=false;
		}
		if(same==true)ans++;
		else 
		{
			same=false;
			break;
		}
	}
	if(ans==0)printf("nai\n");
	else 
	{
		for(i=ans-1;i>=0;i--)
		{
			printf("%c",str[0][i]);
		}
	}
	return 0;
}