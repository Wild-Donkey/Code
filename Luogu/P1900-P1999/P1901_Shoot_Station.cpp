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
unsigned a[1000005], b[1000005];
unsigned c[1000005];
unsigned Stack[1000005], * Top(Stack);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Ans(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    a[i] = RD();
    b[i] = RD();
  }
  for (unsigned i(1); i <= n; ++i) {
    while (Top > Stack && a[*Top] < a[i]) c[i] += b[*Top], --Top;
    *(++Top) = i;
  }
  Top = Stack;
  for (unsigned i(n); i; --i) {
    while (Top > Stack && a[*Top] < a[i]) c[i] += b[*Top], --Top;
    *(++Top) = i;
  }
  for (unsigned i(1); i <= n; ++i) Ans = max(Ans, c[i]);
  printf("%u\n", Ans);
  //  }
//  system("pause");
  return Wild_Donkey;
}