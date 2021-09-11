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
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[100005], Nxt[100005], Pow[100005], m, n, w;
unsigned Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  w = RD() % 10000, t = RD(), Pow[0] = 1;
  for (unsigned i(1); i <= 100000; ++i) Pow[i] = Pow[i - 1] * w % 10000;
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    for (unsigned i(1), j(0); i <= n; ++i, j = i - 1) {
      while (j && (a[i] ^ a[Nxt[j] + 1])) j = Nxt[j];
      Nxt[i] = j ? (Nxt[j] + 1) : 0;
      // printf("%u %u\n", i, Nxt[i]);
    }
    while (n) { Ans += Pow[n]; if (Ans >= 10000) Ans -= 10000; n = Nxt[n]; }
    printf("%04u\n", Ans);
  }
  system("pause");
  return Wild_Donkey;
}
/*
jkkjjjkjk
*/