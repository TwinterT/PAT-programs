#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct node
{
	char name[20];
	int in[3],out[3];
}node;

int M;
vector<node> data;

bool cmp1(node a,node b)
{
	int num_a,num_b;
	num_a=a.in[0]*10000+a.in[1]*100+a.in[2];
	num_b=b.in[0]*10000+b.in[1]*100+b.in[2];
	return num_a<num_b;
}

bool cmp2(node a,node b)
{
	int num_a,num_b;
	num_a=a.out[0]*10000+a.out[1]*100+a.out[2];
	num_b=b.out[0]*10000+b.out[1]*100+b.out[2];
	return num_a>num_b;
}

int main()
{
	node temp;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		scanf("%s %d:%d:%d %d:%d:%d",temp.name,&temp.in[0],&temp.in[1],&temp.in[2],&temp.out[0],&temp.out[1],&temp.out[2]);
		data.push_back(temp);
	}
	sort(data.begin(),data.end(),cmp1);
	printf("%s ",data[0].name);
	sort(data.begin(),data.end(),cmp2);
	printf("%s",data[0].name);	
	return 0;
} 
