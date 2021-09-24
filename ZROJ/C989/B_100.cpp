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
unsigned m, n, Sz(1000000), Now(Sz);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char RB[1000005];
inline char GC() {
  if (Now == Sz) Now = 0, fread(RB, 1, Sz, stdin);
  return RB[Now++];
}
inline unsigned RD() {
  register unsigned intmp(0);
  register char rdch(GC());
  while (rdch < '0') rdch = GC();
  while (rdch >= '0') intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = GC();
  return intmp;
}
inline unsigned Mx(const unsigned x, const unsigned y) { return (y < x) ? x : y; }
inline unsigned Mn(const unsigned x, const unsigned y) { return (y > x) ? x : y; }
inline void Udt(unsigned& x, const unsigned y) { if (x > y) x = y; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  memset(f, 0x3f, sizeof(f)), memset(g, 0x3f, sizeof(g)), n = RD(), m = n >> 1;
  for (register unsigned i(1); i <= n; ++i)
    for (register unsigned j(1), Len((n - i + 1) >> 1); j <= Len; ++j)
      a[i][j] = RD();
  for (register unsigned i(n - 1); i; --i) g[i + 1][1] = f[i][1] = a[i][1];
  for (register unsigned Len(2); Len <= m; ++Len) {
    for (register unsigned i(n - (Len << 1) + 1); i; --i) {
      register unsigned* Le(f[i]), * Ri(g[i + (Len << 1) - 1] + Len), Tmp[8] = {Mx(f[i + 1][Len - 1], a[i][Len]), 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f};
      for (register unsigned j((Len + 7) >> 3); j; --j, Le += 8, Ri -= 8) {
        Udt(Tmp[0], Mx(*(Le + 1), *(Ri - 1)));
        Udt(Tmp[1], Mx(*(Le + 2), *(Ri - 2)));
        Udt(Tmp[2], Mx(*(Le + 3), *(Ri - 3)));
        Udt(Tmp[3], Mx(*(Le + 4), *(Ri - 4)));
        Udt(Tmp[4], Mx(*(Le + 5), *(Ri - 5)));
        Udt(Tmp[5], Mx(*(Le + 6), *(Ri - 6)));
        Udt(Tmp[6], Mx(*(Le + 7), *(Ri - 7)));
        Udt(Tmp[7], Mx(*(Le + 8), *(Ri - 8)));
      }
      f[i][Len] = g[i + (Len << 1) - 1][Len] = Mn(Mn(Mn(Tmp[0], Tmp[1]), Mn(Tmp[2], Tmp[3])), Mn(Mn(Tmp[4], Tmp[5]), Mn(Tmp[6], Tmp[7])));
    }
  }
  printf("%u\n", f[1][m]);
  //  }
  return Wild_Donkey;
}
