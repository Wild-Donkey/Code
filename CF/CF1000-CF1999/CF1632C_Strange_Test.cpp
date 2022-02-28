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
unsigned Bin[30];
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), m = RD(), A = 0, Ans = 0x3f3f3f3f;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD(), Bin[0] = 1;
  for (unsigned i(1); i <= 25; ++i) Bin[i] = (Bin[i - 1] << 1);
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    if (m <= n) { printf("%u\n", n - m); continue; }
    for (unsigned i(n); i <= m; ++i) {
      A = (m | i);
      // printf("Try %u %u\n", i, A);
      for (unsigned j(0); j <= 25; ++j) if ((Bin[j] & A) && (!(i & Bin[j])) && ((A ^ Bin[j]) >= m)) A ^= Bin[j];
      // printf("A = %u\n", A);
      Ans = min(Ans, i - n - m + 1 + (i | A));
    }
    printf("%u\n", min(m - n, Ans));
  }
  //  system("pause");
  return Wild_Donkey;
}