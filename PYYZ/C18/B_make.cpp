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
long long Sum[50005], f[50005];
unsigned g[50005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Calc() {
  f[0] = 0xafafafafafafafaf;
  for (unsigned i(1); i <= n; ++i) {
    f[i] = 0x3f3f3f3f3f3f3f3f;
    for (unsigned j(0); j < i; ++j) if (f[i] > max(f[j], Sum[i] - Sum[j]))
      f[i] = max(f[j], Sum[i] - Sum[j]), g[i] = j;
    printf("%u ", g[i]);
  }
  putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) printf("%lld ", f[i]); putchar(0x0A);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  freopen("B.in", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  srand(time(0));
  n = 20, m = 1;
  printf("%u %u\n", n, m);
  for (unsigned i(1); i <= n; ++i) printf("%d ", (rand() << 1) - rand()); putchar(0x0A);
  //  }
  // system("pause");
  return Wild_Donkey;
}