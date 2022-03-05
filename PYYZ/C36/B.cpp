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
unsigned f[263005][18];
unsigned E[205][205], Pos[20], Dis[20][20], Ti[20], Range[20][2], Earn[20], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  memset(E, 0x3f, sizeof(E));
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD();
    E[B][A] = E[A][B] = min(E[A][B], C);
  }
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j < n; ++j) if (i ^ j) {
      for (unsigned k(j + 1); k <= n; ++k) if ((k ^ i) && (k ^ j)) {
        E[k][j] = E[j][k] = min(E[j][k], E[j][i] + E[i][k]);
      }
    }
  }
  for (unsigned i(1); i <= n; ++i) E[i][i] = 0;
  m = (1 << (n = RD()));
  for (unsigned i(0); i < n; ++i)
    Pos[i] = RD(), Range[i][0] = RD(), Range[i][1] = RD(), Ti[i] = RD(), Earn[i] = RD();
  for (unsigned i(0); i < n; ++i) for (unsigned j(i); j < n; ++j)
    Dis[i][j] = Dis[j][i] = E[Pos[i]][Pos[j]];
  // for (unsigned i(1); i <= n; ++i) for (unsigned j(i); j <= n; ++j) printf("(%u %u) %u\n", i, j, Dis[i][j]);
  for (unsigned i(0); i < n; ++i) {
    if (E[1][Pos[i]] <= Range[i][1]) f[1 << i][i] = max(E[1][Pos[i]], Range[i][0]) + Ti[i];
    else f[1 << i][i] = 0x3f3f3f3f;
    // printf("%u ", f[1 << i][i]);
  }
  // putchar(0x0A);
  for (unsigned i(1); i < m; ++i) {
    for (unsigned j(0); j < n; ++j) if ((i >> j) & 1) {
      unsigned Fr(i ^ (1 << j)), Er(0x3f3f3f3f), Choi(100);
      if (!Fr) break;
      for (unsigned k(0); k < n; ++k) if ((Fr >> k) & 1)
        if (Er > f[Fr][k] + Dis[k][j]) Er = f[Fr][k] + Dis[k][j], Choi = k;
      if (Er <= Range[j][1]) f[i][j] = max(Er, Range[j][0]) + Ti[j];
      else f[i][j] = 0x3f3f3f3f;
    }
  }
  for (unsigned i(0); i <= m; ++i) {
    char Flg(0);
    for (unsigned j(0); j < n; ++j) if (((i >> j) & 1) && f[i][j] < 0x3f3f3f3f) Flg = 1;
    if (!Flg) continue;
    unsigned Tmp(0);
    for (unsigned j(0); j < n; ++j) if ((i >> j) & 1) Tmp += Earn[j];
    Ans = max(Ans, Tmp);
  }
  printf("%u\n", Ans);
  //  }
//  system("pause");
  return Wild_Donkey;
}