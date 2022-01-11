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
const unsigned Top(1000000);
unsigned Prime[200005], Phi[1000005], Cnt(0);
unsigned a[1000005], List[2005], Div(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Ans(0), Tmp(0);
bitset <1000005> No;
char Flg(0);
unsigned GCD(unsigned x, unsigned y) {
  unsigned TG;
  while (y) TG = x, x = y, y = TG % y;
  return x;
}
unsigned Pow(unsigned x, unsigned y) {
  unsigned long long RP(1);
  // printf("%llu %u: ", x, y);
  while (y) {
    if (y & 1) RP = RP * x % n;
    x = (unsigned long long)x * x % n, y >>= 1;
  }
  // printf("%u\n", RP);
  return RP;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  // freopen("PRM.out", "w", stdout);
  //  Clr();
  Phi[0] = 0, Phi[1] = 1;
  for (unsigned i(2); i <= Top; ++i) {
    if (!No[i]) Prime[++Cnt] = i, Phi[i] = i - 1;
    for (unsigned j(1), Des(i* Prime[j]); j <= Cnt, Des <= Top; ++j, Des = i * Prime[j]) {
      Phi[Des] = Phi[i] * Phi[Prime[j]], No[Des] = 1;
      if (!(i % Prime[j])) { Phi[Des] = Phi[Des] * Prime[j] / (Prime[j] - 1); break; }
    }
  }
  // for (unsigned i(1); i <= Top; ++i) printf("%d ", Phi[i]);putchar(0x0A);
  // for (unsigned i(1); i <= Cnt; ++i) printf("%d ", Prime[i]);putchar(0x0A);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    n = RD(), m = RD(), Div = Ans = 0;
    if (n == 2) {
      printf("1\n");
      if (m == 1) printf("1");
      putchar(0x0A);
      continue;
    }
    if (n == 4) {
      printf("1\n");
      if (m == 1) printf("3");
      putchar(0x0A);
      continue;
    }
    Tmp = (n & 1) ? n : (n >> 1);
    if (!(Tmp & 1)) { printf("0\n\n");continue; }
    for (unsigned i(1); i <= Cnt; ++i) if (!(Tmp % Prime[i])) {
      while (!(Tmp % Prime[i])) Tmp /= Prime[i]; break;
    }
    if (Tmp > 1) { printf("0\n\n");continue; }
    for (unsigned i(sqrt(Phi[n])); i; --i) if (!(Phi[n] % i)) {
      List[++Div] = i;
      if ((i * i) ^ Phi[n]) List[++Div] = Phi[n] / i;
    }
    for (unsigned i(1); i <= n; ++i) {
      if (GCD(i, n) > 1) continue;
      Flg = 0;
      for (unsigned j(1); j < Div; ++j) if (Pow(i, List[j]) == 1) { Flg = 1;break; }
      if (Flg) continue;
      a[++Ans] = i;
      break;
    }
    for (unsigned i(2); i < Phi[n]; ++i) if (GCD(i, Phi[n]) == 1) a[++Ans] = Pow(a[1], i);
    sort(a + 1, a + Ans + 1);
    printf("%u\n", Ans);
    for (unsigned i(m); i <= Ans; i += m) printf("%u ", a[i]);putchar(0x0A);
  }
  // system("pause");
  return Wild_Donkey;
}
/*
2^11753%23497=32
1
23497 101
1
25 1
6
2 1
4 1
25 2
36 1
9 6
18 1
*/