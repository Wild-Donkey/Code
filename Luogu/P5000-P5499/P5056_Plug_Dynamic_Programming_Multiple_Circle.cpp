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
unsigned f[13][12][4105], List[8205], Find[4105], Con(0), m, n, N;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[13][13], Flg(0);
inline void Nxt(unsigned& x, unsigned& y) {
  if (y + 1 >= m) ++x, y = 0;
  else ++y;
}
inline void Lst(unsigned& x, unsigned& y) {
  if (y) --y;
  else --x, y = m - 1;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), N = (1 << (m = RD()) + 1);
  for (unsigned i(1); i <= n; ++i) scanf("%s", a[i]);
  for (unsigned i(1); (i <= n) && (!Flg); ++i) for (unsigned j(0); j < m; ++j)
    if (a[i][j] ^ '*') { Flg = 1, A = i, B = j;break; }
  if (!Flg) { printf("1\n"); return 0; } Flg = 0;
  for (unsigned i(n); i && (!Flg); --i) for (unsigned j(m - 1); ~j; --j)
    if (a[i][j] ^ '*') { Flg = 1, C = i, D = j;break; }
  for (unsigned i(0); i < N; ++i) {
    for (unsigned j(Cnt = 0); j <= m; ++j) if ((i >> j) & 1) ++Cnt;
    if (!(Cnt & 1)) Find[List[i] = ++Con] = i;
  }
  printf("Con %u\n", Con);
  Lst(A, B), f[A][B][1] = 1, Nxt(C, D);
  unsigned Pli(A), Plj(B); Nxt(Pli, Plj);
  for (unsigned i(A), j(B); (i ^ C) || (j ^ D); i = Pli, j = Plj, Nxt(Pli, Plj)) {
    printf("Do (%u, %u)\n", i, j);
    for (unsigned k(1); k <= Con; ++k) if (f[i][j][k]) {
      unsigned Cur(Find[k]), To;
      char Up(0), Lef(0);
      if ((Cur >> Plj) & 1) Up = 1;
      if ((Cur >> m) & 1) Lef = 1;
      if ((Up ^ Lef) && (!(Lef && (Plj == m - 1)))) f[Pli][Plj][k] += f[i][j][k];
      To = (Cur ^ (1 << m));
      To ^= 1 << Plj;
      f[Pli][Plj][List[To]] += f[i][j][k];
      printf("(%u %u)", Cur, f[i][j][k]);
    }
    putchar(0x0A);
  }
  Lst(C, D); printf("%u\n", f[C][D][1]);
  //  }
    //  system("pause");
  return Wild_Donkey;
}
/*
2 2
..
..
**..
....
*/