#include<stdio.h>
#include<string.h>

int main()
{
	char str[90];
	int N,n1,n2,n3;
	scanf("%s",str);
	N=strlen(str);
	n1=n2=(N-1)/3+1;
	n3=N+2-n1-n2;
	int i;
	for(i=0;i<n1-1;i++)
	{
		printf("%c",str[i]);
		for(int j=0;j<n3-2;j++)
		{
			printf(" ");
		} 
		printf("%c",str[N-i-1]);
		printf("\n");
	}
	for(int k=i;k<=N-i-1;k++)
	{
		printf("%c",str[k]);
	}
	return 0;
} 
