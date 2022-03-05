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
bitset<50005> No;
unsigned Prime[10005], CntP(0);
unsigned List[50005], CntL(0);
unsigned m, n;
unsigned A(1), B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void DFS(unsigned Dep) {
  // printf("A%u %u\n", A, Dep);
  if ((Dep > CntP) || ((2500000000 / A) < Prime[Dep])) return;
  A *= Prime[Dep], ++CntL;
  if (!(CntL % 10000)) printf("%u\n", CntL);
  DFS(Dep + 1);
  A /= Prime[Dep];
  DFS(Dep + 1);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = 50000;
  for (unsigned i(2); i <= n; ++i) {
    // printf("FAQ %u\n", i);
    if (!No[i]) Prime[++CntP] = i;
    for (unsigned j(1); (Prime[j] * i <= n) && (j <= CntP); ++j) {
      No[i * Prime[j]] = 1;
      if (!(i % Prime[j])) break;
    }
  }
  printf("Done %u\n", CntP);
  DFS(1);
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    // a[i] = RD();
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}