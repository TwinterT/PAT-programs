#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

const int maxn=10010;
const int INF=1000000000;

typedef struct member
{
	int id;
	vector<int> relate;
	double estate,area;
	member()
	{
		estate=area=0;
	}
}member;

typedef struct family
{
	int min_id;
	int number;
	double estate,area;
	family()
	{
		min_id=INF;
		number=0;
		estate=area=0;
	}
}family;

vector<int> person;
member data[maxn];
vector<family> ans;
bool vis[maxn]={false};
int n;

void DFS(int index,int &number,double &estate,double &area,int &min_id)
{
	if(vis[index]==false)
	{
		vis[index]=true;
		if(min_id>index)min_id=index;
		number++;
		estate+=data[index].estate;
		area+=data[index].area;
		for(int k:data[index].relate)
		{
			if(vis[k]==false)DFS(k,number,estate,area,min_id);
		}
	}
}

void DFS_travel()
{
	for(int c:person)
	{
		if(vis[c]==false)
		{
			family temp;
			DFS(c,temp.number,temp.estate,temp.area,temp.min_id);
			vis[c]=true;
			temp.area/=temp.number;
			temp.estate/=temp.number;
			ans.push_back(temp);
		}
	}
}

bool cmp(family a,family b)
{
	if(a.area!=b.area)return a.area>b.area;
	else return a.min_id<b.min_id;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int id,fa,mo,chid_num;
		scanf("%d %d %d %d",&id,&fa,&mo,&chid_num);
		person.push_back(id);
		data[id].id=id;
		if(fa!=-1)
		{
			data[id].relate.push_back(fa);
			data[fa].relate.push_back(id);
		}
		if(mo!=-1)
		{
			data[id].relate.push_back(mo);
			data[mo].relate.push_back(id);
		}
		for(int j=0;j<chid_num;j++)
		{
			int chid;
			scanf("%d",&chid);
			data[id].relate.push_back(chid);
			data[chid].relate.push_back(id);
		}
		scanf("%lf %lf",&data[id].estate,&data[id].area);
	}
	DFS_travel();
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",ans.size());
	for(family i:ans)
	{
		printf("%04d %d %.3f %.3f\n",i.min_id,i.number,i.estate,i.area);
	}
	system("pause");
	return 0;
}