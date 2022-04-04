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
unsigned a[500005], l[500005], L[500005];
unsigned long long f[2][500005], Ans(0x3f3f3f3f3f3f3f3f);
unsigned m, n(0), A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  A = RD(), m = min((unsigned)30, RD()), B = 0;
  for (unsigned i(1); i <= A; ++i)
    if((C = RD()) > B) B = a[++n] = C, l[n] = 1;
    else ++l[n]; 
  for (unsigned i(n); i; --i) L[i] = L[i + 1] + l[i];
  unsigned long long *Cur(f[1]), *Pre(f[0]);
  memset(Pre, 0x3f, ((n + 1) << 3)), Pre[0] = 0;
  for (unsigned i(1); i <= m; ++i, swap(Cur, Pre)) {
    memset(Cur, 0x3f, ((n + 1) << 3));
    for (unsigned j(1); j <= n; ++j) for (unsigned k(0); k < j; ++k)
      Cur[j] = min(Cur[j], Pre[k] + (unsigned long long)a[j] * L[k + 1]);
    Cur[0] = 0x3f3f3f3f3f3f3f3f; if(Ans > Cur[n]) Ans = min(Ans, Cur[n]), A = i;
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

