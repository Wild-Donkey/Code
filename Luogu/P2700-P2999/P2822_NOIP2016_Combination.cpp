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
unsigned F[2005], G[2005];
unsigned Ans[2005][2005];
unsigned P, CntP(0), Q, CntQ(0);
unsigned A, B, C, D, t, m;
inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD(), m = RD();
  for (unsigned i(2); i <= m; ++i)
    if (!(m % i)) {
      P = i;
      while (!(m % i)) m /= i, ++CntP;
      break;
    }
  if (m > 1) {
    for (unsigned i(2); i <= m; ++i)
      if (!(m % i)) {
        Q = i;
        while (!(m % i)) m /= i, ++CntQ;
      }
  }
  // printf("P %u %u Q %u %u\n", P, CntP, Q, CntQ);
  for (unsigned i(1); i <= 2000; ++i)
    for (unsigned j(P); j <= i; j = j * P) F[i] += i / j;
  if (CntQ) {
    for (unsigned i(1); i <= 2000; ++i)
      for (unsigned j(Q); j <= i; j = j * Q) G[i] += i / j;
  }
  // for (unsigned i(1); i <= 20; ++i) printf("%u ", F[i]);
  // putchar(0x0A);
  // for (unsigned i(1); i <= 20; ++i) printf("%u ", G[i]);
  // putchar(0x0A);
  for (unsigned i(1); i <= 2000; ++i) {
    for (unsigned j(0); j <= i; ++j) {
      Ans[i][j] = 1;
      if (F[i] < F[j] + F[i - j] + CntP) Ans[i][j] = 0;
      if (CntQ && G[i] < G[j] + G[i - j] + CntQ) Ans[i][j] = 0;
      // printf("%u ", Ans[i][j]);
    }
    // putchar(0x0A);
  }
  for (unsigned i(1); i <= 2000; ++i) {
    for (unsigned j(1); j <= 2000; ++j) Ans[i][j] += Ans[i][j - 1];
  }
  for (unsigned i(1); i <= 2000; ++i) {
    for (unsigned j(1); j <= 2000; ++j) Ans[i][j] += Ans[i - 1][j];
  }
  for (unsigned T(1); T <= t; ++T) {
    A = RD(), B = RD();
    printf("%u\n", Ans[A][B]);
  }
  //  system("pause");
  return Wild_Donkey;
}