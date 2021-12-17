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
unsigned long long Mod(1000000007);
unsigned long long f[66000], g[66000];
unsigned long long Tmp(0);
unsigned N, a[20][20], n;
signed main() {
  N = 1 << (n = RD()), f[0] = 1;
  for (unsigned i(0); i < n; ++i) for (unsigned j(0); j < n; ++j) a[i][j] = RD() + 1;
  for (unsigned i(0); i < N; ++i) {
    g[i] = 1;
    for (unsigned j(0); j < n; ++j) if (i & (1 << j))
      for (unsigned k(0); k < j; ++k) if (i & (1 << k))
        g[i] = g[i] * a[j][k] % Mod;
  }
  for (unsigned i(1); i < N; ++i, Tmp = 0) {
    for (unsigned j((i - 1)& i); j; j = i & (j - 1)) if (j > (i ^ j))
      Tmp = (Tmp + f[j] * g[i ^ j]) % Mod;
    f[i] = Mod + g[i] - Tmp;
    if (f[i] >= Mod) f[i] -= Mod;
  }
  printf("%llu\n", f[N - 1]);
  return Wild_Donkey;
}