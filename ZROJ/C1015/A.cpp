#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
const unsigned long long Mod(998244353);
long long Ans;
unsigned Ar[300005], To[300005];
unsigned m, n, Cnt;
unsigned A, B, C, D, t;
bitset<300005> Vis;
pair <unsigned, unsigned> a[300005];
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), t = RD();
  for (unsigned i(1); i <= n; ++i) a[i].first = RD();
  for (unsigned i(1); i <= n; ++i) Ar[i] = a[i].second = RD();
  sort(a + 1, a + n + 1);
  sort(Ar + 1, Ar + n + 1);
  if(t) {
    for (unsigned i(1); i <= n; ++i) {
      a[i].second = lower_bound(Ar + 1, Ar + n + 1, a[i].second) - Ar;
      To[i] = a[i].second;
    }
    for (unsigned i(1); i <= n; ++i) {
      if(!(Vis[i])) {
        unsigned Cur(i), Tmp(0);
        while (!Vis[Cur]) Vis[Cur] = 1, Cur = To[Cur], ++Tmp;
        Cnt += Tmp - 1;
      }
    }
  }
  for (unsigned i(1); i <= n; ++i) {
    long long j((long long)Ar[i] - a[i].first);
    Ans = (Ans + j * j) % Mod;
  }
//  for (unsigned i(1); i <= n; ++i) printf("%u %u\n", a[i].second, To[i]);
  if(t) printf("%lld %u\n", Ans, Cnt);
  else printf("%lld\n", Ans);
//  }
  return Wild_Donkey;
}
/*
5 1
4 5 3 1 2
2 5 1 4 7
*/
