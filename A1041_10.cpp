#include<stdio.h>

int n;
int num[100010],hash[10010];
int main()
{
	scanf("%d ",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		hash[num[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		if(hash[num[i]]==1)
		{
			printf("%d\n",num[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
} 
