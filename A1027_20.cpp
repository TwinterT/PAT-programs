#include<stdio.h>

int r,g,b;
char mp[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int color[3][2]={0};

void turn(int color[],int num)
{
	color[1]=num%13;
	num/=13;
	color[0]=num;
}

void print()
{
	printf("#");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%c",mp[color[i][j]]);
		}
	}
}

int main()
{
	scanf("%d %d %d",&r,&g,&b);
	turn(color[0],r);
	turn(color[1],g);
	turn(color[2],b);
	print();
	return 0;
} 
