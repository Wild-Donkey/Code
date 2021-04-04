#include<iostream>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	unsigned long long ans;
	int x,n;
	cin>>x>>n;
	ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=x;
	}
	cout<<ans;
	return 0;
}
