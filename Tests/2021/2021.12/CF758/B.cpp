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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), A = RD(), B = RD(), m = A + B + 2;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    if (m > n) { printf("-1\n"); continue; }
    if (A >= B) {
      if (A > B + 1) { printf("-1\n"); continue; }
      for (unsigned i(1); i <= n - m; ++i) printf("%u ", i);
      C = n - m + 1, D = n, Cnt = 0;
      while (C <= D) printf("%u ", ((Cnt++) & 1) ? (D--) : (C++));
      putchar(0x0A);
    }
    else {
      if (B > A + 1) { printf("-1\n"); continue; }
      C = 1, D = m, Cnt = 0;
      while (C <= D) printf("%u ", ((Cnt++) & 1) ? (C++) : (D--));
      for (unsigned i(m + 1); i <= n; ++i) printf("%u ", i);
      putchar(0x0A);
    }
  }
  // system("pause");
  return Wild_Donkey;
}

/*
3
4 1 1
6 1 2
6 2 1
*/