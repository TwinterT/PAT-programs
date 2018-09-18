#include<stdio.h>
#include<string.h>

typedef struct node
{
	char name[15];
	char pass[15];
}node;

node team[1010];
int n;

bool modify(int k)
{
	int temp=0;
	int	len=strlen(team[k].pass);
	for(int i=0;i<len;i++)
	{
		if(team[k].pass[i]=='1')
		{
			team[k].pass[i]='@';
			temp++;
		}else if(team[k].pass[i]=='0')
			{
				team[k].pass[i]='%';
				temp++;
			}else if(team[k].pass[i]=='l')
				{
					team[k].pass[i]='L';
					temp++;
				}
				else if(team[k].pass[i]=='O')
					{
						team[k].pass[i]='o';
						temp++;
					}
	}
	if(temp!=0)return true;
	else return false;
}

int main()
{
	bool vis[1010]={false};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s",team[i].name,team[i].pass);
	}
	int m=0;
	for(int i=0;i<n;i++)
	{
		if(modify(i))
		{
			vis[i]=true;
			m++;
		}
	}
	if(m!=0)
	{
		printf("%d\n",m);
		for(int i=0;i<n;i++)
		{
			if(vis[i]==true)
			{
				printf("%s %s\n",team[i].name,team[i].pass);
			}
		}
	}
	else 
	{
		if(n==1)
		{
			printf("There is 1 account and no account is modified");
		}
		else
		{
			printf("There are %d accounts and no account is modified",n);
		}
	}
	
	return 0;
} 
