#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstdlib>
using namespace std;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
	unsigned long long a,b,ans=1;
    cin>>a>>b;
	for(int i=1;i<=b;i++)
    {
    ans*=a;
	}
	cout<<ans<<endl;
	return 0;
}
