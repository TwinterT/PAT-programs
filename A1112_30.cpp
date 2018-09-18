#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int maxn=1010;
const int maxm=128;

char str[maxn];
int K,len,isstuck[maxn]={0};

void judgestuck()
{
	int i=0,j=0;
	while(i<len)
	{
		while(j<len&&str[i]==str[j])
		{
			j++;
		}
		if((j-i)%K!=0)
		{
			isstuck[str[i]]=1;
		}
		i=j;
	}
}

int main()
{
	scanf("%d%s",&K,str);
	len=strlen(str);
	judgestuck();
	for(int i=0;i<len;i++)
	{
		if(isstuck[str[i]]==0)
		{
			printf("%c",str[i]);
			isstuck[str[i]]=-1;
		}
	}
	printf("\n");
	for(int i=0;i<len;)
	{
		printf("%c",str[i]);
		if(isstuck[str[i]]==-1)
		{
			i+=K;
		}
		else
		{
			i++;
		}
	}
	system("pause");
	return 0;
}