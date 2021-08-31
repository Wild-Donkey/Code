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
unsigned a[100005], Now, Sum, m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char b[100005];
inline void Clr() {
  n = RD(), Sum = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T) {
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      Sum ^= (a[i] = RD());
    }
    if (Sum == 0) { printf("Draw\n"); continue; }
    for (register char i(31); i >= 0; --i)
      if (Sum & (1 << i)) { Now = i; break; }
    if (!(n & 1)) { printf("Alice\n");continue; }
    Sum = 0;
    for (register unsigned i(1); i <= n; ++i)
      b[i] = (a[i] & (1 << Now)) >> Now, Sum += b[i];
    if (!(b[1] | b[n])) { printf("Bob\n");continue; }
    if ((Sum - 1) % 4) { printf("Bob\n");continue; }
    if (b[1]) {
      register unsigned Mid(2), L, R;
      for (; Mid <= ((n + 1) >> 1); ++Mid)
        if (b[Mid] ^ b[n - Mid + 2]) break;
      L = Mid, R = n - Mid + 2;
      for (; Mid <= R; Mid += 2)
        if (b[Mid] ^ b[Mid + 1]) break;
      if (Mid > R) { printf("Alice\n");continue; }
    }
    if (b[n]) {
      register unsigned Mid(1), L, R;
      for (; Mid <= (n >> 1); ++Mid)
        if (b[Mid] ^ b[n - Mid]) break;
      L = Mid, R = n - Mid;
      for (; Mid <= R; Mid += 2)
        if (b[Mid] ^ b[Mid + 1]) break;
      if (Mid > R) { printf("Alice\n");continue; }
    }
    printf("Bob\n");
  }
  // system("pause");
  return Wild_Donkey;
}