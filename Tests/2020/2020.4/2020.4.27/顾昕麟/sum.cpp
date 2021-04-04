//sum
//#include<con>
#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int num[10000000];
struct STU{
	int color;
	int point;
}QAQ[100010];
int m,n,ans;
int main()
{
	//freopen("sum.in","r",stdin);
	//freopen("sum.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>QAQ[i].point;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>QAQ[i].color;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(j-i==k-j&&QAQ[i].color==QAQ[k].color)
				{
					ans+=(i+k)*(QAQ[i].point+QAQ[k].point)%10007;
				}
			}
		}
	}
	cout<<ans;
	return 0;																					while(1);
}
