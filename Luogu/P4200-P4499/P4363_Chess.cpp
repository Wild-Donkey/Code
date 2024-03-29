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
#define Lbt(x) ((x)&((~(x))+1))
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
unordered_map <unsigned, unsigned> Find;
int a[15][15], b[15][15], f[200005];
unsigned List[200005], Step[200005];
unsigned m, n, nm, Bnm;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned PpC(unsigned x) {
  unsigned PRt(0);
  for (;x;x -= Lbt(x)) ++PRt;
  return PRt;
}
inline void DFS(unsigned Now, unsigned Dep, unsigned Used) {
  if (Dep == nm) {
    if (Used == m) List[++Cnt] = Now, Find[Now] = Cnt;
    return;
  }
  if (Used > m) return;
  DFS(Now, Dep + 1, Used);
  DFS(Now | (1 << Dep), Dep + 1, Used + 1);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Bnm = (1 << ((nm = n + m) - 1)) - 1;
  if ((n * m) & 1) {
    for (unsigned i(n); i; --i) for (unsigned j(m); j; --j) a[i][j] = RD();
    for (unsigned i(n); i; --i) for (unsigned j(m); j; --j) b[i][j] = RD();
  }
  else {
    for (unsigned i(n); i; --i) for (unsigned j(m); j; --j) b[i][j] = RD();
    for (unsigned i(n); i; --i) for (unsigned j(m); j; --j) a[i][j] = RD();
  }
  DFS(0, 0, 0);
  for (unsigned i(1); i <= Cnt; ++i) for (unsigned j(0), Thi(n); j < nm; ++j)
    if (List[i] & (1 << j)) Step[i] += Thi; else --Thi;
  for (unsigned i(2); i <= Cnt; ++i) {
    unsigned Now(List[i]), Need(((~Now) >> 1) & Now & Bnm);
    if (Step[i] & 1) {
      f[i] = 0xafafafaf;
      for (unsigned j(Need); j; j -= Lbt(j)) {
        unsigned Dest(Find[Now ^ (3 * Lbt(j))]);
        // printf("Need %u, %u -> %u\n", Need, Dest, i);
        f[i] = max(f[i], f[Dest] + a[n - PpC((Lbt(j) - 1) & (~Now))][1 + PpC((Lbt(j) - 1) & Now)]);
        // printf("Location (%u, %u)\n", n - PpC((Lbt(j) - 1) & (~List[Dest])), 1 + PpC((Lbt(j) - 1) & List[Dest]));
      }
    }
    else {
      f[i] = 0x3f3f3f3f;
      for (unsigned j(Need); j; j -= Lbt(j)) {
        unsigned Dest(Find[Now ^ (3 * Lbt(j))]);
        // printf("Need %u, %u -> %u\n", Need, Dest, i);
        f[i] = min(f[i], f[Dest] - b[n - PpC((Lbt(j) - 1) & (~Now))][1 + PpC((Lbt(j) - 1) & Now)]);
      }
    }
  }
  // for (unsigned i(1); i <= Cnt; ++i) printf("%u %u %u %d\n", i, List[i], Step[i], f[i]);
  printf("%d\n", ((n * m) & 1) ? f[Cnt] : (-f[Cnt]));
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
REMOVE BEFORE FLIGHT
*/