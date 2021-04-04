#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define N 1000007
using namespace std;
int n,m;
int que1[N],que2[N];
int num[N];
void dealmin()
{
	int h=1,t=0;
	for(int i=1;i<=n;i++)
	{
		while(h<=t&&que1[h]+m<=i)
		{
		h++;	
		}
		while(h<=t&&num[i]<num[que1[t]])
		{
		t--;	
		}
		que1[++t]=i;
		if(i>=m)cout<<num[que1[h]]<<" ";
	}

}

void dealmax()
{
	int h=1,t=0;
	for(int i=1;i<=n;i++)
	{
		while(h<=t&&que2[h]+m<=i)
		{
		h++;	
		}
		while(h<=t&&num[i]>num[que2[t]])
		{
				t--;
		}
	
		que2[++t]=i;
		if(i>=m)cout<<num[que2[h]]<<" ";
	}
}
int main()
{
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	dealmin();
	cout<<endl;
	dealmax();
	return 0;
}
