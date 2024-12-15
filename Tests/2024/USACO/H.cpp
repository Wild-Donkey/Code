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
const int mod = 1000000007;
const int N = 5e5 + 10, M = N << 1;

void Mn(unsigned &x) {x -= (x >= mod) ? mod : 0;}

char a[N];
unsigned f[N], g[N], Blue[N], Red[N], RedP[N], RedCnt[N];
void solve(){
  unsigned n;
  scanf("%u%s", &n, a + 1);
  f[0] = 1;
  unsigned LastB = 0x3f3f3f3f, LastR = 0x3f3f3f3f;
  for (unsigned i(1); i <= n; ++i) {
    if(a[i] == 'R') RedP[RedCnt[i] = RedCnt[i - 1] + 1] = i;
    else RedCnt[i] = RedCnt[i - 1];
  }
  for (unsigned i(n); i; --i) {
    if(a[i] == 'B') LastB = i;
    if(a[i] == 'R') LastR = i;
    Blue[i] = LastB, Red[i] = LastR;
  }
  // printf("Done\n");
  // return;
  for (unsigned i(1); i <= n; ++i) {
    if(i > 1) Mn(g[i] += g[i - 2]);
    if(a[i] == 'X') Mn(f[i] += f[i - 1]);
    unsigned Cur = 1, L = i + Cur, R = i + (Cur << 1) - 1;
    while (R <= n && L - 1 < Blue[i]) {
      if(Red[L] <= R) {
        L = RedP[RedCnt[R]] + 1, Cur = L - i, R = L + Cur - 1;
        continue;
      }
      unsigned Delt = min(Red[L], n + 1) - R - 1;
      Delt -= (Delt & 1);
      Delt = min(Delt, i + (Blue[i] - i) * 2 - 1 - R);
      if(Delt > n) return;
      Mn(g[R] += f[i - 1]), Mn(g[R + Delt + 2] += mod - f[i - 1]);
      L = Red[L] + 1, Cur = L - i, R = L + Cur - 1;
    }
    Mn(f[i] += g[i]);
    // printf("f[%u]=%u\n", i, f[i]);
  }
  printf("%u\n", f[n]);
}

signed main(){
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);

  // codeforces;
  
  int t = 1;
  while(t--) solve();
  return 0;
}