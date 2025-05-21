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
char a[10000005];
unsigned Sum[10000005], List[256];
pair<unsigned, unsigned> Q[10005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  memset(a, 0, n);
  scanf("%s", a);
  n = strlen(a);
}
signed main() {
  List['P'] = 3, List['p'] = 2, List['G'] = 1;
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    Sum[0] = List[a[0]];
    for (unsigned i(1); i < n; ++i) Sum[i] = Sum[i - 1] + List[a[i]];
    m = RD();
    for (unsigned i(1); i <= m; ++i) {
      A = RD() - 1, B = RD() - 1;
      printf("%u\n", Sum[B] - (A ? Sum[A - 1] : 0));
    }
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
Tears snaking down your skin
Do you feel lonely
Do you feel blue
All right too

Leaves dancing in the wind
Do you feel angry
Do you feel hunbry
All right too
*/