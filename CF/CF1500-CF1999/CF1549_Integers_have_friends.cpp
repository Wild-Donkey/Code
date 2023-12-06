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
unsigned long long Ans, a[200005], LM[200005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0);
inline unsigned long long ABS(unsigned long long x, unsigned long long y) {
  return (x > y) ? (x - y) : (y - x);
}
inline unsigned long long Gcd(unsigned long long x, unsigned long long y) {
  unsigned long long GTmp;
  while (y) { GTmp = x, x = y, y = GTmp % x; }
  return x;
}
inline void Clr() { n = RD(), Cnt = 0, a[0] = 0; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    for (unsigned i(n); i; --i) a[i] = ABS(a[i], a[i - 1]);
    unsigned L(1), R(1), Mid(1);
    Ans = 0, a[1] = LM[0] = 1;
    // for (unsigned i(1); i <= n; ++i) printf("%llu ", a[i]);
    // putchar(0x0A);
    for (; R <= n; Ans = Gcd(a[++R], Ans)) {
      while ((L < Mid) && (1 == Gcd(Ans, LM[Mid - L]))) ++L;
      if (Gcd(Ans, LM[Mid - L]) ^ 1) {
        --L, Cnt = max(Cnt, R - L);
        continue;
      }
      L = Mid = R, Ans = 0, LM[0] = a[L];
      while (LM[Mid - L] ^ 1) --L, LM[Mid - L] = Gcd(LM[Mid - L - 1], a[L]);
      Cnt = max(Cnt, R - L);
    }
    printf("%u\n", Cnt + 1);
  }
  //  system("pause");
  return Wild_Donkey;
}