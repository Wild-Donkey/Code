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
#include <set>
#include <string>
#include <unordered_map>
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
unsigned a[105][105], Ans[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char FlgMid(0);
inline void Flipn(unsigned x) {Ans[++Cnt] = x + 0x3f3f3f3f; for (unsigned i(1), j(n); i < j; ++i, --j) swap(a[i][x], a[j][x]);}
inline void Flipm(unsigned x) {Ans[++Cnt] = x; for (unsigned i(1), j(m); i < j; ++i, --j) swap(a[x][i], a[x][j]);}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) a[i][j] = RD();
  if(m & 1) for (unsigned i(1); i <= n; ++i) 
    if(a[i][(m >> 1) + 1] ^ ((m >> 1) + 1))return printf("NO\n"), 0;
  if(n & 1) {
    for (unsigned i(1); i <= m; ++i) if(a[(n >> 1) + 1][i] ^ i) {FlgMid = 1; break;}
    if(FlgMid) for (unsigned i(1); i <= m; ++i) if(a[(n >> 1) + 1][i] ^ (m - i + 1)) {FlgMid = 2; break;}
    if(FlgMid == 2) return printf("NO\n"), 0;
    if(FlgMid) Flipm((n >> 1) + 1);
  }
  for (unsigned i(1), j(m); i < j; ++i, --j) for (unsigned u(1), d(n); u < d; ++u, --d) {
    char Cni(0), Cnj(0);
    if(a[u][i] ^ i) ++Cni; if(a[u][j] ^ i) ++Cni;
    if(a[d][i] ^ i) ++Cni; if(a[d][j] ^ i) ++Cni;
    if(a[u][i] ^ j) ++Cnj; if(a[u][j] ^ j) ++Cnj;
    if(a[d][i] ^ j) ++Cnj; if(a[d][j] ^ j) ++Cnj;
    if((Cni ^ 2) || (Cnj ^ 2)) return printf("NO\n"), 0;
  }
  printf("YES\n");
  for (unsigned i(1), j(m); i < j; ++i, --j) {
    for (unsigned u(1), d(n); u < d; ++u, --d) {
      if(a[u][i] == a[d][i]){if(a[u][i] ^ i) Flipm(u), Flipn(i), Flipn(j), Flipm(u); continue;}
      if(a[u][i] ^ a[u][j]) Flipn(i);
      Flipm(u), Flipn((a[u][i] ^ i) ? j : i), Flipm(u);
    }
  }
  printf("%u\n", Cnt);
  for (unsigned i(1); i <= Cnt; ++i) 
    printf("%u %u\n", (Ans[i] > 0x3f3f3f3f), (Ans[i] > 0x3f3f3f3f) ? Ans[i] - 0x3f3f3f3f : Ans[i
    ]);
  return Wild_Donkey;
}
