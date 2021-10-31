#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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
const unsigned long long Ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
unsigned long long Ans(0), a[15], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline void Clr() {
  n = RD(), m = RD() + 1;
  Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    for (unsigned i(2); (i <= n) && m; ++i) {
      unsigned long long Now((Ten[a[i]] / Ten[a[i - 1]]) - 1);
      if(Now <= m) m -= Now, Ans += Ten[a[i - 1]] * Now;
      else Ans += Ten[a[i - 1]] * m, m = 0;
    }
    if(m) Ans += Ten[a[n]] * m;
    printf("%llu\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}

