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
unsigned a[10005], m, n;
unsigned long long A, B, C, D;
unsigned t;
unsigned long long Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  D = RD(), A = RD(), B = RD(), C = RD(), n = RD();
  Tmp = Cnt = Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      Cnt += min(Tmp, C);
      Tmp -= min(Tmp, C);
      Cnt += A * D + C;
      Tmp += A * D * B - C;
      if (Tmp >= 40000000000) Tmp = 40000000000;
      Ans = max(Ans, Cnt + min(C * ((n - i) << 2), Tmp));
    }
    printf("%llu\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}