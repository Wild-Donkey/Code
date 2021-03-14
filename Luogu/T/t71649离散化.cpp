#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
long long a[N],mi;
int n,mii,hao=0;
bool b[N]; 
inline void in()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
}
int main()
{
	in();
	for(int i=1;i<=n;i++)
	{
		mii=0;
		mi=0x7fffffffffffffff;
		for(int j=1;j<=n;j++)
			if(mi>a[j]&&!b[j])
			{
				mii=j;
				mi=a[j]; 
			}
		b[mii]=true;
		if(b[mii])
			a[mii]=++hao;
		for(int j=1;j<=n;j++)
			if(a[j]==mi&&!b[j])
			{
				a[j]=hao;
				b[j]=true;			
			}	
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
