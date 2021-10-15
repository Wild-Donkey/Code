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
const unsigned STsk(305);
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
bitset<STsk> f[STsk][STsk], Beat[STsk], Beaten[STsk];
char Ia[2005];
signed main() {
//  freopen("ex_C2.in", "r", stdin);
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
      for (unsigned j(i), len(1); len < Len; ++j, ++len) {
        for (unsigned k(i); k <= j; ++k) if((f[len][i][k]) && (!f[Len][i][k])) {
          f[Len][i][k] = (f[Len - len][j + 1] & Beat[k]).count() ? 1 : 0;
        }
      }
      for (unsigned j(i + Len - 1), len(1); len < Len; --j, ++len) {
        for (unsigned k(i + Len - 1); k >= j; --k) if((f[len][j][k]) && (!f[Len][i][k])) {
          f[Len][i][k] = (f[Len - len][i] & Beat[k]).count() ? 1 : 0;
        }
      }
//      printf("[%u %u]\n", i, i + Len - 1);
//      for (unsigned j(i); j <= i + Len - 1; ++j) printf("%u ", (unsigned)f[Len][i][j]);
//      putchar(0x0A);
    }
  }
  for (unsigned i(1); i <= n; ++i) if(f[n][1][i]) printf("%u ", i);
//  }
  return Wild_Donkey;
}

