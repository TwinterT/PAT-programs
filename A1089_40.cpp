#include<stdio.h>
#include<algorithm>

using namespace std;

const int N=111;

int origin[N],temp0ri[N],changed[N];
int n;

int min(int a,int b)
{
	if(a<b)return a;
	else return b;
}

void showArray(int A[])
{
	for(int i=0;i<n;i++)
	{
		printf("%d",A[i]);
		if(i<n-1)printf(" ");
	}
	printf("\n");
}

bool isSame(int A[],int B[])
{
	for(int i=0;i<n;i++)
	{
		if(A[i]!=B[i])return false;
	}
	return true;
}

bool insertSort()
{
	bool flag=false;
	for(int i=1;i<n;i++)
	{
		if(i!=1&&isSame(temp0ri,changed))
		{
			flag=true;
		}
		int temp=temp0ri[i],j=i;
		while(j>0&&temp0ri[j-1]>temp)
		{
			temp0ri[j]=temp0ri[j-1];
			j--;
		}
		temp0ri[j]=temp;
		if(flag==true)
		{
			return true;
		}
	}
	return false;
}

void mergeSort()
{
	bool flag =false;
	for(int step=2;step/2<=n;step*=2)
	{
		if(step!=2&&isSame(temp0ri,changed))
		{
			flag=true;
		}
		for(int i=0;i<n;i+=step)
		{
			sort(temp0ri+i,temp0ri+min(i+step,n));
		}
		if(flag==true)
		{
			showArray(temp0ri);
			return;
		}
	}
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&origin[i]);
		temp0ri[i]=origin[i];
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&changed[i]);
	}
	if(insertSort())
	{
		printf("Insertion Sort\n");
		showArray(temp0ri);
	}
	else
	{
		printf("Merge Sort\n");
		for(i=0;i<n;i++)
		{
			temp0ri[i]=origin[i];
		}
		mergeSort();
	}
	return 0;
}