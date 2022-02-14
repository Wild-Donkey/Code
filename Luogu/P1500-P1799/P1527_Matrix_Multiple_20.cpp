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
unsigned a[505][505], Dif[505][505], b[250005], Ans[60005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Qry {
  unsigned L, U, R, D, K, Num;
  inline unsigned Ct() { return Dif[R][D] + Dif[L - 1][U - 1] - Dif[L - 1][D] - Dif[R][U - 1]; }
}Q[60005];
inline void Count(unsigned x) {
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) Dif[i][j] = (a[i][j] <= x);
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) Dif[i][j] += Dif[i - 1][j];
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) Dif[i][j] += Dif[i][j - 1];
}
inline void Solve(unsigned L, unsigned R, unsigned Ql, unsigned Qr) {
  if (L == R) { for (unsigned i(Ql); i <= Qr; ++i) Ans[Q[i].Num] = L; return; }
  if (Ql > Qr) return;
  unsigned Mid((L + R) >> 1), Bot(Ql);
  Count(b[Mid]);
  for (unsigned i(Ql); i <= Qr; ++i) if (Q[i].Ct() >= Q[i].K) swap(Q[Bot++], Q[i]);
  Solve(L, Mid, Ql, Bot - 1);
  Solve(Mid + 1, R, Bot, Qr);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) b[++Cnt] = a[i][j] = RD();
  for (unsigned i(1); i <= m; ++i)
    Q[i].L = RD(), Q[i].U = RD(), Q[i].R = RD(), Q[i].D = RD(), Q[i].K = RD(), Q[i].Num = i;
  sort(b + 1, b + Cnt + 1), Cnt = unique(b + 1, b + Cnt + 1) - b;
  Solve(1, Cnt - 1, 1, m);
  for (unsigned i(1); i <= m; ++i) printf("%u\n", b[Ans[i]]);
  //  }
  //  system("pause");
  return Wild_Donkey;
}