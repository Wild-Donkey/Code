#include <algorithm>
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
unsigned a[4005][2005], f[4005][2005], g[4005][2005];
unsigned m, n, Sz(100000), Now(Sz);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char RB[100005];
inline char GC() {
  if (Now == Sz) Now = 0, fread(RB, 1, Sz, stdin);
  return RB[Now++];
}
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(GC());
  while (rdch < '0' || rdch > '9') rdch = GC();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = GC();
  return intmp;
}
inline unsigned Mx(const unsigned x, const unsigned y) { return (y < x) ? x : y; }
inline void Udt(unsigned& x, const unsigned y) { if (x > y) x = y; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = n >> 1;
  for (unsigned i(1); i <= n; ++i)
    for (unsigned j(1), Len((n - i + 1) >> 1); j <= Len; ++j)
      a[i][j] = RD();
  for (register unsigned Len(1); Len <= m; ++Len) {
    for (register unsigned Tmp, i(n - (Len << 1) + 1); i; --i) {
      Tmp = Mx(f[i + 1][Len - 1], a[i][Len]);
      register unsigned* Le(f[i] + 1), * Ri(g[i + (Len << 1) - 1] + Len - 1);
      Cnt = (Len - 1) >> 3;
      // printf("%u %u\n", Len, Cnt);
      for (register unsigned j(Cnt); j; --j) {
        Udt(Tmp, Mx(*(Le++), *(Ri--)));
        Udt(Tmp, Mx(*(Le++), *(Ri--)));
        Udt(Tmp, Mx(*(Le++), *(Ri--)));
        Udt(Tmp, Mx(*(Le++), *(Ri--)));
        Udt(Tmp, Mx(*(Le++), *(Ri--)));
        Udt(Tmp, Mx(*(Le++), *(Ri--)));
        Udt(Tmp, Mx(*(Le++), *(Ri--)));
        Udt(Tmp, Mx(*(Le++), *(Ri--)));
      }
      for (unsigned j((Len - 1) & 7); j; --j) Udt(Tmp, Mx(*(Le++), *(Ri--)));
      f[i][Len] = g[i + (Len << 1) - 1][Len] = Tmp;
    }
  }
  printf("%u\n", f[1][m]);
  //  }
  return Wild_Donkey;
}