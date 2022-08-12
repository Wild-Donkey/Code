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
const unsigned Mod(998244353);
inline void Mn(unsigned& x) { x -= (x >= Mod) ? Mod : 0; }
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
unsigned f[200005], Ans[200005], l, r, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline void Clr() {
  memset(Ans, 0, (n + 1) << 2);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  n = RD(), r = l = RD(), Cnt = Tmp = 0, f[0] = 1;
  while (Tmp < n) Tmp += (r++);
  // printf("%u\n", Cnt);
  for (unsigned i(l); i <= r; ++i) {
    for (unsigned j(n); j >= i; --j) f[j] = f[j - i];
    for (unsigned j(0); j < i; ++j) f[j] = 0;
    for (unsigned j(i); j <= n; ++j) Mn(f[j] += f[j - i]), Mn(Ans[j] += f[j]);
    // for (unsigned j(1); j <= n; ++j) printf("%u ", f[j]); putchar(0x0A);
  }
  for (unsigned i(1); i <= n; ++i) printf("%u ", Ans[i]); putchar(0x0A);
  //  system("pause");
  return Wild_Donkey;
}