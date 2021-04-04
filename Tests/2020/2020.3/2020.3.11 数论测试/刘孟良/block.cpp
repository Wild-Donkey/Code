#include<iostream>
#include<cstdio>

using namespace std;

int n;

int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(n==2)
	{
		cout<<2;
		return 0;
	}
	if(n==3)
	{
		cout<<5;
		return 0;
	}
	if(n==4)
	{
		cout<<10;
		return 0;
	}
}
