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
#define foreplay for
#define wild while
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
char No[200005];
unsigned Pri[30005], Big[200005];
unsigned a[200005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned long long Ans(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  Big[1] = 1;
  for (unsigned i(2); i <= 200000; ++i) {
    if (!No[i]) Big[i] = i, Pri[++Cnt] = i;
    for (unsigned j(1), J(i << 1); j <= Cnt && J <= 200000;
         J = (Pri[++j] * i)) {
      Big[J] = Pri[j], No[J] = 1;
      if (!(i % Pri[j])) break;
    }
  }
  // for (unsigned i(1); i <= 100; ++i) printf("%u\n", Pri[i]);
  // for (unsigned i(1); i <= 100; ++i) printf("%u Big %u\n", i, Big[i]);
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = 1;
    if (!A) {
      ++D;
      continue;
    }
    while (No[A]) {
      C = Big[A];
      A /= C;
      if (A % C)
        B *= C;
      else
        A /= C;
    }
    B *= A;
    ++a[B];
  }
  Ans = (unsigned long long)D * ((n - 1) + (n - D));
  for (unsigned i(1); i <= 200000; ++i) {
    if (a[i] > 1) Ans += (unsigned long long)a[i] * (a[i] - 1);
    // printf("%llu\n", Ans);
  }
  printf("%llu\n", Ans >> 1);
  //  }
  //  system("pause");
  return Wild_Donkey;
}