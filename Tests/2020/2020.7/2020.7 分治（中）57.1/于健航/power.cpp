#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int Next[10000];
double quick_power(double base, unsigned int n)
{
	double res=1.0;
	while (n>0)
	{
		if (n&1)
			res*=base;
		base*=base;
		n>>=1;
	}
	return res;
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
	int a,b;
	cin>>a>>b;
	cout<<quick_power(a,b)<<endl;
	return 0;
}
