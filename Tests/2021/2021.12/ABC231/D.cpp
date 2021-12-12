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
unsigned Deg[200005], m, n;
unsigned To[200005][2];
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
bitset<200005> Ava;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    ++Deg[A = RD()], ++Deg[B = RD()];
    To[A][To[A][0] ? 1 : 0] = B;
    To[B][To[B][0] ? 1 : 0] = A;
  }
  for (unsigned i(1); i <= n; ++i) if (Deg[i] > 2) { printf("No\n"); return Wild_Donkey; }
  for (unsigned i(1); i <= n; ++i) if ((!Ava[i]) && (Deg[i] < 2)) {
    Ava[i] = 1, ++Cnt;
    if (Deg[i]) {
      unsigned Cur(To[i][0]), Last(i);
      while (Deg[Cur] == 2) {
        unsigned TmpL(Cur);
        ++Cnt;
        Cur = To[Cur][(To[Cur][0] == Last) ? 1 : 0];
        if (Ava[Cur]) { printf("No\n"); return Wild_Donkey; }
        Last = TmpL, Ava[Cur] = 1;
      }
      Ava[Cur] = 1;
      ++Cnt;
    }
  }
  printf((Cnt < n) ? "No\n" : "Yes\n");
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
4 4
1 2
1 4
2 3
3 4
*/