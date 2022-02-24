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
long long a[5005], f[5005], m, Ans(0);
unsigned n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Ava[51], Flg;
inline void Clr() {
  n = RD(), m = RD(), Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i)
      a[i] = RDsg(), Ans = max(Ans, f[i] = max(a[i] + f[i - 1], (long long)0));
    printf("%lld ", Ans);
    for (unsigned i(1); i <= n; ++i) {
      long long Now(0xafafafafafafafaf);
      for (unsigned j(n); j >= i; --j) Now = max(Now, f[j] = f[j - 1] + a[j]);
      // for (unsigned j(n); j >= i; --j) printf("%lld ", f[j]);putchar(0x0A);
      Now += m * i, Ans = max(Ans, Now);
      printf("%lld ", Ans);
    }
    putchar(0x0A);
  }
  //  system("pause");
  return Wild_Donkey;
}