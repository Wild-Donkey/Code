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
#define foreplay for
#define wild while
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
unsigned a[205], Dis[205], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Queue[10005], *Hd(Queue), *Tl(Queue);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), A = RD(), B = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  if (A == B) {
    printf("0\n");
    return 0;
  }
  *(++Tl) = A;
  while (Hd < Tl) {
    unsigned Cur(*(++Hd)), Nxt(Cur + a[Cur]);
    // printf("Cur %u Nxt %u\n", Cur, Nxt);
    if (Nxt <= n) {
      if (Dis[Nxt] == 0) Dis[Nxt] = Dis[Cur] + 1, *(++Tl) = Nxt;
      if (Nxt == B) break;
    }
    if (Cur > a[Cur]) {
      Nxt = Cur - a[Cur];
      if (Dis[Nxt] == 0) Dis[Nxt] = Dis[Cur] + 1, *(++Tl) = Nxt;
      if (Nxt == B) break;
    }
  }
  if (Dis[B])
    printf("%u\n", Dis[B]);
  else
    printf("-1\n");
  //  }
  //  system("pause");
  return Wild_Donkey;
}