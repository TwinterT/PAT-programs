#include<stdio.h>
#include<algorithm>
using namespace std;

void to_array(int n,int array[])
{
	for(int i=0;i<4;i++)
	{
		array[i]=n%10;
		n=n/10;
	} 
} 

int to_number(int array[])
{
	int n=0;
	for(int i=0;i<4;i++)
	{
		n=n*10+array[i];
	}
	return n;
}

bool cmp(int n1,int n2)
{
	return n1>n2;
}
int main()
{
	int num,max,min,array[5];
	scanf("%d",&num);
	do
	{
	to_array(num,array);
	min=to_number(array);
	sort(array,array+4,cmp);
	max=to_number(array);
	num=max-min;
	printf("%d - %d = %d\n",max,min,num);
	}while(num!=6174&&num!=0);
	return 0;
}
