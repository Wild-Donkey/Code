#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int x,n;
	cin>>x>>n;
	long long a;
	a=pow(x,n);
	cout<<a;
}
