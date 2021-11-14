#include<bits/stdc++.h>

using namespace std;

#define int long long
//#define INF 1ll<<30

template<typename _T>
inline void read(_T &x)
{
	x=0;char s=getchar();int f=1;
	while(s<'0'||s>'9') {f=1;if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();}
	x*=f;
}

const int mod = 2148473647;
const int np = 2e6 + 5;
int h[np],f[np];
int fac[np],inv[np];

inline int power(int a,int b)
{
	int res(1);
	while(b)
	{
		if(b & 1) res = res * a,res %= mod;
		a = a *  a;
		a %= mod;
		b >>= 1;
	}
	return res;
}

inline int c(int n,int m)
{
	return (((fac[n] * inv[m])%mod) * inv[n-m]) % mod;
}

signed  main()
{
    freopen("D.in", "r", stdin);
    freopen("D.ans", "w", stdout);
	int n;
	read(n);
	fac[0] = 1;
	for(int i=1;i<=(int)2e6;i++) fac[i] = fac[i - 1] * i % mod,fac[i] %= mod;
	inv[(int)2e6] = power(fac[(int)(2e6)],mod-2);
	for(int i=(int)(2e6) - 1;i >= 0;i--) inv[i] = inv[i + 1] *(i + 1),inv[i] %= mod; 
	
	int hn = c(2 * n,n) - c(2 * n,n + 1);
	hn %= mod;
	hn += mod;
	hn %= mod;
	
	int sum=0;
	sum = f[1] = 1;
	for(int i=2;i<=n;i++)
	{
		f[i] = sum * 2;
		f[i] %= mod;
		sum += f[i];
		sum %= mod;
	} 
	int Ans = f[n] * power(hn,mod -2 );
	Ans %= mod;
	printf("%lld %lld\n",hn,f[n]);
	printf("%lld",Ans);
 }


