#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define re register
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll quickpower(ll x,ll n)
{
	
	ll ans=1,base=x;
	while(n)
	{
		if(n&1)
		{
			ans*=base;		
		}
		base=base*base;
		n>>=1;
	}
	return ans;
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	ll x,n;
	cin>>x>>n;
	cout<<quickpower(x,n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

