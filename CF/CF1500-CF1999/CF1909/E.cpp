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
const unsigned long long Mod(998244353);
unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
    // printf("%u %u\n", x, )
  }
  return Rt;
}
vector<unsigned> Domi[200005], OK[20];
unsigned List[20];
unsigned m, n;
unsigned A, B;
unsigned t;
char HavAs;
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) Domi[i].clear();
  n = RD(), m = RD(), HavAs = 0;
}
unsigned Count(unsigned x, unsigned y) {
  x &= (1 << y) - 1;
  unsigned Rt(0);
  while (x) Rt += (x & 1), x >>= 1;
  return Rt;
}
void Prt(unsigned x, unsigned y) {
  printf("%u\n", Count(x, y));
  char Prtd(0);
  for (unsigned i(0); i < y; ++i)
    if (x & (1 << i)) {
      if (Prtd) putchar(' ');
      printf("%u", i + 1);
      Prtd = 1;
    }
  putchar(0x0A);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  // for (unsigned i(0); i < 5; ++i) printf("%u %llu %llu\n", i, Fac[i],
  // Inv[i]);
  for (unsigned i(1); i <= 19; ++i)
    for (unsigned j(i); j <= 19; j += i) List[i] |= 1 << (j - 1);
  for (unsigned I(5); I <= 19; ++I) {
    for (unsigned i((1 << I) - 1); i; --i) {
      unsigned Cur(0);
      for (unsigned j(1); j <= I; ++j)
        if (i & (1 << (j - 1))) Cur ^= List[j];
      A = Count(Cur, I);
      if (A * 5 <= I) OK[I].push_back(i);
    }
    // printf("%u: %u\n", I, OK[I].size());
  }
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= m; ++i) {
      A = RD(), B = RD();
      Domi[A].push_back(B);
    }
    if (n >= 20) {
      printf("%u\n", n);
      for (unsigned i(1); i < n; ++i) printf("%u ", i);
      printf("%u\n", n);
      continue;
    }
    if (n < 5) {
      printf("-1\n");
      continue;
    }
    for (auto i : OK[n]) {
      char Flg(0);
      for (unsigned j(1); j <= n; ++j)
        if (i & (1 << (j - 1))) {
          for (auto k : Domi[j]) {
            if (!(i & (1 << (k - 1)))) {
              Flg = 1;
              break;
            }
          }
          if (Flg) break;
        }
      if (Flg) continue;
      Prt(i, n), HavAs = 1;
      break;
    }
    if (!HavAs) printf("-1\n");
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
d_i = sum_{j | i} I_jI_{\frac ij}

di % 2 = 1

Exist j^2 = i

5 > sqrt n

19->1 4 9 16 NO
*/