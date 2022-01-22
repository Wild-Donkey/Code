#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=998244353;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

inline int ksm(int a,int b,int mod){
    int res=1;
    while(b){if(b&1) res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;
}

int n,sum[N],TenPow[N],InvTenPow[N],f[N],g[N],h[N],H[N];
char s[N];

int main(){
  freopen("D.in", "r", stdin);
  freopen("D.ans", "w", stdout);
    read(n);
    scanf("%s",s+1);
    int TenInv=ksm(10,mod-2,mod);
    InvTenPow[0]=1;TenPow[0]=1;
    for(int i=1;i<=n;i++) InvTenPow[i]=1ll*InvTenPow[i-1]*TenInv%mod;
    for(int i=1;i<=n;i++) TenPow[i]=1ll*TenPow[i-1]*10%mod;
    for(int i=1;i<=n;i++) sum[i]=(1ll*sum[i-1]*10%mod+s[i]-'0')%mod;
    for(int i=0;i<=n;i++) h[i]=1ll*sum[i]*InvTenPow[i]%mod;
    f[0]=1;g[0]=1;H[0]=h[0]*f[0];
    for(int i=1;i<=n;i++){
        f[i]=((1ll*sum[i]*g[i-1]%mod-1ll*TenPow[i]*H[i-1]%mod)%mod+mod)%mod;
        g[i]=(g[i-1]+f[i])%mod;H[i]=(H[i-1]+1ll*h[i]*f[i]%mod)%mod;
    }
    printf("%d\n",f[n]);
    return 0;
}
