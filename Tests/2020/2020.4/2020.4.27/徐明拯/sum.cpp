#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long k,i,j,n,m,ans=0;
long long a[100010],b[100010];
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	    cin>>a[i];
	for(i=1;i<=n;i++)
	    cin>>b[i];
	for(k=0;k<=(n-1)/2-1;k++)
	{
		for(i=1;i<=n-2*(k+1);i++)
	    {
		    if(b[i]==b[i+2*(k+1)]&&b[i]!=b[i+k+1])
		    ans=ans+(i+i+2*(k+1))*(a[i]+a[i+2*(k+1)]);
	    }
	}
	cout<<ans;
	return 0;
}

