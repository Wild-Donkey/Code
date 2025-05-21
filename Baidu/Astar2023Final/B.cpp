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
const unsigned long long Mod(1000000007);
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
struct Inf {
  unsigned Pls, Tm;
  char Type;
  inline const char operator<(const Inf &x) const { return Tm < x.Tm; }
} I[2000005];
unsigned m, n, S, T, M(0);
unsigned A, B, C, D;
unsigned Cnt(0);
unsigned long long Ans(1);
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  Clr();
  Cnt = n = RD(), m = RD(), S = RD(), T = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), C = RD(), D = RD();
    if (C > D) continue;
    I[++M] = {A, C, 0};
    I[++M] = {A, D + 1, 1};
  }
  sort(I + 1, I + M + 1);
  // printf("")
  for (unsigned i(1); i <= M;) {
    unsigned Now(I[i].Tm);
    Ans = Ans * Pow(Cnt, Now - S) % Mod;
    while (I[i].Tm == Now) {
      if (I[i].Type)
        ++Cnt;
      else
        --Cnt;
      ++i;
    }
    S = Now;
  }
  Ans = Ans * Pow(Cnt, T - S + 1) % Mod;
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}