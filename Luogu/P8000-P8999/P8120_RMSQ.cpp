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
unsigned fPool[300000000], Len[300005], Mx[1005][1005];
unsigned a[300005], Pos[300005], m, n, q;
unsigned Stack[2005], STop(0);
unsigned A, B, C, D, TmpM;
unsigned PrA, PrB;
unsigned Cnt(0), Ans(0), Tmp(0);
char Use(0);
inline unsigned* f(const unsigned x, const unsigned y, const unsigned z) {
  return fPool + x * PrA + y * PrB + z;
}
signed main() {
  n = RD(), m = RD(), q = RD(), Use = RD(), B = min(m, (unsigned)max((double)m * m / 300001000, (m / sqrt(q))) + 1), A = m / B;
  PrB = B + 1, PrA = PrB * (A + 1);
  for (unsigned i(1); i <= n; ++i) Pos[RD()] = i;
  for (unsigned i(1); i <= m; ++i) a[i] = Pos[RD()];
  for (unsigned i(0); i < A; ++i) {
    memset(Len, 0, ((n + 1) << 2)), TmpM = 0;
    for (unsigned j(i), k = (i * B + 1); j < A; ++j) {
      unsigned* CuPo(f(i, j, 1));
      for (unsigned Cou(1); Cou <= B; ++Cou, ++k, ++CuPo) {
        unsigned Cur(a[k]), Pre(Len[Cur - 1] + 1);
        Len[Cur] = max(Pre, Len[Cur]), TmpM = max(TmpM, Len[Cur]);
        if (j > i) (*CuPo) = Len[Cur];
      }
      Mx[i][j] = TmpM;
    }
    unsigned* CuPo(f(i, A, 1));
    for (unsigned k(A* B + 1); k <= m; ++k, ++CuPo) {
      unsigned Cur(a[k]), Pre(Len[Cur - 1] + 1);
      Len[Cur] = max(Pre, Len[Cur]), (*CuPo) = Len[Cur];
    }
  }
  for (unsigned i(A - 1); i; --i) {
    memset(Len, 0, ((n + 1) << 2));
    for (unsigned j(i), k = ((i + 1) * B); ~j; --j) {
      unsigned* CuPo(f(A - j - 1, A - i, 1));
      for (unsigned Cou(1); Cou <= B; ++Cou, --k, ++CuPo) {
        unsigned Cur(a[k]), Pre(Len[Cur + 1] + 1);
        Len[Cur] = max(Pre, Len[Cur]);
        if (j < i) (*CuPo) = Len[Cur];
      }
    }
  }
  memset(Len, 0, ((n + 1) << 2));
  for (unsigned i(1); i <= q; ++i) {
    if (!Use) Ans = 0;
    C = (RD() ^ Ans), D = (RD() ^ Ans), Ans = 0;
    unsigned L((C + B - 2) / B), R(D / B);
    if (L >= R) {
      for (unsigned i(C); i <= D; ++i) {
        unsigned Cur(a[i]), Pre(Len[Cur - 1] + 1);
        Stack[++STop] = Cur, Ans = max(Ans, Len[Cur] = max(Len[Cur], Pre));
      }
      while (STop) Len[Stack[STop--]] = 0;
      printf("%u\n", Ans); continue;
    }
    --R, Ans = max(Ans, Mx[L][R]), C = (L * B) - C + 1, D -= (R + 1) * B;
    unsigned* CuPo(f(L, R + 1, 1));
    for (unsigned j(1), p(((R + 1)* B) + 1); j <= D; ++j, ++p, ++CuPo) {
      unsigned TheL(*CuPo), Le(a[p] - TheL + 1);
      Ans = max(Ans, TheL);
      Stack[++STop] = Le, Len[Le] = max(Len[Le], TheL);
    }
    for (unsigned j(1), p(L* B); j <= C; ++j, --p) {
      unsigned Cur(a[p]), Pre(Len[Cur + 1] + 1);
      Stack[++STop] = Cur, Ans = max(Ans, Len[Cur] = max(Len[Cur], Pre));
    }
    while (STop) Len[Stack[STop--]] = 0;
    CuPo = f(A - L, A - R, 1);
    for (unsigned j(1); j <= C; ++j, ++CuPo) Ans = max(Ans, *CuPo);
    printf("%u\n", Ans);
  }
  return Wild_Donkey;
}