#include<stdio.h>

double test[3][3];
char mp[3]={'W','T','L'};

int main()
{
	double ans=1;
	for(int i=0;i<3;i++)
	{
		int max_j=0;
		double temp=-1;
		for(int j=0;j<3;j++)
		{
			scanf("%lf",&test[i][j]);
			if(test[i][j]>temp)
			{
				max_j=j;
				temp=test[i][j];
			}
		}
		printf("%c ",mp[max_j]);
		ans*=temp;
	}
	ans=(ans*0.65-1)*2;
	printf("%.2f",ans);
	return 0;
}
