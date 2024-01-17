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
const unsigned long long Mod(998244353), Inv26(729486258), _2526(268758096);
inline void Mn(unsigned long long &x) { x -= (x >= Mod) ? Mod : 0; }
inline void Mn(unsigned &x) { x -= (x >= Mod) ? Mod : 0; }
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
unsigned long long Fac[100005], Inv[100005];
char a[100005];
unsigned long long Palin, Ans(0);
unsigned m, n, t;
unsigned long long C(unsigned x, unsigned y) {
  return (Fac[x] * Inv[y] % Mod) * Inv[x - y] % Mod;
}
inline void Clr() {
  memset(a, 0, n + 1);
  scanf("%s", a + 1);
  n = strlen(a + 1), m = RD();
}
signed main() {
  freopen("T416105_10.in", "r", stdin);
  //  freopen(".out", "w", stdout);
  Fac[0] = 1;
  for (unsigned i(1); i <= 100000; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[100000] = Pow(Fac[100000], Mod - 2);
  for (unsigned i(100000); i; --i) Inv[i - 1] = Inv[i] * i % Mod;
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    unsigned Sam(0), Dif(0), Unk(0);
    for (unsigned i(1), j(n); i < j; ++i, --j) {
      if (a[i] ^ '?') {
        if (a[j] ^ '?') {
          if (a[i] ^ a[j]) ++Dif;
        } else
          ++Unk;
      } else
        ++Unk;
    }
    n = ((n + 1) >> 1), Sam = n - Dif - Unk;
    if (!Dif)
      Palin = Pow(Inv26, Unk);
    else
      Palin = 0;
    unsigned long long Cur(Pow(Inv26, Unk));
    Ans = 0;
    // printf("Dif %u Unk %u m %u Sam %u\n", Dif, Unk, m, Sam);
    for (unsigned i(Dif); i <= Dif + Unk; ++i, Cur = Cur * 25 % Mod) {
      // printf("i %u, n - i %u m %u i - Dif %u Unk %u\n", i, n - i, m, i - Dif,
      //  Unk);
      Ans = (Ans + (C(Unk, i - Dif) * Cur % Mod) *
                       (C(n, m) + ((n - i >= m) ? (Mod - C(n - i, m)) : 0))) %
            Mod;
    }
    Ans = Ans * Pow(C(n, m), Mod - 2) % Mod;
    Mn(Ans += Palin);
    printf("%llu\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}