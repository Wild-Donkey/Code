#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int ans=1;
int a,b;
void ksm(int n,int k)
{
	if(k==0)
	return;
	if(k&1)
	ans*=n;
	n=n*n;
	return ksm(n,k>>1);
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>a>>b;
	if(a==0)
	{
		cout<<0<<endl;
		return 0;
	}
	ksm(a,b);
	cout<<ans<<endl;
	return 0;
}

