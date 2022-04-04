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
unsigned long long f[1000005];
unsigned a[10005], b[10005], m(0), n;
unsigned long long Ans(0x3f3f3f3f3f3f3f3f);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD() - 1, A = RD();
  for (unsigned i(1); i <= n; ++i) b[i] = (B = RD()) - A, A = B;
  sort(b + 1, b + n + 1);
  memset(f, 0x3f, sizeof(f)), f[0] = 0;
//  for (unsigned i(1); i <= n; ++i) printf("%u ", b[i]); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) a[i] = a[i - 1] + b[i];
  for (unsigned i(1); i <= n; ++i) {
    Tmp = m + max(i * b[i], a[i]);
//    printf("Cond %u from %u\n", Tmp, m);
    unsigned long long g[Tmp + 1];
    memset(g, 0x3f, (Tmp + 1) << 3);
    unsigned aa(a[i] * a[i]), bb(b[i] * b[i]);
    for (unsigned j(0); j <= m; ++j) {
      unsigned long long &To(g[j + a[i]]), &To1(g[j + i * b[i]]);
      To = min(To, f[j] + aa);
      To1 = min(To1, f[j] + (unsigned long long)i * bb + ((j * b[i]) << 1));
    }
//    for (unsigned j(0); j <= Tmp; ++j) printf("%llu ", g[j]); putchar(0x0A);
    memcpy(f, g, (Tmp + 1) << 3), m = Tmp;
  }
//  for (unsigned i(0); i <= m; ++i) printf("%llu ", f[i]); putchar(0x0A);
  for (unsigned i(0); i <= m; ++i) if(f[i] < 0x3f3f3f3f3f3f3f3f) Ans = min(Ans, (n + 1) * f[i] - (unsigned long long)i * i);
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
//0 1 3 5
