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
char a[1100005];
unsigned Border[1100005], Loop[1100005], m, n, Tot, Cnt, Odd(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  n = RD();
  scanf("%s", a + 1);
  Cnt = Tot = 0, Border[1] = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      unsigned j(i - 1);
      while ((j) && (a[Border[j] + 1] ^ a[i])) j = Border[j];
      if (!j) Border[i] = a[i] == a[1];
      else Border[i] = Border[j] + 1;
      if (i % (i - Border[i])) Loop[i] = 1;
      else Loop[i] = i / (i - Border[i]);
    }
    for (unsigned i(1); i <= n; ++i) {

    }
  }
  //  system("pause");
  return Wild_Donkey;
}