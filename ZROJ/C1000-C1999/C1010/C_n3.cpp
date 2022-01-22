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
#include <string>
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
const unsigned STsk(705);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
bitset<STsk> f[STsk][STsk], Beat[STsk], Beaten[STsk];
char Ia[2005];
signed main() {
//  freopen("ex_C4.in", "r", stdin);
//  freopen("C.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", Ia + 1);
    for (unsigned j(1); j <= n; ++j) Beat[i][j] = Ia[j] - '0';
    Beaten[i] = ~Beat[i];
  }
  for (unsigned i(1); i <= n; ++i) f[1][i][i] = 1;
  for (unsigned Len(2); Len <= n; ++Len) {
    for (unsigned i(n - Len + 1); i; --i) {
      f[Len][i][i] = ((f[Len - 1][i + 1] & Beat[i]).count()) ? 1 : 0;
      f[Len][i][i + Len - 1] = ((f[Len - 1][i] & Beat[i + Len - 1]).count()) ? 1 : 0;
      for (unsigned k(i + Len - 2); k > i; --k) {
        f[Len][i][k] = f[k - i + 1][i][k] & f[i + Len - k][k][k];
        printf("[%u, %u] %u -> %u\n", i, i + Len - 1, k, (unsigned)f[Len][i][k]);
      }
    }
  }
  for (unsigned i(1); i <= n; ++i) if(f[n][1][i]) printf("%u ", i);
//  }
  return Wild_Donkey;
}

