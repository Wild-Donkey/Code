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
inline unsigned long long RDll() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned long long A, B;
unsigned long long Ms[300005], Mx[1000005];
unsigned f[1000005], m, n;
unsigned C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), C = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RDll() * RD();
    Mx[A] = max(B, Mx[A]);
  }
  for (unsigned i(1); i < C; ++i) {
    Mx[i + 1] = max(Mx[i], Mx[i + 1]);
    for (unsigned j(C / i); j > 1; --j) Mx[j * i] = max(Mx[j * i], Mx[i] * j);
  }
  m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD() * RDll();
    unsigned L(0), R(C + 1), Mid;
    while (L < R) {
      Mid = ((L + R) >> 1);
      if (Mx[Mid] > A) R = Mid;
      else L = Mid + 1;
    }
    if (L > C) printf("-1 ");
    else printf("%u ", L);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
// t = h / D, xhd >= HD