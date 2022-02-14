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
unsigned a[10005], m(5), n(10), q(10000);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  freopen("P8120.in", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  srand(time(0));
  printf("%u %u %u %u\n", m, n, (m * (m + 1)) >> 1, 0);
  for (unsigned i(1); i <= m; ++i) a[i] = i;
  random_shuffle(a + 1, a + m + 1);
  for (unsigned i(1); i <= m; ++i) printf("%u ", a[i]);putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) printf("%u ", (rand() % m) + 1); putchar(0x0A);
  // for (unsigned i(1); i <= q; ++i) {
  //   A = (rand() % n) + 1, B = (rand() % n) + 1;
  //   if (A > B) swap(A, B);
  //   printf("%u %u\n", A, B);
  // }
  for (unsigned i(1); i <= m; ++i) {
    for (unsigned j(1); j <= i; ++j) printf("%u %u\n", j, i);
  }
  //  }
        //  system("pause");
  return Wild_Donkey;
}
