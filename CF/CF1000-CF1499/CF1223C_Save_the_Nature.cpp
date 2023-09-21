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
unsigned a[200005], n;
unsigned A, B, C, D, E, Rate3, t;
unsigned long long Ans(0);
inline void Clr() { n = RD(); }
inline unsigned Gcd(unsigned x, unsigned y) { return y ? Gcd(y, x % y) : x; }
inline char Check(unsigned x) {
  unsigned Type0(x / E), Type1((x / B) - Type0), Type2((x / D) - Type0), Cnt(0);
  unsigned long long Tot(0);
  for (unsigned i(1); i <= Type0; ++i) Tot += Rate3 * a[n - (Cnt++)];
  for (unsigned i(1); i <= Type1; ++i) Tot += A * a[n - (Cnt++)];
  for (unsigned i(1); i <= Type2; ++i) Tot += C * a[n - (Cnt++)];
  return Tot >= Ans;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD() / 100;
    sort(a + 1, a + n + 1);
    A = RD(), B = RD(), C = RD(), D = RD();
    Ans = RDll(), Rate3 = A + C;
    if (A < C) swap(A, C), swap(B, D);
    unsigned long long Tmp((unsigned long long)D * (B / Gcd(B, D)));
    E = (Tmp > n) ? (n + 1) : Tmp;
    if (!Check(n)) {
      printf("-1\n");
      continue;
    }
    unsigned L(1), R(n), Mid;
    while (L ^ R) {
      Mid = ((L + R) >> 1);
      if (Check(Mid))
        R = Mid;
      else
        L = Mid + 1;
    }
    printf("%u\n", L);
  }
  //  system("pause");
  return Wild_Donkey;
}