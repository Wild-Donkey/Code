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
unsigned Ava[2005][2005];
short Lst[2005], Lf[2005], Rg[2005];
short Stk[2005], *STop(Stk);
bitset<2005> No;
unsigned long long Ans(0);
unsigned A, B, C, D, t, m, n, K;
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), K = RD();
  for (unsigned i(1); i <= n; ++i) {
    unsigned Lim((K + i - 1) / i);
    for (unsigned j(Lim); j <= m; ++j)
      Ava[i][j] = Ava[i - 1][j] + (((j - Lim + 1) * (j - Lim + 2)) >> 1);
//    printf("%u(%u):", i, Lim); for (unsigned j(1); j <= m; ++j) printf("%u ", Ava[i][j]); putchar(0x0A);
  }
  Lst[0] = Lst[m + 1] = 0x3f3f;
  for (short i(1); i <= n; ++i) {
    for (short j(1); j <= m; ++j) if(RD()) Lst[j] = i;
//    for (unsigned j(1); j <= m; ++j) printf("%u ", Lst[j]); putchar(0x0A);
    No = 0;
    *(STop = Stk) = 0;
    for (short j(1); j <= m; ++j) {
      while (Lst[*STop] <= Lst[j]) {if(Lst[*STop] == Lst[j]) No[*STop] = 1; --STop;}
      Lf[j] = *STop, *(++STop) = j;
    }
//    for (unsigned j(1); j <= m; ++j) printf("%u ", Lf[j]); putchar(0x0A);
    *(STop = Stk) = m + 1;
    for (short j(m); j; --j) {
      while (Lst[*STop] <= Lst[j]) --STop;
      Rg[j] = *STop, *(++STop) = j;
    }
//    for (unsigned j(1); j <= m; ++j) printf("%u ", Rg[j]); putchar(0x0A);
    for (short j(1); j <= m; ++j) if(!No[j]) {
      short Low(min(i, min(Lst[Lf[j]], Lst[Rg[j]])) - Lst[j]), Del(i - Lst[j]), Wid(Rg[j] - Lf[j] - 1);
//      printf("Low %u Del %u Wid %u\n", Low, Del, Wid);
      Ans += Ava[Del][Wid] - Ava[Del - Low][Wid];
    }
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
