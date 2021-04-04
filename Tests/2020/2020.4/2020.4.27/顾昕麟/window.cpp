//window
//#include<con>
#include<iostream>
using namespace std;
int num[1000010];
int minn[1000010];
int maxn[1000010];
long long win,len,a=10000000000,b=-100000000000;
int main()
{
	freopen("window.in","r",stdin);
	freopen("window.in","w",stdout);
	cin>>len>>win;
	for(int i=0;i<len;i++)
	{
		cin>>num[i];
	}
	for(int i=0;i<=len-win;i++)
	{
		for(int j=i;j<win+i;j++)
		{
			if(a>num[j]) a=num[j];
			if(b<num[j]) b=num[j];
		}
		minn[i]=a;
		maxn[i]=b;
		a=10000000000;
		b=-10000000000;
	}
	for(int i=0;i<=len-win;i++)
	{
		cout<<minn[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<=len-win;i++)
	{
		cout<<maxn[i]<<" ";
	}
	return 0;
}
