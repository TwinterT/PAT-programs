#include<stdio.h>
#include<string.h>
 

int b,num,turn_num[40];

int main()
{
	scanf("%d %d",&num,&b);
	int k=0;
	do{
		turn_num[k++]=num%b;
		num=num/b;
	}while(num!=0);
	int i=0;
	int num=k;
	while(i<=k)
	{
		if(turn_num[i]!=turn_num[k-1])break;
		else
		{
			i++;
			k--;
		}
	}
	if(i<=k)printf("No\n");
	else printf("Yes\n");
	for(int j=num-1;j>=0;j--)
	{
		printf("%d",turn_num[j]);
		if(j!=0)printf(" ");
	}
	return 0;
} 
