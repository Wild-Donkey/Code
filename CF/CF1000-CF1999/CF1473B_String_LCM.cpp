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
unsigned m, n, M, N;
unsigned C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[25], b[25], A[405], B[405], Flg;
inline void Clr() {
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(A, 0, sizeof(A));
  memset(B, 0, sizeof(B));
  scanf("%s%s", a + 1, b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  N = 20 * n, M = 20 * m;
  Flg = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(0); i < 20; ++i) memcpy(A + (n * i) + 1, a + 1, n);
    for (unsigned i(0); i < 20; ++i) memcpy(B + (m * i) + 1, b + 1, m);
    for (unsigned i(1); i <= N; ++i) {
      if (A[i] ^ B[i]) { Flg = 1; break; }
      if ((!(i % n)) && (!(i % m))) { for (unsigned j(1); j <= i; ++j) putchar(A[j]); putchar(0x0A); break; }
      if ((i == N) || (i == M)) { Flg = 1; break; }
    }
    if (Flg) printf("-1\n");
  }
  // system("pause");
  return Wild_Donkey;
}