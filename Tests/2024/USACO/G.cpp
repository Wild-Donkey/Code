#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
// #define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 1e5 + 10, M = N << 1;
vector<unsigned> Pos[N];
int Ans[N];
unsigned Calc(unsigned x, unsigned Lim) {
  unsigned Cur = 0, Rt = 0;
  for (auto i:Pos[x]) {
    if(Cur >= i) continue;
    Cur = i + Lim, ++Rt;
  }
  return Rt;
}
void solve(){
  unsigned n, A;
  cin >> n;
  for (unsigned i = 1; i <= n; ++i) cin >> A, Pos[A].pb(i);
  for (unsigned i = 1; i <= n; ++i) if(Pos[i].size()) {
    for (unsigned L = 1, R; L <= n; L = R + 1) {
      unsigned BL = L, BR = n, Mid, LA = Calc(i, L);
      while (BL < BR) {
        Mid = ((BL + BR + 1) >> 1);
        if(Calc(i, Mid) == LA) BL = Mid;
        else BR = Mid - 1;
      }
      R = BL, Ans[L] += LA, Ans[R + 1] -= LA;
    }
  }
  for (unsigned i = 1; i <= n; ++i) {
    Ans[i] += Ans[i - 1];
    printf("%u\n", Ans[i]);
  }
}

signed main(){
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  // codeforces;
  
  int t = 1; // cin >> t;
  while(t--) solve();
  return 0;
}