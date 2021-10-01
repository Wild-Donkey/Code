#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define il inline
#define mod 999911659
#define Mod 999911658
#define inf 0x3fffffff
#define pi pair<int,int>
#define mp(a,b) make_pair(a, b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
int rd(){
	int res = 0, fl = 1;
   char c = getchar();
   while(!isdigit(c)){
       if(c == '-') fl = -1;
       c = getchar();
   }
   while(isdigit(c)){
      res = (res << 3) + (res << 1) + c - '0';
      c = getchar();
   }
   return res * fl;
}
const int maxn = 3010;
int n, m, k, bd[maxn][maxn];
ll f[maxn][maxn];
ll ksm(ll base, ll p){
	ll res=1;
	while(p){
		if(p&1) res*=base;
		res %= mod;
		base *= base; base %= mod;
		p >>= 1;
	}
	res %= mod; res += mod; res %= mod;
	return res;
}
ll num[10][maxn];
int main(){
  freopen("C.in", "r", stdin);
  freopen("C.ans", "w", stdout);
	n=rd(); m=rd(); k=rd();
	if(n < maxn && m < maxn){
		int kx, ky;
		for(int i=1;i<=k;++i) {
			kx = rd(); ky = rd();
			f[kx+1][ky+1]=-1;
		} 
		for(int i=1;i<=m;++i) if(f[1][i]==-1) break; else f[1][i]=1;
		for(int i=2;i<=n;++i){
			for(int j=i;j<=m;++j)
				if(f[i][j]!=-1)
//					f[i][j]=(f[i-1][j]*(f[i-1][j]!=-1)+f[i][j-1]*(f[i][j-1]!=-1)); 
					f[i][j]=((f[i-1][j]*(f[i-1][j]!=-1)+f[i][j-1]*(f[i][j-1]!=-1))%Mod+Mod)%Mod;
		}
	//	for(int i=1;i<=n;++i){
	//		for(int j=1;j<=m;++j) printf("%5lld ", f[i][j]);
	//		printf("\n");
	//	}
	//	printf("%lld\n", f[n][m]);
		if(f[n][m]==-1) printf("1\n");
		else printf("%lld\n", ksm(233, f[n][m]));
		return 0;
	}
//	if(k == 0){
//		printf("%lld\n", )
//		return 0;
//	}
	return 0;
}


