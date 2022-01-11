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
const unsigned Mod(59393);
unsigned a[15], g[3005], f[3005][3005], Ch[3005][3005], m, n;
unsigned Way[3005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
set<pair<unsigned, unsigned> > S;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(0); i <= m; ++i) a[i] = RD();
  for (unsigned i(0); i <= n; ++i) {
    g[i] = 0;
    for (unsigned j(0), k(1); j <= m; ++j) g[i] = (g[i] + k * a[j]) % Mod, k = k * i % Mod;
  }
  if (n == 1) { printf("%u %u\n", 0, g[0]); return 0; }
  for (unsigned i(1); i <= n; ++i)  for (unsigned j(n - 2); ~j; --j) {
    for (unsigned k(0); k <= j; ++k) {
      unsigned Des(f[i - 1][j - k] + g[k + 1]);
      if (f[i][j] < Des) f[i][j] = Des, Ch[i][j] = k;
    }
  }
  for (unsigned i(n), j(n - 2); i; --i) Way[i] = 1 + Ch[i][j], j -= Ch[i][j];
  // printf("Done %u\n", f[n][n - 2]);
  printf("%u %u\n", n - 1, f[n][n - 2]);
  // for (unsigned i(1); i <= n; ++i) printf("%u ", Way[i]); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) S.insert(make_pair(Way[i], i));
  for (unsigned i(1); i < n; ++i) {
    unsigned Nu((S.rbegin())->second), No((S.rbegin())->first);
    S.erase(make_pair(No, Nu));
    unsigned Num((S.begin())->second), Now((S.begin())->first);
    S.erase(S.begin());
    printf("%u %u\n", Num, Nu);
    // printf("Sub %u %u\n", Now, No);
    if (No > 1) S.insert(make_pair(No - 1, Nu));
  }
  //  }
  // system("pause");
  return Wild_Donkey;
}