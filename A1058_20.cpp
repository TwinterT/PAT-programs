#include<stdio.h>

typedef struct num
{
	int Galleon;
	int Sickle;
	int Knut;
}num;

num A,B,C;

num sum(num a,num b)
{
	num ans;
	ans.Galleon=a.Galleon+b.Galleon;
	ans.Sickle=a.Sickle+b.Sickle;
	ans.Knut=a.Knut+b.Knut;
	int temp;
	while(ans.Knut>=29)
	{
		temp=ans.Knut/29;
		ans.Knut%=29;
		ans.Sickle+=temp;
	}
	while(ans.Sickle>=17)
	{
		temp=ans.Sickle/17;
		ans.Sickle%=17;
		ans.Galleon+=temp;
	}
	return ans;
}

int main()
{
	scanf("%d.%d.%d",&A.Galleon,&A.Sickle,&A.Knut);
	scanf("%d.%d.%d",&B.Galleon,&B.Sickle,&B.Knut);
	C=sum(A,B); 
	printf("%d.%d.%d",C.Galleon,C.Sickle,C.Knut);
	return 0;
} 
