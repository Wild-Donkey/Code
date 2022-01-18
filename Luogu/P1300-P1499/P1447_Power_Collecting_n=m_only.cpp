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
unsigned long long Sum[100005], Ans(0);
unsigned Prime[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
bitset<100005> Isnt;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Sum[1] = 1;
  if (n < m) swap(n, m);
  for (unsigned i(2); i <= n; ++i) {
    if (!Isnt[i]) Prime[++Cnt] = i, Sum[i] = i - 1;
    for (unsigned j(1); (j <= Cnt) && (Prime[j] * i <= n); ++j) {
      unsigned Des(Prime[j] * i);
      Isnt[Des] = 1, Sum[Des] = Sum[Prime[j]] * Sum[i];
      if (!(i % Prime[j])) { Sum[Des] /= Prime[j] - 1, Sum[Des] *= Prime[j]; break; }
    }
  }
  // for (unsigned i(1); i <= n; ++i) printf("%u ", Sum[i]);putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) Sum[i] += Sum[i - 1];
  // for (unsigned i(1); i <= n; ++i) printf("%u ", Sum[i]);putchar(0x0A);
  for (unsigned i(1); i <= m; ++i) Ans += (Sum[m / i] + Sum[n / i] - 1) * i;
  // printf("%llu\n", Ans);
  printf("%llu\n", (Ans << 1) - ((unsigned long long)n * m));
  //  }
  // system("pause");
  return Wild_Donkey;
}