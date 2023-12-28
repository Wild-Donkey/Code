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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
unsigned long long a[200005], K, Ans;
unsigned m, n;
unsigned t;
char Flg;
inline void Clr() { n = RD(), K = RD(), Flg = 0, Ans = 0; }
unsigned long long Gcd(unsigned long long x, unsigned long long y) {
  unsigned long long GTmp;
  while (y) GTmp = x, x = y, y = GTmp % y;
  return x;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      a[i] = RD();
      if (a[i] > K) Flg |= 4;
      if (a[i] < K) Flg |= 2;
      if (a[i] == K) Flg |= 1;
    }
    if (Flg == 1) {
      printf("0\n");
      continue;
    }
    if (!(Flg == 2 || Flg == 4)) {
      printf("-1\n");
      continue;
    }
    if (Flg == 2)
      for (unsigned i(1); i <= n; ++i) a[i] = K - a[i];
    else
      for (unsigned i(1); i <= n; ++i) a[i] -= K;
    K = 0;
    for (unsigned i(1); i <= n; ++i) K = Gcd(K, a[i]);
    for (unsigned i(1); i <= n; ++i) Ans += (a[i] / K) - 1;
    printf("%llu\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
x -> a b (a + b = x)
*/