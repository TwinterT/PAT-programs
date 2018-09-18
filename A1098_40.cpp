#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 110;

int n;
int origin[maxn],temp_ori[maxn],now[maxn];

bool judge()
{
	for(int i=1;i<=n;i++)
	{
		if(now[i]!=temp_ori[i])return false;
	}
	return true;
}


bool insertsort()
{
	bool tag=false;
	int i;
	for(i=2;i<=n;i++)
	{
		if(i!=2&&judge())
		{
			tag=true;
		}
		int temp=temp_ori[i],j=i;
		while(j>1&&temp<temp_ori[j-1])
		{
			temp_ori[j]=temp_ori[j-1];
			j--;
		}
		temp_ori[j]=temp;
		if(tag==true)break;
	}
	return tag;
}

void downadjust(int left,int right)
{
	int i=left,j=left*2;
	while(j<=right)
	{
		if(j+1<=right&&temp_ori[j+1]>temp_ori[j])
		{
			j=j+1;
		}
		if(temp_ori[j]>temp_ori[i])
		{
			swap(temp_ori[j],temp_ori[i]);
			i=j;
			j=i*2;
		}
		else break;	
	}
}

bool heapsort()
{
	int i;
	bool flag=false;
	for(i=n/2;i>=1;i--)
	{
		downadjust(i,n);
	}
	for(i=n;i>=1;i--)
	{
		if(i!=n&&judge())
		{
			flag=true;
		}
		swap(temp_ori[i],temp_ori[1]);
		downadjust(1,i-1);
		if(flag==true)break;
	}
	return flag;
}


int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&origin[i]);
		temp_ori[i]=origin[i];
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&now[i]);
	}
	if(insertsort())
	{
		printf("Insertion Sort\n");
		for(i=1;i<=n;i++)
		{
			printf("%d",temp_ori[i]);
			if(i!=n)printf(" ");
		}
	}
	else 
	{
		for(i=1;i<=n;i++)
		{
			temp_ori[i]=origin[i];
		}
		heapsort();
		printf("Heap Sort\n");
		for(i=1;i<=n;i++)
		{
			printf("%d",temp_ori[i]);
			if(i!=n)printf(" ");
		}
	}
	return 0;
}