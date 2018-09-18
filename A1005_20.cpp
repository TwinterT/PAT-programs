#include<stdio.h>
#include<string.h>

int sum=0,digit[10];
char s[110];
char num[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()
{
	gets(s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		sum+=(s[i]-'0');
	} 
	if(sum==0)printf("%s",num[0]);
	else
	{
		int k=0;
		while(sum!=0)
		{
			digit[k++]=sum%10;
			sum=sum/10;
		}
		for(int i=k-1;i>=0;i--)
		{
			printf("%s",num[digit[i]]);
			if(i!=0)printf(" ");
		}
	}
	return 0;
} 
