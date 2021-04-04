#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define mod 19268017
using namespace std;
long long n,m,ans;
long long  f[10000000];
long long  qmul(long long  x, long long  y)
{
    long long ret=0;
    while(y) {
        if(y&1)
            ret=(ret+x)%mod;
        x=x*2%mod;
        y>>=1;
    }
    return ret;
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
    cin>>n>>m;
    if(n==1&&m==1)
	{
        printf("0\n");
        return 0;
    }
    if(n==1||m==1)
	{
       cout<<"1";
       return 0;
    }
    ans=qmul(n-1,m-1);
    n--;
    m--;
    for(int i=n;i>=2;i--)
	{
        f[i]=qmul(n/i,m/i);
        for(int j=2*i;j<=m;j+=i) 
		{
			f[i]-=f[j];
			f[i]%=mod;
		}
        ans-=f[i];
        ans%=mod;
    }
    cout<<ans+2;
    return 0;
}
