#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long a[23];
unsigned long long c[23];
inline void catalan(int l)
{
	for(int i=0;i<=l-1;i++) 
	{
	a[l]+=a[i]*a[l-1-i];
	c[l]+=(a[i]*a[l-1-i])%19260817;
	}
	c[l]%=19260817;
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	unsigned long long n;
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin>>n;
	a[0]=1;
	c[0]=1;
	a[1]=1;
	c[1]=1;
	a[2]=2;
	c[2]=2;
	a[3]=5;
	c[3]=5;
	a[4]=14;
	c[4]=14;
	for(int i=5;i<=n;i++)
	{
		catalan(i);
	}
	cout << c[n];
}